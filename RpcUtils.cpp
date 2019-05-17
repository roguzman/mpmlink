///////////////////////////////////////////////////////////////////////////////
// 
// $Workfile: RpcUtils.cpp$
// 
// $Author: Jim Fox $
// $Revision: 1 $
// $Date: 11/15/11 8:50a $
// 
// Copyright 2011 - Speedline Technologies, Inc.
//
// Description:  Implementations of some basic functionality common to most RPC
// applications.
//
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

///////////////////////////////////////////////////////////////////////////////
//
//  Method: MIDL_user_allocate
//
//  Description:  Standard allocation function that must be provided to the
//  RPC infrastructure.
//
///////////////////////////////////////////////////////////////////////////////
void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t len)
{
    return(malloc(len));
}
 
///////////////////////////////////////////////////////////////////////////////
//
//  Method: MIDL_user_free
//
//  Description:  Standard free function that must be provided to the
//  RPC infrastructure.
//
///////////////////////////////////////////////////////////////////////////////
void __RPC_USER MIDL_user_free(void __RPC_FAR * ptr)
{
    free(ptr);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method: GetSystemError
//
//  Description: Helper function to convert RPC error codes to text.
//
///////////////////////////////////////////////////////////////////////////////
CString GetSystemError( unsigned long lError )
{
    LPVOID lpMsgBuf;
    CString csMsg;

    FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL, lError, MAKELANGID(LANG_NEUTRAL,  SUBLANG_DEFAULT), 
        (LPTSTR)&lpMsgBuf, 0, NULL);

    // Get the Error String and free the buffer
    csMsg = (LPTSTR) lpMsgBuf;
    LocalFree(lpMsgBuf);

    return csMsg;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method: OpenClientInterface
//
//  Description:  Opens the "raw" RPC connection to a server.  This function 
//  performs the setup necessary prior to make any specific RPC calls.
//
///////////////////////////////////////////////////////////////////////////////
RPC_STATUS OpenClientInterface( const TCHAR* pszNetworkAddress, 
                                const TCHAR* szPortNumber, 
                                RPC_BINDING_HANDLE* phRPC, 
                                TCHAR** pszStringBinding,
                                RPC_IF_HANDLE IfSpec,
                                CString& csError )
{
    RPC_STATUS  rpcStatus;

    // Get the String Binding to use
    rpcStatus = RpcStringBindingCompose( (unsigned short *)_T(""), 
                                         (unsigned short *)_T("ncacn_ip_tcp"),
                                         (unsigned short *)pszNetworkAddress, 
                                         (unsigned short *)szPortNumber,
                                         (unsigned short *)_T(""), 
                                         (unsigned short **)pszStringBinding );

    if( rpcStatus ) 
    {
        csError.Format( _T("ERROR RpcStringBindingCompose returned: %d - %s"), rpcStatus, GetSystemError( rpcStatus ) );
    }
    else
    {
        // Obtain a binding handle using the binding string we just created
        rpcStatus = RpcBindingFromStringBinding( (unsigned short *)*pszStringBinding, phRPC );

        if( rpcStatus ) 
        {
            csError.Format( _T("ERROR RpcBindingFromStringBinding returned: %d - %s"), rpcStatus, GetSystemError( rpcStatus ) );
        }
        else
        {
            // Not really needed in Win2000
            rpcStatus = RpcEpResolveBinding( *phRPC, IfSpec );

            if( rpcStatus )  
            {
                csError.Format( _T("ERROR RpcEpResolveBinding returned: %d - %s"), rpcStatus, GetSystemError( rpcStatus ) );
            }

            // Check to see if the server we want to talk to is listening
            rpcStatus = RpcMgmtIsServerListening( *phRPC );

            if( rpcStatus ) 
            {
                //// In XP SP2 even though our server allows anonymous RPC calls 
                //// this call fails because SP2 wants RpcMgmt calls to uase
                //// authentication.  We could alternately get this call to work
                //// by enabling anonymous RPC calls for the machine by changing
                //// the registry setting (making it like XP SP1) but this would
                //// then allow any program to have anonymous RPC.
                //// To enable XP SP1 like behavior set
                ////   HKEY_LOCAL_MACHINE\SOFTWARE\Policies\Microsoft\Windows NT\RPC
                //// to  
                ////   0

                csError.Format( _T("ERROR RpcMgmtIsServerListening returned: %d - %s"), rpcStatus, GetSystemError( rpcStatus ) );
                csError.Format( _T("Connection Probably OK") );

                rpcStatus = RPC_S_OK;
            }
        }
    }

    return ( rpcStatus );
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method: CloseClientInterface
//
//  Description: Free resources allocated during OpenClientInterface
//
///////////////////////////////////////////////////////////////////////////////
RPC_STATUS CloseClientInterface( TCHAR* pszStringBinding, RPC_BINDING_HANDLE* phRPC, CString& csError )
{
    RPC_STATUS rpcStatus;

    rpcStatus = RpcStringFree( (unsigned short **) &pszStringBinding ); 

    if( rpcStatus ) 
    {
        csError.Format( _T("ERROR RpcStringFree of %s returned: %d - %s"), pszStringBinding, rpcStatus, GetSystemError( rpcStatus ) );
    }
    else
    {
        rpcStatus = RpcBindingFree( phRPC );
     
        if( rpcStatus ) 
        {
            csError.Format( _T("ERROR RpcBindingFree returned: %d - %s"), rpcStatus, GetSystemError( rpcStatus ) );
        }
        else
        {
            csError.Format( _T("Disconnection Successful") );
        }
    }

    return rpcStatus;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method: StartServer
//
//  Description: Performs the setup necessary for an application to recieve
//  RPC calls.
//
///////////////////////////////////////////////////////////////////////////////
BOOL StartServer( AFX_THREADPROC pfnThreadProc, TCHAR* szPortNumber, unsigned int uiNumInterfaces, RPC_IF_HANDLE hRPC[], CWinThread* pCWinThread, CString& csError )
{
    BOOL            bSuccess = TRUE;
    TCHAR*          pszSecurity = NULL; 
    unsigned int    uiMaxCalls  = 20;
    RPC_STATUS      rpcStatus;

    // Specify that the application will accpet RPC calls on the specified port.
    rpcStatus = RpcServerUseProtseqEp( (unsigned short *)_T("ncacn_ip_tcp"), uiMaxCalls, (unsigned short*)szPortNumber, pszSecurity );

    if( rpcStatus )
    {
        csError.Format( _T("StartServer(RpcServerUseProtseqEp): Rpc Error %d - %s"), rpcStatus, GetSystemError(rpcStatus) );
        bSuccess = FALSE;
    }
    else
    {
        // register the specific interfaces that will be handled.
        for( unsigned int uiInterfaceIndex = 0; uiInterfaceIndex < uiNumInterfaces; uiInterfaceIndex++ )
        {
            // Use RpcServerRegisterIf2 and not RpcServerRegisterIf to register our interface.
            // This allows our server to accept anonymous RPC calls with making a change to 
            // the registry so that XP SP2 would behave like XP SP1 allowing any and all 
            // anonymous calls.  The key here is to use RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH.
            // It's worth noting that this will still not allow RpcMgmt cals which will
            // still want authentication but we don't need to use these.
            rpcStatus = RpcServerRegisterIf2( hRPC[uiInterfaceIndex], 
                                              NULL, 
                                              NULL,
                                              RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH, 
                                              uiMaxCalls, 
                                              400, 
                                              NULL ); 
                
            if( rpcStatus )
            {
                csError.Format( _T("StartServer(RpcServerRegisterIf2): Rpc Error %d - %s"), rpcStatus, GetSystemError(rpcStatus) );
                bSuccess = FALSE;
                break;
            }
        }

        if( bSuccess )
        {
            // Create the RPC Interface Thread if needed
            rpcStatus = RpcMgmtIsServerListening( NULL );

            if( rpcStatus )
            {
                if ( rpcStatus == RPC_S_NOT_LISTENING )
                {
                    pCWinThread = AfxBeginThread( pfnThreadProc, NULL, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED, NULL);
                    ASSERT(pCWinThread);
                    pCWinThread->m_bAutoDelete = TRUE;
                    pCWinThread->ResumeThread();
                }
                else
                {
                    csError.Format( _T("StartServer(RpcMgmtIsServerListening): Rpc Error %d - %s"), rpcStatus, GetSystemError(rpcStatus) );
                    bSuccess = FALSE;
                }
            }
        }
    }
    
    return bSuccess;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method: StopServer
//
//  Description: Unregisters RPC interfaces and stops listening for RPC calls.
//
///////////////////////////////////////////////////////////////////////////////
BOOL StopServer( unsigned int uiNumInterfaces, RPC_IF_HANDLE hRPC[], CString& csError )
{
    BOOL            bSuccess = TRUE;        // Assume success
    RPC_STATUS      rpcStatus;

    // stop the listening thread - effectively closes the port.
    rpcStatus = RpcMgmtStopServerListening( NULL );

    if( rpcStatus )
    {
        csError.Format( _T("StopServer(RpcMgmtStopServerListening): Rpc Error %d - %s"), rpcStatus, GetSystemError(rpcStatus) );
        bSuccess = FALSE;
    }
    else
    {
        // unregister our interfaces.
        for( unsigned int uiInterfaceIndex = 0; uiInterfaceIndex < uiNumInterfaces; uiInterfaceIndex++ )
        {
            rpcStatus = RpcServerUnregisterIf( hRPC[uiInterfaceIndex], NULL, 0 );

            if( rpcStatus )
            {
                csError.Format( _T("StopServer(RpcServerUnregisterIf): Rpc Error %d - %s"), rpcStatus, GetSystemError(rpcStatus) );
                bSuccess = FALSE;
            }
        }
    }

    return bSuccess;
}

