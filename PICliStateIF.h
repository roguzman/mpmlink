

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Wed Jun 06 13:58:06 2018
 */
/* Compiler settings for PICliStateIF.idl:
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


#ifndef __PICliStateIF_h__
#define __PICliStateIF_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

/* header files for imported files */
#include "PIDef.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __PICliStateInterface_INTERFACE_DEFINED__
#define __PICliStateInterface_INTERFACE_DEFINED__

/* interface PICliStateInterface */
/* [version][uuid] */ 

void RpcPIMachineStateChange( 
    /* [in] */ PCONTEXT_HDL_TYPE phContext,
    /* [in] */ hyper i64Timestamp,
    /* [in] */ EPISysMachineState eNewState);

void RpcPIWipeStarted( 
    /* [in] */ PCONTEXT_HDL_TYPE phContext,
    /* [in] */ hyper i64Timestamp,
    /* [in] */ short sProfileNameLen,
    /* [size_is][in] */ unsigned short usProfileName[  ]);

void RpcPIWipeComplete( 
    /* [in] */ PCONTEXT_HDL_TYPE phContext,
    /* [in] */ hyper i64Timestamp);

void RpcPIManualStencilCleanStarted( 
    /* [in] */ PCONTEXT_HDL_TYPE phContext,
    /* [in] */ hyper i64Timestamp);

void RpcPIManualStencilCleanComplete( 
    /* [in] */ PCONTEXT_HDL_TYPE phContext,
    /* [in] */ hyper i64Timestamp);

void RpcPIDispenseStarted( 
    /* [in] */ PCONTEXT_HDL_TYPE phContext,
    /* [in] */ hyper i64Timestamp,
    /* [in] */ short sProfileNameLen,
    /* [size_is][in] */ unsigned short usProfileName[  ]);

void RpcPIDispenseComplete( 
    /* [in] */ PCONTEXT_HDL_TYPE phContext,
    /* [in] */ hyper i64Timestamp);

void RpcPIManualAddPasteStarted( 
    /* [in] */ PCONTEXT_HDL_TYPE phContext,
    /* [in] */ hyper i64Timestamp);

void RpcPIManualAddPasteComplete( 
    /* [in] */ PCONTEXT_HDL_TYPE phContext,
    /* [in] */ hyper i64Timestamp);

void RpcPIChangePasteStarted( 
    /* [in] */ PCONTEXT_HDL_TYPE phContext,
    /* [in] */ hyper i64Timestamp);

void RpcPIChangePasteComplete( 
    /* [in] */ PCONTEXT_HDL_TYPE phContext,
    /* [in] */ hyper i64Timestamp);

void RpcPIStencilRemoved( 
    /* [in] */ PCONTEXT_HDL_TYPE phContext,
    /* [in] */ hyper i64Timestamp);

void RpcPIStencilInserted( 
    /* [in] */ PCONTEXT_HDL_TYPE phContext,
    /* [in] */ hyper i64Timestamp);

void RpcPIPrintStrokeStarted( 
    /* [in] */ PCONTEXT_HDL_TYPE phContext,
    /* [in] */ hyper i64Timestamp,
    /* [in] */ boolean bIsFrontToRear,
    /* [in] */ short sStrokeNumber);

void RpcPIPrintStrokeEnded( 
    /* [in] */ PCONTEXT_HDL_TYPE phContext,
    /* [in] */ hyper i64Timestamp);

void RpcPIKneadNotification( 
    /* [in] */ PCONTEXT_HDL_TYPE phContext,
    /* [in] */ hyper i64Timestamp,
    /* [in] */ long lBoardId);

void RpcPIWipeRequested( 
    /* [in] */ PCONTEXT_HDL_TYPE phContext,
    /* [in] */ hyper i64Timestamp,
    /* [in] */ boolean bIsRequesting,
    /* [in] */ short sRequesterNameLen,
    /* [size_is][in] */ unsigned short usRequesterName[  ]);

void RpcPISnapoffStarted( 
    /* [in] */ PCONTEXT_HDL_TYPE phContext,
    /* [in] */ hyper i64Timestamp,
    /* [in] */ short sProfileNameLen,
    /* [size_is][in] */ unsigned short usProfileName[  ],
    /* [in] */ short sNumSnapffSegments,
    /* [size_is][in] */ EPISnapoffMoveType pSegmentMoveType[  ],
    /* [size_is][in] */ double pdSegmentDistanceMm[  ],
    /* [size_is][in] */ double pdSegmentSpeedMmPerSec[  ],
    /* [size_is][in] */ double pdSegmentStepSizeMm[  ],
    /* [size_is][in] */ int pdSegmentStepDelayMilliSecs[  ]);

void RpcPIWipeStartedWithData( 
    /* [in] */ PCONTEXT_HDL_TYPE phContext,
    /* [in] */ hyper i64Timestamp,
    /* [in] */ short sProfileNameLen,
    /* [size_is][in] */ unsigned short usProfileName[  ],
    /* [in] */ double dHopOver,
    /* [in] */ double dTravelOffset,
    /* [in] */ EPIWipePaperFeedMode ePaperFeedMode,
    /* [in] */ EPIWipeEventType eWipeEventType,
    /* [in] */ short sWipeFrequency,
    /* [in] */ short sNumSegments,
    /* [size_is][in] */ double dSegmentIndexDistanceMm[  ],
    /* [size_is][in] */ double dSegmentSpeedMmPerSec[  ],
    /* [size_is][in] */ EPIWipeStrokeType eStrokeType[  ]);

void RpcPIProcessModeChange( 
    /* [in] */ PCONTEXT_HDL_TYPE phContext,
    /* [in] */ hyper i64Timestamp,
    /* [in] */ EPIProcessMode eNewProcessMode);

void RpcPIDiagnosticsModeStarted( 
    /* [in] */ PCONTEXT_HDL_TYPE phContext,
    /* [in] */ hyper i64Timestamp);

void RpcPIDiagnosticsModeEnded( 
    /* [in] */ PCONTEXT_HDL_TYPE phContext,
    /* [in] */ hyper i64Timestamp);

void RpcPIChangeoverStarted( 
    /* [in] */ PCONTEXT_HDL_TYPE phContext,
    /* [in] */ hyper i64Timestamp);

void RpcPIChangeoverEnded( 
    /* [in] */ PCONTEXT_HDL_TYPE phContext,
    /* [in] */ hyper i64Timestamp,
    /* [in] */ boolean bUserCancelled);

void RpcPIManualReducePasteStarted( 
    /* [in] */ PCONTEXT_HDL_TYPE phContext,
    /* [in] */ hyper i64Timestamp);

void RpcPIManualReducePasteComplete( 
    /* [in] */ PCONTEXT_HDL_TYPE phContext,
    /* [in] */ hyper i64Timestamp);



extern RPC_IF_HANDLE PICliStateInterface_v1_0_c_ifspec;
extern RPC_IF_HANDLE PICliStateInterface_v1_0_s_ifspec;
#endif /* __PICliStateInterface_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

void __RPC_USER PCONTEXT_HDL_TYPE_rundown( PCONTEXT_HDL_TYPE );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


