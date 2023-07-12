// SelectSDView.cpp : implementation file
//

#include "stdafx.h"
#include "DSP.h"
#include "DSPDoc.h"
#include "SelectSDView.h"
#include "DSPView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSelectSDView

IMPLEMENT_DYNCREATE(CSelectSDView, CFormView)

CSelectSDView::CSelectSDView()
	: CFormView(CSelectSDView::IDD)
{
	//{{AFX_DATA_INIT(CSelectSDView)
	m_SSSource = _T("");
	m_DDDestination = _T("");
	//}}AFX_DATA_INIT
}

CSelectSDView::~CSelectSDView()
{
}

void CSelectSDView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSelectSDView)
	DDX_CBString(pDX, IDC_SOURCE_CITY_DB, m_SSSource);
	DDX_CBString(pDX, IDC_DEST_CITY_CB, m_DDDestination);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSelectSDView, CFormView)
	//{{AFX_MSG_MAP(CSelectSDView)
	ON_CBN_SELENDOK(IDC_SOURCE_CITY_DB, OnSelendokSourceCityDb)
	ON_CBN_SELCHANGE(IDC_SOURCE_CITY_DB, OnSelchangeSourceCityDb)
	ON_CBN_DBLCLK(IDC_SOURCE_CITY_DB, OnDblclkSourceCityDb)
	ON_CBN_SETFOCUS(IDC_SOURCE_CITY_DB, OnSetfocusSourceCityDb)
	ON_CBN_SELCHANGE(IDC_DEST_CITY_CB, OnSelchangeDestCityCb)
	ON_CBN_EDITCHANGE(IDC_DEST_CITY_CB, OnEditchangeDestCityCb)
	ON_BN_CLICKED(IDC_SEARCH, OnSearch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSelectSDView diagnostics

#ifdef _DEBUG
void CSelectSDView::AssertValid() const
{
	CFormView::AssertValid();
}

void CSelectSDView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSelectSDView message handlers

void CSelectSDView::OnSelendokSourceCityDb() 
{

	
}

void CSelectSDView::OnSelchangeSourceCityDb() 
{
	CDSPDoc *pDoc = (CDSPDoc *)GetDocument();
	CButton *bt;
	UpdateData(true);
	pDoc->m_SSource = m_SSSource;
	POSITION pos = pDoc->GetFirstViewPosition();
	pDoc->GetNextView(pos);
	CDSPView *pView = (CDSPView *) pDoc->GetNextView(pos);

	bt = (CButton *)GetDlgItem(IDC_SEARCH);
	isssel = 1;
	if(isdsel==1)
	{
		bt->EnableWindow(true);
		CStatic *pst = (CStatic *) GetDlgItem(IDC_SEARCH_TEXT);
		CString dd;
		dd.Format("Press \nSEARCH \n To find DSP");
		pst->SetWindowText(dd);
	}

	pView->Invalidate();
	
}

void CSelectSDView::OnDblclkSourceCityDb() 
{

}

void CSelectSDView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class

	CDSPDoc *pDoc = (CDSPDoc *)GetDocument();
	static struct node *plc = pDoc->pLastCity;
	CComboBox *pBox1  = (CComboBox *)GetDlgItem(IDC_SOURCE_CITY_DB);
	CComboBox *pBox2  = (CComboBox *)GetDlgItem(IDC_DEST_CITY_CB);

	if(pDoc->pLastCity !=NULL && pDoc->pLastCity!=plc)
	{
		pBox1->AddString(pDoc->pLastCity->nodeno);
		pBox2->AddString(pDoc->pLastCity->nodeno);
		plc = pDoc->pLastCity;
	}

	
}	

void CSelectSDView::OnSetfocusSourceCityDb() 
{


}

void CSelectSDView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	CButton *bt;
	isssel = 0;
	isdsel = 0;
	bt = (CButton *)GetDlgItem(IDC_SEARCH);
	bt->EnableWindow(false);
}

void CSelectSDView::OnSelchangeDestCityCb() 
{
	// TODO: Add your control notification handler code here
	CDSPDoc *pDoc = (CDSPDoc *)GetDocument();

	UpdateData(true);
	CString dd;
	pDoc->m_DDestination = m_DDDestination;

	POSITION pos = pDoc->GetFirstViewPosition();
	pDoc->GetNextView(pos);
	CDSPView *pView = (CDSPView *) pDoc->GetNextView(pos);
	CButton *bt = (CButton *)GetDlgItem(IDC_SEARCH);
	isdsel = 1;
	if(isssel==1)
	{
		bt->EnableWindow(true);
		CStatic *pst = (CStatic *) GetDlgItem(IDC_SEARCH_TEXT);
		dd.Format("Press \nSEARCH \n To find DSP");
		pst->SetWindowText(dd);
	}

	pView->Invalidate();
	
}

void CSelectSDView::OnEditchangeDestCityCb() 
{

	
}

void CSelectSDView::OnSearch() 
{
	 CDSPDoc *pDoc = (CDSPDoc *)GetDocument();
	 
     struct node *temp;
	 temp = pDoc->pgraph;

	 if(temp!=NULL)
	 {

		//make all to -1 if had some other value due to prev call
		 while(1)
		 {
			temp->sdist = -1;
			temp->psnode = pDoc->pgraph;
			temp=temp->nextnode;
			if(temp == pDoc->pgraph)
				break;
		 }

		temp = pDoc->pgraph;
		
		while(temp->nodeno != m_SSSource)
		{
			temp = temp->nextnode;
		}
		

		
		int res = pDoc->findshortpath(temp);
		

		temp = pDoc->pgraph;
		while(temp->nodeno != m_DDDestination)
		{
			temp = temp->nextnode;
		}

		CString dd;
		CStatic *pst = (CStatic *) GetDlgItem(IDC_SEARCH_TEXT);
		if(res!=-1)
		{
			dd.Format("Shortest Distance %d",temp->sdist);
			pst->SetWindowText(dd);
		}
		else
		{
		
			pst->SetWindowText("error ");
		}
		
		pDoc->UpdateAllViews(this);

	 }
}
