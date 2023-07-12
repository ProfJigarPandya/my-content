/*
 AIM:
          TO FIND MINIMUM SPANNING TREE FOR A GIVEN CONNECTED GRAPH
            USING KRUSKAL ALGORITHM.

   MINIMUM SPANNING TREE :FIND A SUBSET T OF THE EDGES OF G SUCH THAT ALL THE NODES REMAIN CONNECTED 
     WHEN ONLY THE EDGES IN T ARE USED AND THE SUM OF THE LENGTHS OF THE EDGES IN T IS AS SMALL
     AS POSSIBLE.

  REFERENCE:
            PG.190 TO 195   
	    FUNDAMENTALS OF ALGORITHMS
                BY FILLES BRASSARD & PAUL BRATLEY.
        PHI FIFTH INDIAN REPRINT.

  PROGRAM BY:
	JIGAR M PANDYA (MT_07)       ME SEM II         31/1/2006
 
*/


#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip.h>

struct node;
struct edge
{
 struct node *lnptr;
 int weight;
 struct edge *nextoedge; // next ordered weight edge address...
 struct node *rnptr;
};
struct node
{
 char nodename[10];
 struct node *nextnode;
};
struct graph
{
 struct node *pnodelist;
 struct edge *pedgelist;
};

void insertnode(struct node **ppnode,char *nname);
void traverseedgelist(struct edge *pedgelist);
void createedge(struct graph *pgraph,char *sn,char *dn,int w);
void displaygraph(struct graph g);
int ftotalnodes(struct graph g);
struct edge * kruskalalgo(struct graph g);

void main()
{
 struct graph g;
 g.pnodelist = NULL;
 g.pedgelist = NULL;

 char choice;
 int zz=0;
 clrscr();
 //create all nodes linked list.... have edge fields empty...
 while(1)
 {
  cout<<"\n Add more node? -- press 'y' or 'Y' for yes";
  cin>>choice;

  if(choice == 'y' || choice =='Y')
  {
	char nname[10]; zz=1;
	cout<<"\n Enter number of node ";
	cin>>nname;
	insertnode(&(g.pnodelist),nname);
  }
  else
     break;
 }

 //create all edges connecting nodes ........
 while(1)
 {
	if(zz==0)
	{
	cout<<"\n No node .. sorry it's not graph"; return;
	}
	cout<<"\n Add more edge?  -- press 'y' or 'Y' for yes";
	cin>>choice;
	char snode[10],dnode[10];int w;
	if(choice == 'y' || choice == 'Y') //add edge at proper place
	{
	  cout<<"\n Enter source and destination node number and weight";zz=1;
	  cin>>snode>>dnode>>w;
	  createedge(&g,snode,dnode,w);//w is weight
	}
	else
	  break;
 }
 if(zz==0)
 {
	cout<<"\n No node and No edge .... sorry it's not graph"; return;
 }

 cout<<"\n Following graph have been entered by user ";
 displaygraph(g);

 struct edge *mstree;
 mstree = kruskalalgo(g);
 cout<<"\n following are the edges selected for minimum spanning tree";
 traverseedgelist(mstree);

 getch();
}

void insertnode(struct node **ppnode,char *nname)
{
	if(*ppnode == NULL)//first node
	{
	  *ppnode = new node;
	  strcpy( ((*ppnode)->nodename),nname);
	  (*ppnode)->nextnode = NULL;
	}
	else
	{
		insertnode(&((*ppnode)->nextnode),nname);
	}
}

void createedge(struct graph *pgraph,char *sn,char *dn,int w)
{
 if( pgraph->pnodelist == NULL)
 {
	cout<<"\n Empty graph "; return;
 }
 struct node *sptr=pgraph->pnodelist; // let sptr point to the node having no .. sno
 while( (strcmp(sptr->nodename,sn) != 0 ) && sptr!=NULL )
 {
   sptr = sptr->nextnode;
 }
 if(sptr==NULL)
 {
	cout<<"\n Invalide source node number ";
	return;
 }
 struct node *dptr=pgraph->pnodelist; // let dptr point to the node having no.. dno
 while( (strcmp(dptr->nodename,dn)!=0) && dptr!=NULL)
 {
   dptr = dptr->nextnode;
 }
 if(dptr==NULL)
 {
	cout<<"\n Invalide destination node number ";
	return;
 }
 //create and attach actual edge..
 struct edge *neptr;
 neptr = new edge;
 neptr->lnptr = sptr;
 neptr->rnptr = dptr;
 neptr->weight = w;
 neptr->nextoedge = NULL;  //temporary... it might be as per ordered later.

 struct edge *ptr;
 ptr = pgraph->pedgelist;
 if(ptr == NULL) //first entry of edge of graph
 {
  pgraph->pedgelist = neptr;
  return;
 }
 // insert new edge into order
 if(w < pgraph->pedgelist->weight ) //leftmost
 {
   neptr->nextoedge = pgraph->pedgelist;
   pgraph->pedgelist = neptr;
   return;
 }
 while( ptr->nextoedge->weight  < w  && ptr->nextoedge!=NULL)
 {
	ptr = ptr->nextoedge;
 }
 neptr->nextoedge = ptr->nextoedge;
 ptr->nextoedge = neptr;

}
void traverseedgelist(struct edge *pedgelist)
{
	cout<<"\n EdgeWeight    LeftNode    RightNode  ";
	while(pedgelist!=NULL)
	{
	  cout<<"\n";
	  cout<<setw(13)<<pedgelist->weight
	      <<setw(13)<<pedgelist->lnptr->nodename
	      <<setw(13)<<pedgelist->rnptr->nodename;
	  pedgelist = pedgelist->nextoedge;
	}
}

void displaygraph(struct graph g)
{
 struct node *tnode=g.pnodelist;
 while(tnode!=NULL)
 {
  cout<<"\n Node Name. "<<tnode->nodename;
  tnode = tnode->nextnode;
 }
 traverseedgelist(g.pedgelist);
}

int ftotalnodes(struct graph g)
{
 int count=0;
 struct node *temp;
 temp = g.pnodelist;
 while(temp!=NULL)
 {
	count++;
	temp=temp->nextnode;
 }
 return count;
}
struct edge* kruskalalgo(struct graph g)
{
  //edges have already been sorted in order when creation of graph
  int n=ftotalnodes(g);
  struct node *temp=g.pnodelist;
  struct node **ptrarray;
  ptrarray = new node* [n]; // make individual component of all nodes

  for(int i=0;i<n;i++)
  {
	ptrarray[i] = new node;
	strcpy(ptrarray[i]->nodename,temp->nodename);
	ptrarray[i]->nextnode = NULL;
	temp = temp->nextnode;
  }

  int tconsedges=0;
  int ucomp,vcomp;
  struct edge *mstree=NULL;
  struct edge *pe;
  int ncedges;

  pe = g.pedgelist;

  while(1)
  {
	// pe points to edge <u,v>
//	ucomp = find(pe->lnptr);
//	vcomp = find(pe->rnptr);
//      equivalent for loop for above two statement ...
	int flag=0;// flag = 1 if ucomp found .., 2 if vcomp is found .., 3 if both
	for(int j=0;j<n;j++)
	{
	   temp = ptrarray[j];
	   while(temp!=NULL)
	   {
	      if(strcmp(temp->nodename,pe->lnptr->nodename)==0)
	      {
		ucomp = j;
		if(flag == 2) { flag = 3; break; }//both found
		else	flag = 1; // ucomp found
	      }
	      if(strcmp(temp->nodename,pe->rnptr->nodename)==0)
	      {
		vcomp = j;
		if(flag==1) { flag = 3; break;} // both found
		else	flag = 2;// vcomp found
	      }
	      temp=temp->nextnode;
	   }
	   if(flag == 3)
		break;
	}

	if(ucomp != vcomp) // fullfills that no cycle is going to be formed
	{
		//merge(ucomp,vcomp);
		struct node *pu = ptrarray[ucomp];
		ptrarray[ucomp] = NULL;
		struct node *pv;
		pv = ptrarray[vcomp];
		while(pv->nextnode != NULL)
			pv = pv->nextnode;
		pv->nextnode = pu;

	       //attachedge(&(mstree),pe);
	       if(mstree == NULL)
	       {
		mstree = new edge;
		mstree->lnptr = pe->lnptr;
		mstree->weight = pe->weight;
		mstree->rnptr = pe->rnptr;
		mstree->nextoedge = NULL;
	       }
	       else
	       {
		       struct edge *tpe;
		       tpe = mstree;
		       while(tpe->nextoedge!=NULL) tpe = tpe->nextoedge;
		       tpe->nextoedge = new edge;
		       tpe->nextoedge->lnptr = pe->lnptr;
		       tpe->nextoedge->weight = pe->weight;
		       tpe->nextoedge->rnptr = pe->rnptr;
		       tpe->nextoedge->nextoedge = NULL;
	       }
	       tconsedges++;
	}

	if( tconsedges == n-1)
	  break;
	pe = pe->nextoedge;
		if(pe==NULL)  //want ever get in..
	{
		cout<<"\n error in graph....not a connected graph ";
		return mstree;
	}
  }
  return mstree;

}
