#pragma once
///////////////////////////////////////////////////////////////////////////////
// 
// $Workfile: ?/Utilities/OpenApps/PauseMachine/Source/BenchmarkRpcCalls.h $
// 
// $Author: jfox $
// $Revision: 67276+1 $
// $Date: 8/15/2012 4:43:49 PM $
// 
// Copyright 2011 - Speedline Technologies, Inc.
//
// Description:  Declarations of wrapper functions.
//
///////////////////////////////////////////////////////////////////////////////
#include "afxwin.h"
#include "PIDef.h"

unsigned long RpcBMConnect_SEH( handle_t hdl,
                                short sStringBindingLen, 
                                unsigned short usStringBinding[], 
                                unsigned short usPluginGuid[], 
                                short sNameLen, 
                                unsigned short usName[], 
                                PCONTEXT_HDL_TYPE* pphContext, 
                                EPICallStatus* peCallStatus );
unsigned long RpcBMDisconnect_SEH( PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, EPICallStatus* peCallStatus );
unsigned long RpcBMPostAlarm_SEH(   PCONTEXT_HDL_TYPE phContext, 
                                    hyper i64Timestamp, 
                                    EPIAlarmSeverity eAlarmSeverity, 
                                    short sAlarmMessageLen, 
                                    unsigned short usAlarmMessage[], 
                                    hyper i64UserData,
                                    long* plAlarmId, 
                                    EPICallStatus* peCallStatus );
