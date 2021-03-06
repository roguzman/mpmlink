
// CiscoOpenAppDlg.cpp: archivo de implementación
//

#include "stdafx.h"
#include <Winsock.h>
#include <lm.h>
#include "CiscoOpenApp.h"
#include "CiscoOpenAppDlg.h"
#include "afxdialogex.h"
#include "RpcUtils.h"
#include "BenchmarkRpcCalls.h"
#include "PluginInfo.h"
#include "PICliConnectIF.h"
#include "PISerConnectIF.h"
#include "PICliMessageIF.h"
#include "PICliAlarmIF.h"
#include "PICliBoardIF.h"
#include "PICliStateIF.h"
#include "IniReader.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

PCONTEXT_HDL_TYPE       pContextHandler;
CEdit                   m_CEditMessage;
CEdit                   m_CEditLine;
CEdit                   m_CEditSide;
CEdit                   m_CEditLogPath;
bool					bAutoStart;

// Cuadro de diálogo de CCiscoOpenAppDlg

CCiscoOpenAppDlg::CCiscoOpenAppDlg(CWnd* pParent /*= nullptr*/)
	: CDialogEx(IDD_CISCOOPENAPP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCiscoOpenAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_CEditMessage);
	DDX_Control(pDX, IDC_EDIT2, m_CEditNameAndPort);
	DDX_Control(pDX, IDC_EDIT3, m_CEditStatus);
	DDX_Control(pDX, IDC_EDIT4, m_CEditLine);
	DDX_Control(pDX, IDC_EDIT5, m_CEditSide);
	DDX_Control(pDX, IDC_EDIT6, m_CEditLogPath);
	DDX_Control(pDX, IDC_CONNECT, m_CButtonConnect);
	DDX_Control(pDX, IDC_DISCONNECT, m_CButtonDisconnect);
}

BEGIN_MESSAGE_MAP(CCiscoOpenAppDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNECT, &CCiscoOpenAppDlg::OnBnClickedConnect)
	ON_BN_CLICKED(IDC_DISCONNECT, &CCiscoOpenAppDlg::OnBnClickedDisconnect)
END_MESSAGE_MAP()


// Controladores de mensajes de CCiscoOpenAppDlg

BOOL CCiscoOpenAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Establecer el icono para este cuadro de diálogo.  El marco de trabajo realiza esta operación
	//  automáticamente cuando la ventana principal de la aplicación no es un cuadro de diálogo
	SetIcon(m_hIcon, TRUE);			// Establecer icono grande
	SetIcon(m_hIcon, FALSE);		// Establecer icono pequeño

	// TODO: agregar aquí inicialización adicional
	// initialize the pluing's server
	InitRpc();

	LPCWSTR     szResult = new TCHAR[80];
	CString     text;
	CIniReader  iniReader(L".\\config.ini");

	// Get hostname
	// gethostname(szPath, sizeof(szPath));
	// text.Format(_T("%S:4000"), szPath);

	m_CEditNameAndPort.SetWindowTextW(iniReader.ReadString(L"benchmark", L"hostname", L""));
	m_CEditLine.SetWindowTextW(iniReader.ReadString(L"benchmark", L"line", L""));
	m_CEditSide.SetWindowTextW(iniReader.ReadString(L"benchmark", L"side", L""));
	m_CEditLogPath.SetWindowTextW(iniReader.ReadString(L"benchmark", L"logpath", L""));
	szResult = iniReader.ReadString(L"benchmark", L"autostart", L"");
	bAutoStart = (wcscmp(szResult, L"True") == 0 || wcscmp(szResult, L"true") == 0) ? true : false;
	m_CEditNameAndPort.SetSel(0, -1);
	m_CEditNameAndPort.SetFocus();

	// Update buttons
	m_CButtonConnect.EnableWindow(TRUE);
	m_CButtonDisconnect.EnableWindow(FALSE);

	if (bAutoStart)
	{
		CCiscoOpenAppDlg::OnBnClickedConnect();
	}

	return FALSE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

// Si agrega un botón Minimizar al cuadro de diálogo, necesitará el siguiente código
//  para dibujar el icono.  Para aplicaciones MFC que utilicen el modelo de documentos y vistas,
//  esta operación la realiza automáticamente el marco de trabajo.

void CCiscoOpenAppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Contexto de dispositivo para dibujo

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrar icono en el rectángulo de cliente
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dibujar el icono
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// El sistema llama a esta función para obtener el cursor que se muestra mientras el usuario arrastra
//  la ventana minimizada.
HCURSOR CCiscoOpenAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method: CheckRpcResult
//
//  Description: A helper method to check the return of the _SEH methods
//  and deal with errors if they occur.  
//
///////////////////////////////////////////////////////////////////////////////
BOOL CCiscoOpenAppDlg::CheckRpcResult(unsigned long ulResult, EPICallStatus eCallStatus)
{
	BOOL        bReturnVal = FALSE;
	CString     csPrompt;

	if (RPC_S_OK == ulResult)
	{
		switch (eCallStatus)
		{
		case ePICallStatAOK:
			bReturnVal = TRUE;
			break;
		case ePICallStatNotAuthorized:
		case ePICallStatNotLicensed:
		case ePICallStatAlreadyConnected:
		case ePICallStatInternalError:
		case ePICallStatIncorrectState:
		case ePICallStatInvalidContext:
		case ePICallStatInvalidParameter:
		case ePICallStatIncorrectHardware:
		case ePICallStatProcessProgramNotFound:
		default:
			csPrompt.Format(_T("The Machine will not accept a connection: %d"), eCallStatus);
			AfxMessageBox(csPrompt);
			break;
		}
	}
	else
	{
		csPrompt.Format(_T("An RPC exception occurred while connecting to the Machine: %d - %s"), ulResult, GetSystemError(ulResult));
		AfxMessageBox(csPrompt);
	}

	return bReturnVal;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method: InitRpc
//
//  Description: Initializes this plugin's server side.  Any app that wants to
//  connect to Benchmark must at the very least, implement the functions in 
//  PICliConnectIF.idl.  Benchmark uses these functions to query plugins about
//  their verisions and notification requests.
//
///////////////////////////////////////////////////////////////////////////////
void CCiscoOpenAppDlg::InitRpc(void)
{
	RPC_IF_HANDLE   hRpc[] = { PICliConnectInterface_v1_0_s_ifspec,
							   PICliMessageInterface_v1_0_s_ifspec,
							   PICliBoardInterface_v1_0_s_ifspec,
							   PICliStateInterface_v1_0_s_ifspec };

	CString         csPort;
	CString         csError;
	CWinThread*     pCWinThread = NULL;

	// NOTE: in this simple app the plugin's RPC port is hard coded
	// under most circumstances the port should be configurable
	csPort = PLUGIN_PORT;

	// update the binding string - first determine this workstation's name
	WKSTA_INFO_100  *workstationInfoPtr;
	if (NetWkstaGetInfo(NULL, 100, (LPBYTE *)&workstationInfoPtr) == 0)
	{
		m_sClientBindingLen = 128;
		_sntprintf_s((wchar_t*)m_usClientBinding, m_sClientBindingLen, _TRUNCATE, _T("ncacn_ip_tcp:%s[%s]"), workstationInfoPtr->wki100_computername, csPort);
		m_sClientBindingLen = _tcslen((wchar_t*)m_usClientBinding) + 1;
	}

	// start the server
	if (!StartServer(ServerThread,
		(TCHAR*)(LPCTSTR)csPort,
		sizeof(hRpc) / sizeof(hRpc[0]),
		hRpc,
		pCWinThread,
		csError))
	{
		CString csPrompt;
		csPrompt.Format(_T("The plugin server failed to start: %s"), csError);
		AfxMessageBox(csPrompt, MB_OK | MB_ICONEXCLAMATION);

		EndDialog(IDCANCEL);
	}
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method: ServerThread
//
//  Description: A simple thread to support incoming RPC calls.
//
///////////////////////////////////////////////////////////////////////////////
UINT ServerThread(LPVOID pParam)
{
	RPC_STATUS      rpcStatus;
	unsigned int    uiMinCalls = 1;
	unsigned int    uiMaxCalls = 20;
	unsigned int    fDontWait = FALSE;

	// Listen for requests
	rpcStatus = RpcServerListen(uiMinCalls, uiMaxCalls, fDontWait);

	if (rpcStatus)
	{
		ASSERT(0);
	}

	AfxEndThread(0);

	return 0;
}

void CCiscoOpenAppDlg::OnBnClickedConnect()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);

	CString             csMachineNameAndPort;
	CString             csSelection;
	CString             csError;
	CString             csPrompt;
	EPICallStatus       eCallStatus;
	unsigned long       ulResult;

	// parse the edit box for name and port
	m_CEditNameAndPort.GetWindowTextW(csMachineNameAndPort);

	// Update buttons
	m_CButtonConnect.EnableWindow(FALSE);
	m_CButtonDisconnect.EnableWindow(TRUE);
	m_CEditNameAndPort.SetReadOnly(TRUE);
	m_CEditLine.SetReadOnly(TRUE);
	m_CEditSide.SetReadOnly(TRUE);
	m_CEditLogPath.SetReadOnly(TRUE);

	// minimal validation of the name & port
	int iColonIndex = csMachineNameAndPort.Find(_T(":"));
	CString csName = csMachineNameAndPort.Left(iColonIndex);
	CString csPort = csMachineNameAndPort.Mid(iColonIndex + 1);

	// Connection Code

	// OpenClientInterface opens a port to this application to accept RPC calls
	if (OpenClientInterface(csName,
		csPort,
		&m_hBinding,
		&m_szServerBinding,
		PISerConnectInterface_v1_0_c_ifspec,
		csError) == RPC_S_OK)
	{
		// Call the connect function and see if we're licensed, etc.
		// RpcBMConnect_SEH establishes a connection with benchmark
		// The returned m_phContext must be used in all subsequent communications with Benchmark
		ulResult = RpcBMConnect_SEH(m_hBinding,
			m_sClientBindingLen,
			m_usClientBinding,
			(unsigned short*)PLUGIN_GUID,
			_tcslen(PLUGIN_NAME) + 1,
			(unsigned short*)PLUGIN_NAME,
			&pContextHandler,
			&eCallStatus);

		if (CheckRpcResult(ulResult, eCallStatus))
		{
			// If the RpcBMConnect calls succeeds, communications have been established.
			// Any of the Open App interface functions may now be called.
			csPrompt.Format(L"Connected to %s:%s", csName, csPort);
			m_CEditStatus.SetWindowTextW(csPrompt);
			// AfxMessageBox(csPrompt);
		}
		else
		{
			// Update buttons
			m_CButtonConnect.EnableWindow(TRUE);
			m_CButtonDisconnect.EnableWindow(FALSE);
			m_CEditNameAndPort.SetReadOnly(FALSE);
			m_CEditLine.SetReadOnly(FALSE);
			m_CEditSide.SetReadOnly(FALSE);
			m_CEditLogPath.SetReadOnly(FALSE);
			m_CEditNameAndPort.SetFocus();
		}
	}
	else
	{
		csPrompt.Format(L"An RPC exception occurred while connecting to the Machine: %s", csError);
		AfxMessageBox(csPrompt);
	}
}


void CCiscoOpenAppDlg::OnBnClickedDisconnect()
{
	UpdateData(TRUE);
	EPICallStatus       eCallStatus;
	CString strText;

	// Update buttons
	m_CButtonConnect.EnableWindow(TRUE);
	m_CButtonDisconnect.EnableWindow(FALSE);
	m_CEditNameAndPort.SetReadOnly(FALSE);
	m_CEditLine.SetReadOnly(FALSE);
	m_CEditSide.SetReadOnly(FALSE);
	m_CEditLogPath.SetReadOnly(FALSE);

	// Disconnect from Benchmark
	// RpcBMDisconnect informs Benchmark that this OpenApp wants to 
	// cease interacting with it.  Benchmark performs some cleanup
	// which will allow future connections from this Open App
	RpcBMDisconnect_SEH(pContextHandler, 0, &eCallStatus);
	strText.Format(_T("Disconnected from Benchmark"));
	m_CEditStatus.SetWindowTextW(strText);
	m_CEditNameAndPort.SetFocus();
}
