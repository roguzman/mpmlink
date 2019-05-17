

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Wed Jun 06 13:58:05 2018
 */
/* Compiler settings for PICliAlarmIF.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __PICliAlarmIF_h__
#define __PICliAlarmIF_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

/* header files for imported files */
#include "PIDef.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __PICliAlarmInterface_INTERFACE_DEFINED__
#define __PICliAlarmInterface_INTERFACE_DEFINED__

/* interface PICliAlarmInterface */
/* [version][uuid] */ 

void RpcPIAlarmTriggered( 
    /* [in] */ PCONTEXT_HDL_TYPE phContext,
    /* [in] */ hyper i64Timestamp,
    /* [in] */ long lAlarmId,
    /* [in] */ EPIAlarmType eAlarmType,
    /* [in] */ EPIAlarmSubType eAlarmSubType,
    /* [in] */ EPIAlarmSeverity eSeverity,
    /* [in] */ short sTextLen,
    /* [size_is][in] */ unsigned short usText[  ],
    /* [in] */ short sPluginBindingLen,
    /* [size_is][in] */ unsigned short usPluginBinding[  ],
    /* [in] */ short sPluginNameLen,
    /* [size_is][in] */ unsigned short usPluginName[  ],
    /* [in] */ hyper i64UserData);

void RpcPIAlarmChange( 
    /* [in] */ PCONTEXT_HDL_TYPE phContext,
    /* [in] */ hyper i64Timestamp,
    /* [in] */ long lAlarmId,
    /* [in] */ EPIAlarmAction eAction);

void RpcPIAlarmSysStateChange( 
    /* [in] */ PCONTEXT_HDL_TYPE phContext,
    /* [in] */ hyper i64Timestamp,
    /* [in] */ EPIAlarmSysState eNewState);



extern RPC_IF_HANDLE PICliAlarmInterface_v1_0_c_ifspec;
extern RPC_IF_HANDLE PICliAlarmInterface_v1_0_s_ifspec;
#endif /* __PICliAlarmInterface_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

void __RPC_USER PCONTEXT_HDL_TYPE_rundown( PCONTEXT_HDL_TYPE );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif

