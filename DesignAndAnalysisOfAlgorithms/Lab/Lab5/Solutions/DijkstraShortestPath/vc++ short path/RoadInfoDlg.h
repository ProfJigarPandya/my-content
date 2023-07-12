#if !defined(AFX_ROADINFODLG_H__417D11A1_AC8E_11DA_9B1C_9BBC17757B77__INCLUDED_)
#define AFX_ROADINFODLG_H__417D11A1_AC8E_11DA_9B1C_9BBC17757B77__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RoadInfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRoadInfoDlg dialog

class CRoadInfoDlg : public CDialog
{
// Construction
public:
	CRoadInfoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRoadInfoDlg)
	enum { IDD = IDD_DISTBETCITY };
	int		m_Distance;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRoadInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRoadInfoDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROADINFODLG_H__417D11A1_AC8E_11DA_9B1C_9BBC17757B77__INCLUDED_)
