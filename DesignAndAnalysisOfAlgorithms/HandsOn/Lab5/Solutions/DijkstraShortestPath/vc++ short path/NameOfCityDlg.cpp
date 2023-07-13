// NameOfCityDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DSP.h"
#include "NameOfCityDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNameOfCityDlg dialog


CNameOfCityDlg::CNameOfCityDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNameOfCityDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNameOfCityDlg)
	m_NameOfCity = _T("");
	//}}AFX_DATA_INIT
}


void CNameOfCityDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNameOfCityDlg)
	DDX_Text(pDX, IDC_NAMEOFCITY, m_NameOfCity);
	DDV_MaxChars(pDX, m_NameOfCity, 10);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNameOfCityDlg, CDialog)
	//{{AFX_MSG_MAP(CNameOfCityDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNameOfCityDlg message handlers
