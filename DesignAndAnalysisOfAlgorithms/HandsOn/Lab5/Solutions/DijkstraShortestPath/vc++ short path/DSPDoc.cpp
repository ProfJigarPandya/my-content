// DSPDoc.cpp : implementation of the CDSPDoc class
//

#include "stdafx.h"
#include "DSP.h"

#include "DSPDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDSPDoc

IMPLEMENT_DYNCREATE(CDSPDoc, CDocument)

BEGIN_MESSAGE_MAP(CDSPDoc, CDocument)
	//{{AFX_MSG_MAP(CDSPDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDSPDoc construction/destruction

CDSPDoc::CDSPDoc()
{
	// TODO: add one-time construction code here
	totalnode = 0;
	pgraph = NULL;
	m_SSource = ' ';
	pLastCity=NULL;

}

CDSPDoc::~CDSPDoc()
{
}

BOOL CDSPDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDSPDoc serialization

void CDSPDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


void CDSPDoc::insertnode(struct node **ppgraph,CString nodeno,CPoint point)
{
 static struct node *first=NULL;
	if(*ppgraph == NULL)//first node
	{
	  (*ppgraph) = new node;
	  (*ppgraph)->edgelist = NULL;
	  (*ppgraph)->psnode = (*ppgraph);
	  (*ppgraph)->nodeno.Format("%s",nodeno);
	  (*ppgraph)->position = point;
	  (*ppgraph)->sdist = -1;
	  (*ppgraph)->isperm = false;
	  if(first == NULL)
		first = *ppgraph;

	  (*ppgraph)->nextnode = first; //circular
	  pLastCity = *ppgraph;
	}
	else if ((*ppgraph)->nextnode == first) //last node
	{
		 (*ppgraph)->nextnode = new node;
		 (*ppgraph)->nextnode->edgelist = NULL;
		 (*ppgraph)->nextnode->psnode = (*ppgraph)->nextnode;
		 (*ppgraph)->nextnode->nodeno = nodeno;
		 (*ppgraph)->nextnode->position = point;
		 (*ppgraph)->nextnode->sdist = -1;
		 (*ppgraph)->nextnode->isperm = false;
		 (*ppgraph)->nextnode->nextnode  = first;
		 pLastCity = (*ppgraph)->nextnode;
	}
	else
	{
		insertnode(&((*ppgraph)->nextnode),nodeno,point);
	}
}

void CDSPDoc::createedge(struct node **ppgraph,CPoint sno,CPoint dno,int w)
{
 if(*ppgraph == NULL)
 {
	AfxMessageBox("Empty graph "); return;
 }

 struct node *sptr=*ppgraph; // let sptr point to the node having no .. sno
 CRect rc;
 
 while(1) //  (sptr->position.x - 5)   sno && sptr!=NULL )
 {
	rc = CRect(sptr->position.x-10,sptr->position.y-10,sptr->position.x+10,sptr->position.y+10);
    if(rc.PtInRect(sno) || sptr==NULL)
		break;
   sptr = sptr->nextnode;
 }



 if(sptr==NULL)
 {
	AfxMessageBox("Invalide source node number");
	return;
 }

 struct node *dptr=*ppgraph; // let dptr point to the node having no.. dno
 while(1)
 {
	rc = CRect(dptr->position.x-10,dptr->position.y-10,dptr->position.x+10,dptr->position.y+10);
    if(rc.PtInRect(dno) || dptr==NULL)
		break;
    dptr = dptr->nextnode;
 }

 if(dptr==NULL)
 {
	AfxMessageBox("Invalide destination node number ");
	return;
 }

 //create and attach actual edge..
 struct edge *neptr;
 neptr = new edge;
 neptr->dnptr = dptr;
 neptr->weight = w;
 neptr->nextedge = NULL;

 if(sptr->edgelist == NULL)
 {
	sptr->edgelist = neptr;
	return;
 }

 struct edge *eptr = sptr->edgelist;
 while(eptr->nextedge!=NULL)	
	 eptr = eptr->nextedge;
 
 eptr->nextedge = neptr;

}





int CDSPDoc::findshortpath(struct node *dgraph)
{

 //creation of array of pointers of n-1 for C set
 struct node **C;
 C = new struct node* [totalnode-1];
 int j=0;
 struct node *temp = dgraph->nextnode;

 while(1)
 {
   C[j] = temp;
   C[j]->psnode = dgraph; //
   temp = temp->nextnode;
   j++;
   if(j==totalnode-1 )
	// j should be same as totalnode
	break;
 }

 //setting up initial distance
 struct edge *tedge;
 temp = dgraph;
 temp->sdist = 0;
 temp->isperm = true;
 temp->psnode = temp;
 
 tedge = temp->edgelist;
 if(tedge == NULL)
 {
	 AfxMessageBox("No outgoing road from city ");
	 return -1;
 }

 while(tedge!=NULL)
 {
	tedge->dnptr->sdist = tedge->weight;
	tedge = tedge->nextedge;
 }

 //greedy loop for finding shortest...
 int loop=0;
 while(1)
 {
    //v = some element of c minimizing d[v]
    struct node *v;
    int min = -2;
    int vi=-1;
    for(int x=0;x<totalnode-1;x++)
    {
		if(C[x] == NULL)
			continue;
		if(min == -2 && C[x]->sdist != -1)
		{
			min = C[x]->sdist;
			v = C[x];
			vi = x;
		}
		else
		{
			if(C[x]->sdist < min  && C[x]->sdist!=-1)
			{
				min  = C[x]->sdist;
				v = C[x];
				vi = x;
			}
		}

     }

    //c=c/v
	if(v==NULL)
	{
		
		AfxMessageBox("error in finding v");
		return -1;
	}
    
	v->isperm = true;
    C[vi]=NULL;



    //for loop
    for(int w=0;w<totalnode-1;w++) // tn-1
    {
      if(C[w] == NULL)
			continue;
      int nextw,lvw=-2;
      struct edge *tp;
      tp = v->edgelist;
	  if(tp == NULL)
	  {
		//  AfxMessageBox("edgelist null ");
		  continue;
	  }

       while(1)
	   { 
			if(tp->dnptr == C[w])
			{
				if(tp->dnptr->sdist != -1)
				{
					lvw = tp->weight;
					nextw = v->sdist+lvw;
				
					if( (C[w]->sdist) > nextw )
					{
						C[w]->sdist = nextw;
						C[w]->psnode = v;
					}

					break;
				}
				else // no previous way... ???????
				{
					lvw = tp->weight;
					nextw = v->sdist+lvw;
				
					C[w]->sdist = nextw;
					C[w]->psnode = v;
					break;
				}
			}
			tp = tp->nextedge;
			if(tp==NULL)
			break;
		}
      if(lvw == -2) // no edge between v w
		continue;

    } // end of while

    loop++;
    if(loop == totalnode-2)
	{
//		delete[] C;
		return 0;
	}
 }

}


/////////////////////////////////////////////////////////////////////////////
// CDSPDoc diagnostics

#ifdef _DEBUG
void CDSPDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDSPDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDSPDoc commands

