// RoadInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DSP.h"
#include "RoadInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRoadInfoDlg dialog


CRoadInfoDlg::CRoadInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRoadInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRoadInfoDlg)
	m_Distance = 0;
	//}}AFX_DATA_INIT
}


void CRoadInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRoadInfoDlg)
	DDX_Text(pDX, IDC_DISTANCE, m_Distance);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRoadInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CRoadInfoDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRoadInfoDlg message handlers
