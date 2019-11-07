// DBLocal.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "DBLocal.h"

#include "mainfrm.h"
#include "DBLocdoc.h"
#include "DBLocvw.h"

#include "..\object\dbsrvimp.h"
class CDBSrvFactory;

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDBLocalApp

BEGIN_MESSAGE_MAP(CDBLocalApp, CWinApp)
	//{{AFX_MSG_MAP(CDBLocalApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDBLocalApp construction

CDBLocalApp::CDBLocalApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	m_dwDBFactory=0;
	m_pLastDoc=NULL;
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CDBLocalApp object

CDBLocalApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CDBLocalApp initialization

BOOL CDBLocalApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

	if (m_lpCmdLine[0] != '\0')
	{
		if (lstrcmpi(m_lpCmdLine, "/REGSERVER")==0) {
			if (FAILED(DllRegisterServer())) {
				AfxMessageBox("Unable to register the server!");
				}
			return FALSE;
			}
		else if (lstrcmpi(m_lpCmdLine, "/UNREGSERVER")==0) {
			if (FAILED(DllUnregisterServer())) {
				AfxMessageBox("Unable to unregister the server!");
				}
			return FALSE;
			}
	}

	DllRegisterServer();

	CoInitialize(NULL);
	CDBSrvFactory *pFactory=new CDBSrvFactory();
	pFactory->AddRef();

	if (FAILED(CoRegisterClassObject(CLSID_DBSAMPLE, (IUnknown*) pFactory, 
				CLSCTX_INPROC_SERVER | CLSCTX_LOCAL_SERVER, REGCLS_MULTIPLEUSE, &m_dwDBFactory))) {
		pFactory->Release();
		return FALSE;
		}
	pFactory->Release(); // COM keeps a reference to the class factory

	Enable3dControls();

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(
		IDR_DBLOCATYPE,
		RUNTIME_CLASS(CDBLocalDoc),
		RUNTIME_CLASS(CMDIChildWnd),          // standard MDI child frame
		RUNTIME_CLASS(CDBLocalView));
	AddDocTemplate(pDocTemplate);

	// create main MDI Frame window
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;

	// create a new (empty) document
	//OnFileNew();

	if (m_lpCmdLine[0] != '\0')
	{
		// TODO: add command line processing here
	}

	// The main window has been initialized, so show and update it.
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CDBLocalApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CDBLocalApp commands

int CDBLocalApp::ExitInstance() 
{
	if (m_dwDBFactory) {
		CoRevokeClassObject(m_dwDBFactory);
		m_dwDBFactory=0;
		}	
	return CWinApp::ExitInstance();
}
