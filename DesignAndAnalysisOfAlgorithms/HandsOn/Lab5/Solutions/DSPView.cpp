// DSPView.cpp : implementation of the CDSPView class
//

#include "stdafx.h"
#include "DSP.h"

#include "DSPDoc.h"
#include "DSPView.h"
#include "NameOfCityDlg.h"
#include "RoadInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDSPView

IMPLEMENT_DYNCREATE(CDSPView, CScrollView)

BEGIN_MESSAGE_MAP(CDSPView, CScrollView)
	//{{AFX_MSG_MAP(CDSPView)
	ON_COMMAND(ID_ADD_CITY, OnAddCity)
	ON_UPDATE_COMMAND_UI(ID_ADD_CITY, OnUpdateAddCity)
	ON_COMMAND(ID_ADD_ROAD, OnAddRoad)
	ON_UPDATE_COMMAND_UI(ID_ADD_ROAD, OnUpdateAddRoad)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_KEYDOWN()
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDSPView construction/destruction

CDSPView::CDSPView()
{
	// TODO: add construction code here
	iscity=-1;
}

CDSPView::~CDSPView()
{
}

BOOL CDSPView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDSPView drawing

void CDSPView::OnDraw(CDC* pDC)
{
	CDSPDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
	CRect rect;
	GetClientRect(&rect);
	pDC->DrawText("Activate the area and then use ADD menu to add city or to add road\n Press ESC to cancel the current action \n Orange end of edge indicate Destination end \n Dont give duplicate name of cities\n Don't click outside circle when selecting source n destination",&rect,DT_CENTER);

	
	
	//draw graph... 
	struct node *temp=pDoc->pgraph;
	struct node *ssn=NULL,*ddn=NULL;
	struct edge *te;
	CBrush sbr,p,dbr;
	sbr.CreateSolidBrush(RGB(255,0,0));
	dbr.CreateSolidBrush(RGB(0,0,255));
	p.CreateSolidBrush(RGB(128,128,128));
	pDC->SelectObject(&p);
	CPoint s,d;
	
	if(temp!=NULL)
	{
		while(1)
		{
			CPoint point=temp->position;
			if(temp->nodeno == pDoc->m_SSource)
			{
				 pDC->SelectObject(&sbr);	

			}
			else if(temp->nodeno == pDoc->m_DDestination)
			{
				pDC->SelectObject(&dbr);
			}
			else
			{
				pDC->SelectObject(&p);
			}

			pDC->Ellipse(CRect(point.x-10,point.y-10,point.x+10,point.y+10));
			
			pDC->TextOut(point.x-30,point.y+12,temp->nodeno);
			pDC->TextOut(point.x+30,point.y-12,temp->psnode->nodeno);
			
			te = temp->edgelist;
			s = temp->position;
			
			CPen pen,*pOldPen;
			pen.CreatePen( PS_DASHDOT   ,5,RGB(255,128,128));

			while(te!=NULL)
			{
				d = te->dnptr->position;
				pDC->MoveTo(s);
				pDC->LineTo(d);
				pOldPen = pDC->SelectObject(&pen);
				pDC->MoveTo(d);
				pDC->LineTo(CPoint(d.x - (d.x - s.x) / 5 , d.y - (d.y - s.y)/5));
				pDC->SelectObject(pOldPen);
				int x,y;
				x = (s.x > d.x) ? ( (d.x + (s.x - d.x)/2) + 10  ):((s.x + (d.x-s.x)/2) - 10);
				y = (s.y > d.y) ? ( (d.y + (s.y - d.y)/2) + 10):( (s.y+ (d.y-s.y)/2) - 10);
				CString sdist;
				sdist.Format("%d",te->weight);
							
				pDC->TextOut(x,y,sdist);
				te = te->nextedge;
			}

			temp = temp->nextnode;
			if(temp == pDoc->pgraph)
				break;
		}
	
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDSPView printing

BOOL CDSPView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDSPView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDSPView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDSPView diagnostics

#ifdef _DEBUG
void CDSPView::AssertValid() const
{
	CView::AssertValid();
}

void CDSPView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDSPDoc* CDSPView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDSPDoc)));
	return (CDSPDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDSPView message handlers

void CDSPView::OnAddCity() 
{

	CRect rect;
	GetClientRect(&rect);
	ClientToScreen(&rect);
	::ClipCursor(&rect);
	iscity = 1;	


}

void CDSPView::OnUpdateAddCity(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CDSPView::OnAddRoad() 
{
	// TODO: Add your command handler code here
	iscity = 2;

	CRect rect;
	GetClientRect(&rect);
	ClientToScreen(&rect);
	::ClipCursor(&rect);

}

void CDSPView::OnUpdateAddRoad(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CDSPView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CDSPDoc *pDoc = GetDocument();
	
	
	
	::ClipCursor(NULL);
	CNameOfCityDlg dlg1;
	CRoadInfoDlg dlg2;

	CClientDC dc(this);
	OnPrepareDC (&dc);
	dc.DPtoLP(&point);
	
	
	if(iscity==1)//add a city
	{
		if( dlg1.DoModal() == IDOK)
		{	
			dlg1.m_NameOfCity.MakeUpper();
			pDoc->insertnode(&(pDoc->pgraph),dlg1.m_NameOfCity,point);
			pDoc->totalnode = pDoc->totalnode + 1;
			pDoc->UpdateAllViews(NULL);
		}

		iscity = -1;
	}
	else if(iscity == 2) // add a edge
	{

		ss = point;
		iscity = 3; //sd

	}
	else if(iscity == 3) //sd
	{
		sd = point;
		

		if( dlg2.DoModal() == IDOK)
		{	
			pDoc->createedge(&(pDoc->pgraph),ss,sd,dlg2.m_Distance);
			pDoc->UpdateAllViews(NULL);
		}

		iscity = -1;
	}
	else
	{

	}

	
	//CView::OnLButtonDown(nFlags, point);
}

void CDSPView::OnMouseMove(UINT nFlags, CPoint point) 
{

	if(iscity==1)
		::SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR_CITY));
	else if(iscity==2)
		::SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR_SS));
	else if(iscity==3)
		::SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR_SD));
	else
		::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	CView::OnMouseMove(nFlags, point);
}

void CDSPView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{

	
	switch(nChar)
	{
	case VK_HOME:
		OnHScroll(SB_LEFT,0,NULL);
		break;
	case VK_END:
		OnHScroll(SB_RIGHT,0,NULL);
		break;
	case VK_UP:
		OnVScroll(SB_LINEUP,0,NULL);
		break;
	case VK_DOWN:
		OnVScroll(SB_LINEDOWN,0,NULL);
		break;
	case VK_LEFT:
		OnHScroll(SB_LINELEFT,0,NULL);
		break;
	case VK_RIGHT:
		OnHScroll(SB_LINERIGHT,0,NULL);
		break;
	case VK_PRIOR:
		OnVScroll(SB_PAGEUP,0,NULL);
		break;
	case VK_NEXT:
		OnVScroll(SB_PAGEDOWN,0,NULL);
		break;

	default:

		iscity = -1;
		::ClipCursor(NULL);
	
	}


	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CDSPView::SetSourceCity(CString str)
{

}

void CDSPView::OnInitialUpdate() 
{

	CSize sizeTotal(800,800);

	SetScrollSizes(MM_TEXT,sizeTotal);

}

void CDSPView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	
	CScrollView::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CDSPView::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	
	CScrollView::OnHScroll(nSBCode, nPos, pScrollBar);
}
