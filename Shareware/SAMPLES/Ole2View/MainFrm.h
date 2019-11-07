// mainfrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#ifndef _MAINFRM_H_
#define _MAINFRM_H_

// OnUpdate( lHint ) flags                                      
#define UPD_ALL                0x00000000
#define UPD_NOOBJECTVIEW       0x00000001                                      
#define UPD_NOREGISTRYVIEW     0x00000002
#define UPD_REFRESH            0x00000004

void WINAPI ViewInterface( HWND hwnd, REFIID riid, IUnknown *punk );
                
class CObjTreeView ;
class CRegistryView ;

class CMyOleDropTarget : public COleDropTarget
{
public:
	CMyOleDropTarget();
	virtual ~CMyOleDropTarget();

    virtual DROPEFFECT OnDragEnter(CWnd* pWnd, COleDataObject* pDataObject,
		DWORD dwKeyState, CPoint point);
	virtual DROPEFFECT OnDragOver(CWnd* pWnd, COleDataObject* pDataObject,
		DWORD dwKeyState, CPoint point);
	virtual BOOL OnDrop(CWnd* pWnd, COleDataObject* pDataObject,
		DROPEFFECT dropEffect, CPoint point);
};



class CMainFrame : public CFrameWnd
{   
friend class COle2ViewApp ;
protected: // create from serialization only
    CMainFrame();
    DECLARE_DYNCREATE(CMainFrame)
    BOOL SavePosition() ;
    BOOL RestorePosition(int nCmdShow) ;

// Implementation
public:
	BOOL m_fCmdLineProcessed;
    virtual ~CMainFrame();
    virtual BOOL CMainFrame::LoadFrame(UINT nIDResource, DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE,
                CWnd* pParentWnd = NULL, CCreateContext* pContext = NULL);
    virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
#endif


public: 
    CSplitterWnd	m_wndSplitter ; 
    CStatusBar		m_wndStatusBar;
    CToolBar		m_wndToolBar;  
    
    CObjTreeView*	m_pObjTreeView ;
    CRegistryView*	m_pRegistryView ;
    CMyOleDropTarget  m_dropTarget;

#ifdef _MAC
    BOOL m_fInOnCreateClient;
#endif
// Generated message map functions
protected:
    //{{AFX_MSG(CMainFrame)
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnDestroy();
    afx_msg void OnFileRunREGEDIT();
    afx_msg void OnViewRefresh();
    afx_msg void OnUpdateViewRefresh(CCmdUI* pCmdUI);
	afx_msg void OnObjectDelete();
	afx_msg void OnUpdateObjectDelete(CCmdUI* pCmdUI);
	afx_msg void OnObjectVerify();
	afx_msg void OnUpdateObjectVerify(CCmdUI* pCmdUI);
	afx_msg void OnFileViewTypeLib();
    afx_msg void OnUseInProcServer();
    afx_msg void OnUpdateUseInProcServer(CCmdUI* pCmdUI);
    afx_msg void OnUseInProcHandler();
    afx_msg void OnUpdateUseInProcHandler(CCmdUI* pCmdUI);
    afx_msg void OnUseLocalServer();
    afx_msg void OnUpdateUseLocalServer(CCmdUI* pCmdUI);
    afx_msg void OnFileBind();
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnActivateApp(BOOL bActive, HTASK hTask);
	afx_msg void OnViewHiddenComCats();
	afx_msg void OnUpdateViewHiddenComCats(CCmdUI* pCmdUI);
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};


#endif // _MAINFRM_H_

