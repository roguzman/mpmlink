///////////////////////////////////////////////////////////////////////////////
// 
// $Workfile: ?/Utilities/OpenApps/PauseMachine/Source/BenchmarkRpcCalls.cpp $
// 
// $Author: jfox $
// $Revision: 67276+1 $
// $Date: 8/15/2012 4:43:49 PM $
// 
// Copyright 2011 - Speedline Technologies, Inc.
//
// Description:  Implements Structured Exception Handling (SEH) wrappers
// for the Benchmark RPC calls that are being used.  Each wrapper function
// adds a try/catch block to trap any RPC exceptions that may occur.
//
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "PISerConnectIF.h"
#include "PISerAlarmIF.h"

unsigned long RpcBMConnect_SEH( handle_t hdl,
                                short sStringBindingLen, 
                                unsigned short usStringBinding[], 
                                unsigned short usPluginGuid[], 
                                short sNameLen, 
                                unsigned short usName[], 
                                PCONTEXT_HDL_TYPE* pphContext, 
                                EPICallStatus* peCallStatus )
{
    unsigned long ulReturnVal = RPC_S_OK;
    
    RpcTryExcept
    {
        RpcBMConnect( hdl, sStringBindingLen, usStringBinding, usPluginGuid, sNameLen, usName, pphContext, peCallStatus );
    }
    RpcExcept(1)
    {
        ulReturnVal = RpcExceptionCode();
    }
    RpcEndExcept
    
    return ulReturnVal;
}

unsigned long RpcBMDisconnect_SEH( PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, EPICallStatus* peCallStatus )
{
    unsigned long ulReturnVal = RPC_S_OK;
    
    RpcTryExcept
    {
        RpcBMDisconnect( phContext, i64Timestamp, peCallStatus );
    }
    RpcExcept(1)
    {
        ulReturnVal = RpcExceptionCode();
    }
    RpcEndExcept
    
    return ulReturnVal;
}

unsigned long RpcBMPostAlarm_SEH(   PCONTEXT_HDL_TYPE phContext, 
                                    hyper i64Timestamp, 
                                    EPIAlarmSeverity eAlarmSeverity, 
                                    short sAlarmMessageLen, 
                                    unsigned short usAlarmMessage[], 
                                    hyper i64UserData,
                                    long* plAlarmId, 
                                    EPICallStatus* peCallStatus )
{
    unsigned long ulReturnVal = RPC_S_OK;
    
    RpcTryExcept
    {
        RpcBMPostAlarm( phContext, i64Timestamp, eAlarmSeverity, sAlarmMessageLen, usAlarmMessage, i64UserData, plAlarmId, peCallStatus );
    }
    RpcExcept(1)
    {
        ulReturnVal = RpcExceptionCode();
    }
    RpcEndExcept
    
    return ulReturnVal;
}




