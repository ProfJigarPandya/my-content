// DSPView.h : interface of the CDSPView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DSPVIEW_H__2E9C040D_AC62_11DA_9B1C_B8289D003876__INCLUDED_)
#define AFX_DSPVIEW_H__2E9C040D_AC62_11DA_9B1C_B8289D003876__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDSPView : public CScrollView
{
protected: // create from serialization only
	CDSPView();
	DECLARE_DYNCREATE(CDSPView)

// Attributes
public:
	CPoint ss,sd;
	CDSPDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDSPView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetSourceCity(CString str);
	
	int iscity;
	virtual ~CDSPView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDSPView)
	afx_msg void OnAddCity();
	afx_msg void OnUpdateAddCity(CCmdUI* pCmdUI);
	afx_msg void OnAddRoad();
	afx_msg void OnUpdateAddRoad(CCmdUI* pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DSPView.cpp
inline CDSPDoc* CDSPView::GetDocument()
   { return (CDSPDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DSPVIEW_H__2E9C040D_AC62_11DA_9B1C_B8289D003876__INCLUDED_)
