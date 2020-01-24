// DBLocvw.h : interface of the CDBLocalView class
//
/////////////////////////////////////////////////////////////////////////////

class CDBLocalView : public CView
{
protected: // create from serialization only
	CDBLocalView();
	DECLARE_DYNCREATE(CDBLocalView)

// Attributes
public:
	CDBLocalDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDBLocalView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDBLocalView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDBLocalView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DBLocvw.cpp
inline CDBLocalDoc* CDBLocalView::GetDocument()
   { return (CDBLocalDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
