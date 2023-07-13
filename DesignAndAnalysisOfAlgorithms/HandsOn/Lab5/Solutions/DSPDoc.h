// DSPDoc.h : interface of the CDSPDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DSPDOC_H__2E9C040B_AC62_11DA_9B1C_B8289D003876__INCLUDED_)
#define AFX_DSPDOC_H__2E9C040B_AC62_11DA_9B1C_B8289D003876__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



struct node;
struct edge
{
 struct node* dnptr;
 int weight;
 struct edge* nextedge;
};

struct node
{
 struct edge *edgelist;
 CString nodeno;
 int sdist;
 boolean isperm;
 CPoint position;
 struct node *psnode;
 struct node *nextnode;
};


class CDSPDoc : public CDocument
{
protected: // create from serialization only
	CDSPDoc();
	
	DECLARE_DYNCREATE(CDSPDoc)

// Attributes
public:
   struct node* pLastCity;
  int totalnode;
  struct node *pgraph; 	

// Operations
public:
  void insertnode(struct node **ppnode,CString nodeno,CPoint point);
  void createedge(struct node **ppgraph,CPoint sno,CPoint dno,int w);
  int findshortpath(struct node *pgraph);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDSPDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	CString m_DDestination;
	CString m_SSource;
	virtual ~CDSPDoc();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDSPDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DSPDOC_H__2E9C040B_AC62_11DA_9B1C_B8289D003876__INCLUDED_)
