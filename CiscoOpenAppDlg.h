
// CiscoOpenAppDlg.h: archivo de encabezado
//

#pragma once

#include "afxwin.h"
#include "PIDef.h"

#define     MAX_STRING_BINDING_LEN      128
#define     MAX_MRU_MachineS            25

// Cuadro de diálogo de CCiscoOpenAppDlg
class CCiscoOpenAppDlg : public CDialogEx
{
// Construcción
public:
	CCiscoOpenAppDlg(CWnd* pParent = nullptr);	// Constructor estándar

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CISCOOPENAPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Compatibilidad con DDX/DDV


// Implementación
protected:
	HICON m_hIcon;

	// Funciones de asignación de mensajes generadas
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	void InitRpc(void);
	BOOL CheckRpcResult(unsigned long ulResult, EPICallStatus eCallStatus);

public:
	RPC_BINDING_HANDLE      m_hBinding;
	unsigned short          m_usClientBinding[MAX_STRING_BINDING_LEN];
	short                   m_sClientBindingLen;
	TCHAR*                  m_szServerBinding;
	PCONTEXT_HDL_TYPE       m_phContext;
	BOOL                    m_bConnected;
	CEdit                   m_CEditNameAndPort;
	CEdit                   m_CEditStatus;
	CButton                 m_CButtonConnect;
	CButton                 m_CButtonDisconnect;
	afx_msg void OnBnClickedConnect();
	afx_msg void OnBnClickedDisconnect();
};

UINT ServerThread(LPVOID pParam);
