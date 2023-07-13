#if !defined(AFX_SELECTSDVIEW_H__0EBD9C81_AC66_11DA_9B1C_B8289D003876__INCLUDED_)
#define AFX_SELECTSDVIEW_H__0EBD9C81_AC66_11DA_9B1C_B8289D003876__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SelectSDView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSelectSDView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CSelectSDView : public CFormView
{
protected:
	CSelectSDView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CSelectSDView)

// Form Data
public:
	//{{AFX_DATA(CSelectSDView)
	enum { IDD = IDD_SELECT_SD_DLG };
	CString	m_SSSource;
	CString	m_DDDestination;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:
	int isdsel;
	int isssel;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSelectSDView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CSelectSDView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CSelectSDView)
	afx_msg void OnSelendokSourceCityDb();
	afx_msg void OnSelchangeSourceCityDb();
	afx_msg void OnDblclkSourceCityDb();
	afx_msg void OnSetfocusSourceCityDb();
	afx_msg void OnSelchangeDestCityCb();
	afx_msg void OnEditchangeDestCityCb();
	afx_msg void OnSearch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELECTSDVIEW_H__0EBD9C81_AC66_11DA_9B1C_B8289D003876__INCLUDED_)
