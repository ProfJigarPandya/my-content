#if !defined(AFX_NAMEOFCITYDLG_H__275FF421_AC72_11DA_9B1C_902F67B41575__INCLUDED_)
#define AFX_NAMEOFCITYDLG_H__275FF421_AC72_11DA_9B1C_902F67B41575__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NameOfCityDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNameOfCityDlg dialog

class CNameOfCityDlg : public CDialog
{
// Construction
public:
	CNameOfCityDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNameOfCityDlg)
	enum { IDD = IDD_NAMEOFCITY };
	CString	m_NameOfCity;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNameOfCityDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNameOfCityDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NAMEOFCITYDLG_H__275FF421_AC72_11DA_9B1C_902F67B41575__INCLUDED_)
