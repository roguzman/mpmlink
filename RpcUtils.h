#pragma once
///////////////////////////////////////////////////////////////////////////////
// 
// $Workfile: RpcUtils.h $
// 
// $Author: Jim Fox $
// $Revision: 1 $
// $Date: 11/15/11 8:50a $
// 
// Copyright 2011 - Speedline Technologies, Inc.
//
// Description:  Declarations of RPC setup functions.
//
///////////////////////////////////////////////////////////////////////////////
#include "afxwin.h"
#include "rpc.h" 

CString GetSystemError( unsigned long lError );
RPC_STATUS OpenClientInterface( const TCHAR* pszNetworkAddress, 
                                const TCHAR* szPortNumber, 
                                RPC_BINDING_HANDLE* phRPC, 
                                TCHAR** pszStringBinding,
                                RPC_IF_HANDLE IfSpec,
                                CString& csError );
RPC_STATUS CloseClientInterface( TCHAR* pszStringBinding, RPC_BINDING_HANDLE* phRPC, CString& csError );
BOOL StopServer( unsigned int uiNumInterfaces, RPC_IF_HANDLE hRPC[], CString& csError );
BOOL StartServer( AFX_THREADPROC pfnThreadProc, 
                  TCHAR* szPortNumber, 
                  unsigned int uiNumInterfaces, 
                  RPC_IF_HANDLE hRPC[], 
                  CWinThread* pCWinThread, 
                  CString& csError );
