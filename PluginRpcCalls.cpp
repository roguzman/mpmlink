///////////////////////////////////////////////////////////////////////////////
// 
// $Workfile: ?/Utilities/OpenApps/PauseMachine/Source/PluginRpcCalls.cpp $
// 
// $Author: jfox $
// $Revision: 0+1 $
// $Date: 5/17/2012 3:42:44 PM $
// 
// Copyright 2011 - Speedline Technologies, Inc.
//
// Description:  This file implements the functions declared in PICliConnectIF.h.
// PICliConnectIF.h - is automatically generated when PICliConnectIF.idl is 
// compiled with the MIDL compiler.
//
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "PluginInfo.h"
#include "PICliConnectIF.h"
#include "PICliAlarmIF.h"
#include "PICliMessageIF.h"
#include "PICliStateIF.h"
#include "PICliBoardIF.h"

extern PCONTEXT_HDL_TYPE       pContextHandler;
extern CEdit                   m_CEditMessage;

CString strBuffer;
CString text;

void UpdateCEdit(LPCTSTR text)
{
	strBuffer.Append(text);
	m_CEditMessage.SetWindowTextW(strBuffer);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method: RpcPIGetNotificationList
//
//  Description: Called by Benchmark immediately following a call by a plugin of
//  RpcBMConnect.  This function tells benchmark what notifications are requested
//  by the plugin.  In the case of this PauseMachine plugin - no notifications
//  are requested.
//
///////////////////////////////////////////////////////////////////////////////
void RpcPIGetNotificationList( handle_t hdl, hyper i64Timestamp, short* sListLen, EPINotifyType eNotifyList[], PCONTEXT_HDL_TYPE* pphContext )
{
    // no notifications
    *sListLen = 2;
	eNotifyList[0] = ePINotifyTypeMessage;
	eNotifyList[1] = ePINotifyTypeBoard;
    // give Benchmark a context handle to use when calling the plugin.
    // normally this could be a pointer to a plugin side context data structure or object
    // for this simple example anything non-NULL will work.
    // *pphContext = (PCONTEXT_HDL_TYPE)0x00000001;
	*pphContext = (PCONTEXT_HDL_TYPE)pContextHandler;
	OutputDebugStringW(L"RpcPIGetNotificationList\n");
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method: RpcPIGetVersionInfo
//
//  Description: Called by Benchmark immediately following a call by a plugin of
//  RpcBMConnect.  Tells Benchmark the plugin's schema version, etc.
//
///////////////////////////////////////////////////////////////////////////////
void RpcPIGetVersionInfo( handle_t hdl, hyper i64Timestamp, short* sNameLen, unsigned short usName[], short* sSoftwareVersionLen, unsigned short usSoftwareVersion[], long* lSchema )
{
    *lSchema = BENCHMARK_PII_SCHEMA_VERSION;

    _sntprintf_s( (wchar_t*)usName, *sNameLen, _TRUNCATE, _T("%s"), PLUGIN_NAME );
    *sNameLen = _tcslen( (wchar_t*)usName ) + 1;

    _sntprintf_s( (wchar_t*)usSoftwareVersion, *sSoftwareVersionLen, _TRUNCATE, _T("%s"), PLUGIN_VERSION );
    *sSoftwareVersionLen = _tcslen( (wchar_t*)usSoftwareVersion ) + 1;
	OutputDebugStringW(L"RpcPIGetVersionInfo\n");
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method: RpcPIPing
//
//  Description:  Benchmark may or may not call this function at anytime.  It
//  provides Benchmark with the ability to test the connection to the plugin.
//
///////////////////////////////////////////////////////////////////////////////
void RpcPIPing( PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp )
{
    // do nothing
	OutputDebugStringW(L"RpcPIPing\n");

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method: RpcPIDisconnect
//
//  Description: Called immediately prior to Benchmark terminating communications
//  with the plugin.
//
///////////////////////////////////////////////////////////////////////////////
void RpcPIDisconnect( PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp )
{
    // do nothing
	OutputDebugStringW(L"RpcPIDisconnect\n");
}

///////////////////////////////////////////////////////////////////////////////
//  Alarm Interface methods
///////////////////////////////////////////////////////////////////////////////
void RpcPIAlarmChange( PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, long lAlarmId, EPIAlarmAction eAction )
{
	// do nothing
	OutputDebugStringW(L"RpcPIAlarmChange\n");
}

void RpcPIAlarmSysStateChange (PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, EPIAlarmSysState eNewState )
{
	// do nothing
	OutputDebugStringW(L"RpcPIAlarmSysStateChange\n");
}

void RpcPIAlarmTriggered( PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, long lAlarmId, EPIAlarmType eAlarmType, EPIAlarmSubType eAlarmSubType, EPIAlarmSeverity eSeverity, short sTextLen, unsigned short usText[], short sPluginBindingLen, unsigned short usPluginBinding[], short sPluginNameLen, unsigned short usPluginName[], hyper i64UserData )
{
	// do nothing
	OutputDebugStringW(L"RpcPIAlarmTriggered\n");
}

///////////////////////////////////////////////////////////////////////////////
//  Message Interface methods
///////////////////////////////////////////////////////////////////////////////
void RpcPIPostMessage( PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, short sMessageLen, unsigned short usMessage[] )
{
	text.Format(_T("- RpcPIPostMessage : %s\r\n"), usMessage);
	UpdateCEdit(text);
}

///////////////////////////////////////////////////////////////////////////////
//  State Interface methods
///////////////////////////////////////////////////////////////////////////////
void RpcPIChangeoverEnded(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, boolean bUserCancelled) {}
void RpcPIChangeoverStarted(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp) {}
void RpcPIChangePasteComplete(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp) {}
void RpcPIChangePasteStarted(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp) {}
void RpcPIDiagnosticsModeEnded(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp) {}
void RpcPIDiagnosticsModeStarted(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp) {}
void RpcPIDispenseComplete(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp) {}
void RpcPIDispenseStarted(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, short sProfileNameLen, unsigned short usProfileName[]) {}
void RpcPIKneadNotification(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, long lBoardId) {}
void RpcPIMachineStateChange(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, EPISysMachineState eNewState) {}
void RpcPIManualAddPasteComplete(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp) {}
void RpcPIManualAddPasteStarted(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp) {}
void RpcPIManualReducePasteComplete(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp) {}
void RpcPIManualReducePasteStarted(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp) {}
void RpcPIManualStencilCleanComplete(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp) {}
void RpcPIManualStencilCleanStarted(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp) {}
void RpcPIPrintStrokeEnded(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp) {}
void RpcPIPrintStrokeStarted(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, boolean bIsFrontToRear, short sStrokeNumber) {}
void RpcPIProcessModeChange(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, EPIProcessMode eNewProcessMode) {}
void RpcPISnapoffStarted(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, short sProfileNameLen, unsigned short usProfileName[], short sNumSnapffSegments, EPISnapoffMoveType pSegmentMoveType[], double pdSegmentDistanceMm[], double pdSegmentSpeedMmPerSec[], double pdSegmentStepSizeMm[], int pdSegmentStepDelayMilliSecs[]) {}
void RpcPIStencilInserted(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp) {}
void RpcPIStencilRemoved(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp) {}
void RpcPIWipeComplete(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp) {}
void RpcPIWipeRequested(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, boolean bIsRequesting, short sRequesterNameLen, unsigned short usRequesterName[]) {}
void RpcPIWipeStarted(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, short sProfileNameLen, unsigned short usProfileName[]) {}
void RpcPIWipeStartedWithData(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, short sProfileNameLen, unsigned short usProfileName[], double dHopOver, double dTravelOffset, EPIWipePaperFeedMode ePaperFeedMode, EPIWipeEventType eWipeEventType, short sWipeFrequency, short sNumSegments, double dSegmentIndexDistanceMm[], double dSegmentSpeedMmPerSec[], EPIWipeStrokeType eStrokeType[]) {}

///////////////////////////////////////////////////////////////////////////////
//  Board Interface methods
///////////////////////////////////////////////////////////////////////////////
void RpcPIBoardAccepted(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, long lBoardId) { OutputDebugStringW(L"RpcPIBoardAccepted\n"); }
void RpcPIBoardBarcodeNotification(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, EPIBarcodeSource eBarcodeSource, short sBarcodeLen, unsigned short usBarcode[]) { UpdateCEdit(L"Board Scanned : %s"); }
void RpcPIBoardClamped(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, long lBoardId) { OutputDebugStringW(L"RpcPIBoardClamped\n"); }
void RpcPIBoardPrinted(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, long lBoardNumber, short sBarcodeLen, unsigned short usBarcode[], boolean bInitStrokeF2R, short sNumStrokes, EPIProcessedStatus eProcessedStatus, long lPackagedDataLength, byte packagedData[]) 
{ 
	text.Format(L"{\"Board Printed\" : %d, \"Barcode\" : \"%s\", \"Status\": %d}\r\n", lBoardNumber, usBarcode, eProcessedStatus);
	UpdateCEdit(text); 
}
void RpcPIBoardProcgCompleted(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, long lBoardId, long lBoardCount) {}
void RpcPIBoardProcgStarted(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, long lBoardId) {}
void RpcPIBoardRejected(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, long lBoardId) {}
void RpcPIBoardUnclamped(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, long lBoardId) {}
void RpcPIClearQueue(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp) {}
void RpcPIPostPanelData(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, long lBoardId, short sNumPanels, short sPanelIdList[], unsigned short usBarcodeList[][BENCHMARK_PII_MAX_BARCODE_LEN]) {}
void RpcPIPostPasteHeightData(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, long lBoardId, double dPasteHeightMinMm, double dPasteHeightMeasuredMm) {}
void RpcPIPostPasteHeightDataEx(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, long lBoardId, double dPasteHeightMinMm, double dPasteHeightMaxMm, double dPasteHeightMeasuredMm) {}

///////////////////////////////////////////////////////////////////////////////
//
//  Method: PCONTEXT_HDL_TYPE_rundown
//
//  Description: This function is required for compilation with Visual Studio.
//
///////////////////////////////////////////////////////////////////////////////
extern "C" void RPC_ENTRY PCONTEXT_HDL_TYPE_rundown(PCONTEXT_HDL_TYPE /*phContext*/)
{
} 


