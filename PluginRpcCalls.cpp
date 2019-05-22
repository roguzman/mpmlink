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
extern CEdit                   m_CEditLine;
extern CEdit                   m_CEditSide;
extern CEdit                   m_CEditLogPath;

CString strBuffer;
CString text;

void UpdateCEdit(CString text)
{
	int nLength = m_CEditMessage.GetWindowTextLength();
	// put the selection at the end of text
	m_CEditMessage.SetSel(nLength, nLength);
	// replace the selection
	m_CEditMessage.ReplaceSel(text);
	// strBuffer.Append(text);
	// m_CEditMessage.SetWindowTextW(strBuffer);
}

CString getTimeStamp(time_t epoch)
{
	CTime t(epoch);
	CString res = t.Format("%Y-%m-%d %H-%M-%S");
	return res;
}

void saveToFile(CString type, time_t epoch, CString header, CString text)
{
	CString line;
	CString	side;
	CString logpath;
	CString strFileName;

	CTime t(epoch);
	CString res = t.Format("%Y-%m-%d_%H-%M-%S");

	m_CEditLine.GetWindowTextW(line);
	m_CEditSide.GetWindowTextW(side);
	m_CEditLogPath.GetWindowTextW(logpath);

	strFileName.Format(_T("%s%s_%s_%s_%s.csv"), (LPCWSTR)logpath, (LPCWSTR)line, (LPCWSTR)side, (LPCWSTR)type, (LPCWSTR)res);
	CStdioFile f(strFileName, CFile::modeCreate | CFile::modeReadWrite);
	f.WriteString(header);
	f.WriteString(text);
	f.Close();
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
    *sListLen = 3;
	eNotifyList[0] = ePINotifyTypeMessage;
	eNotifyList[1] = ePINotifyTypeBoard;
	eNotifyList[2] = ePINotifyTypeState;
    // give Benchmark a context handle to use when calling the plugin.
    // normally this could be a pointer to a plugin side context data structure or object
    // for this simple example anything non-NULL will work.
    // *pphContext = (PCONTEXT_HDL_TYPE)0x00000001;
	*pphContext = (PCONTEXT_HDL_TYPE)pContextHandler;
	UpdateCEdit(L"Received Notification List request.\r\n");
	UpdateCEdit(L"Subscribed to : [ePINotifyTypeMessage, ePINotifyTypeBoard, ePINotifyTypeState]\r\n");
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
}

///////////////////////////////////////////////////////////////////////////////
//  Alarm Interface methods
///////////////////////////////////////////////////////////////////////////////
void RpcPIAlarmChange( PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, long lAlarmId, EPIAlarmAction eAction )
{
	// do nothing
}

void RpcPIAlarmSysStateChange (PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, EPIAlarmSysState eNewState )
{
	// do nothing
}

void RpcPIAlarmTriggered( PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, long lAlarmId, EPIAlarmType eAlarmType, EPIAlarmSubType eAlarmSubType, EPIAlarmSeverity eSeverity, short sTextLen, unsigned short usText[], short sPluginBindingLen, unsigned short usPluginBinding[], short sPluginNameLen, unsigned short usPluginName[], hyper i64UserData )
{
	// do nothing
}

///////////////////////////////////////////////////////////////////////////////
//  Message Interface methods
///////////////////////////////////////////////////////////////////////////////
void RpcPIPostMessage( PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, short sMessageLen, unsigned short usMessage[] )
{
	CString strDate;

	strDate = getTimeStamp(i64Timestamp);

	text.Format(_T("Message sent by Benchmark : Timestamp=%s Message=%s \r\n"), (LPCWSTR)strDate, usMessage);
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
void RpcPIDispenseComplete(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp)
{
	CString strDate;

	strDate = getTimeStamp(i64Timestamp);

	CString data;
	data.Format(_T("%s \r\n"), (LPCWSTR)strDate);
	saveToFile(L"dispense", i64Timestamp, L"TimeStamp\n", data);

	text.Format(_T("Dispense Completed : TimeStamp=%s \r\n"), (LPCWSTR)strDate);
	UpdateCEdit(text);
}
void RpcPIDispenseStarted(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, short sProfileNameLen, unsigned short usProfileName[])
{
	CString strDate;

	strDate = getTimeStamp(i64Timestamp);

	text.Format(_T("Dispense Started : TimeStamp=%s  ProfileName=%s \r\n"), (LPCWSTR)strDate, usProfileName);
	UpdateCEdit(text);
}
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
void RpcPIWipeStartedWithData(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, short sProfileNameLen, unsigned short usProfileName[], double dHopOver, double dTravelOffset, 
	EPIWipePaperFeedMode ePaperFeedMode, EPIWipeEventType eWipeEventType, short sWipeFrequency, short sNumSegments, double dSegmentIndexDistanceMm[], double dSegmentSpeedMmPerSec[],
	EPIWipeStrokeType eStrokeType[])
{
	CString strPaperFeedMode;
	CString strWipeEventType;
	CString strStrokeType;
	CString strDate;

	switch (ePaperFeedMode)
	{
	case EPIWipePaperFeedMode::ePIWipePaperFeedModeUndefined:
		strPaperFeedMode = L"Undefined";
		break;
	case EPIWipePaperFeedMode::ePIWipePaperFeedModeIndex:
		strPaperFeedMode = L"Index";
		break;
	case EPIWipePaperFeedMode::ePIWipePaperFeedModeContinuous:
		strPaperFeedMode = L"Continuous";
		break;
	case EPIWipePaperFeedMode::ePIWipePaperFeedModeLast:
		strPaperFeedMode = L"Last";
		break;
	default:
		break;
	}

	switch (eWipeEventType)
	{
	case EPIWipeEventType::PIWipeEventTypeAuerBoatComplete:
		strWipeEventType = L"AuerBoatComplete";
		break;
	case EPIWipeEventType::PIWipeEventTypeBoard:
		strWipeEventType = L"Board";
		break;
	case EPIWipeEventType::PIWipeEventTypeCleanAndRemoveTimer:
		strWipeEventType = L"CleanAndRemoveTimer";
		break;
	case EPIWipeEventType::PIWipeEventTypeDispense:
		strWipeEventType = L"Dispense";
		break;
	case EPIWipeEventType::PIWipeEventTypeIdle:
		strWipeEventType = L"Idle";
		break;
	case EPIWipeEventType::PIWipeEventTypeInspFail:
		strWipeEventType = L"InspFail";
		break;
	case EPIWipeEventType::PIWipeEventTypeKnead:
		strWipeEventType = L"Knead";
		break;
	case EPIWipeEventType::PIWipeEventTypeLast:
		strWipeEventType = L"Last";
		break;
	case EPIWipeEventType::PIWipeEventTypeManualCleanTimer:
		strWipeEventType = L"ManualCleanTimer";
		break;
	case EPIWipeEventType::PIWipeEventTypeStencilInspFail:
		strWipeEventType = L"StencilInspFail";
		break;
	case EPIWipeEventType::PIWipeEventTypeUndefined:
		strWipeEventType = L"Undefined";
		break;
	case EPIWipeEventType::PIWipeEventTypeUserDef:
		strWipeEventType = L"UserDef";
		break;
	case EPIWipeEventType::PIWipeEventTypeWipeNowManualClean:
		strWipeEventType = L"WipeNowManualClean";
		break;
	case EPIWipeEventType::PIWipeEventTypeWipeNowManualRemove:
		strWipeEventType = L"WipeNowManualRemove";
		break;
	case EPIWipeEventType::PIWipeEventTypeWipeTest:
		strWipeEventType = L"WipeTest";
		break;
	default:
		break;
	}


	// strTemp.Append(L"[");
	for (int i = 0; i < sNumSegments; i++)
	{
		switch (eStrokeType[i])
		{
		case ePIWipeStrokeTypeDryR2F:
			strStrokeType.Append(L"DRY-R2F ");
			break;
		case ePIWipeStrokeTypeDryF2R:
			strStrokeType.Append(L"DRY-F2R ");
			break;
		case ePIWipeStrokeTypeSolventR2F:
			strStrokeType.Append(L"SOLVENT-R2F ");
			break;
		case ePIWipeStrokeTypeSolventF2R:
			strStrokeType.Append(L"SOLVENT-F2R ");
			break;
		case ePIWipeStrokeTypeVacuumR2F:
			strStrokeType.Append(L"VACUUM-R2F ");
			break;
		case ePIWipeStrokeTypeVacuumF2R:
			strStrokeType.Append(L"VACUUM-R2F ");
			break;
		case ePIWipeStrokeTypeVacuumSolventF2R:
			strStrokeType.Append(L"SOLVENT-F2R ");
			break;
		case ePIWipeStrokeTypeVacuumSolventR2F:
			strStrokeType.Append(L"SOLVENT-R2F ");
			break;
		case ePIWipeStrokeTypeLast:
		default:
			strStrokeType.Append(L"UNKNOWN");
			break;
		}
	}
	strStrokeType.Delete(strStrokeType.GetLength() - 1);
	// strTemp.Append(L"]");

	strDate = getTimeStamp(i64Timestamp);

	CString data;
	data.Format(_T("%s,%s,%s,%s,%d,%s\n"), (LPCWSTR)strDate, usProfileName, (LPCWSTR)strPaperFeedMode, (LPCWSTR)strWipeEventType, sWipeFrequency, (LPCWSTR)strStrokeType);
	saveToFile(L"wipe", i64Timestamp, L"TimeStamp,ProfileName,PaperFeedMode,WipeEventType,WipeFequency,StrokeType\n", data);

	text.Format(_T("Wipe Started : TimeStamp=%s  Profilename=%s  PapedFeedMode=%d  WipeEventType=%d  WipeFrequency=%d  StrokeType=%s\r\n"), (LPCWSTR)strDate, usProfileName, ePaperFeedMode, eWipeEventType, sWipeFrequency, (LPCWSTR)strStrokeType);
	UpdateCEdit(text);
}

///////////////////////////////////////////////////////////////////////////////
//  Board Interface methods
///////////////////////////////////////////////////////////////////////////////
void RpcPIBoardAccepted(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, long lBoardId) { OutputDebugStringW(L"RpcPIBoardAccepted\n"); }
void RpcPIBoardBarcodeNotification(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, EPIBarcodeSource eBarcodeSource, short sBarcodeLen, unsigned short usBarcode[]) { UpdateCEdit(L"Board Scanned : %s"); }
void RpcPIBoardClamped(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, long lBoardId) { OutputDebugStringW(L"RpcPIBoardClamped\n"); }
void RpcPIBoardPrinted(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, long lBoardNumber, short sBarcodeLen, unsigned short usBarcode[], boolean bInitStrokeF2R, short sNumStrokes, EPIProcessedStatus eProcessedStatus, long lPackagedDataLength, byte packagedData[]) 
{ 
	wchar_t* sResult = new TCHAR[80];
	CString strDate;

	strDate = getTimeStamp(i64Timestamp);

	switch (eProcessedStatus)
	{
	case EPIProcessedStatus::ePIProcessedStatusAOK:
		sResult = L"OK";
		break;
	case EPIProcessedStatus::ePIProcessedStatusError:
		sResult = L"ERROR";
		break;
	case EPIProcessedStatus::ePIProcessedStatusLast:
		sResult = L"LAST";
		break;
	default:
		sResult = L"UNKNOWN";
		break;
	}

	CString data;
	data.Format(_T("%s,%d,%s,%d,%s"), (LPCWSTR)strDate, lBoardNumber, usBarcode, sNumStrokes, sResult);
	saveToFile(L"board", i64Timestamp, L"TimeStamp,BoardNumber,BarCode,NumStrokes,Status\n", data);

	text.Format(L"Board Printed : TimeStamp=%s  BoardNumber=%d  BarCode=%s  NumStrokes=%d  Status=%s \r\n", (LPCWSTR)strDate, lBoardNumber, usBarcode, sNumStrokes, sResult);
	UpdateCEdit(text); 
}
void RpcPIBoardProcgCompleted(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, long lBoardId, long lBoardCount) {}
void RpcPIBoardProcgStarted(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, long lBoardId) {}
void RpcPIBoardRejected(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, long lBoardId) {}
void RpcPIBoardUnclamped(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, long lBoardId) {}
void RpcPIClearQueue(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp) {}
void RpcPIPostPanelData(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, long lBoardId, short sNumPanels, short sPanelIdList[], unsigned short usBarcodeList[][BENCHMARK_PII_MAX_BARCODE_LEN]) {}
void RpcPIPostPasteHeightData(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, long lBoardId, double dPasteHeightMinMm, double dPasteHeightMeasuredMm)
{
	CString strDate;

	strDate = getTimeStamp(i64Timestamp);

	text.Format(_T("Paste Height Data :  TimeStamp=%s  BoardId=%d  PasteHeightMinMm=%f  PasteHeightMeasuredMm=%f \r\n"), (LPCWSTR)strDate, lBoardId, dPasteHeightMinMm, dPasteHeightMeasuredMm);
	UpdateCEdit(text);
}
void RpcPIPostPasteHeightDataEx(PCONTEXT_HDL_TYPE phContext, hyper i64Timestamp, long lBoardId, double dPasteHeightMinMm, double dPasteHeightMaxMm, double dPasteHeightMeasuredMm)
{
	CString strDate;

	strDate = getTimeStamp(i64Timestamp);

	CString data;
	data.Format(_T("%s,%d,%f,%f,%f\n"), (LPCWSTR)strDate, lBoardId, dPasteHeightMinMm, dPasteHeightMaxMm, dPasteHeightMeasuredMm);
	saveToFile(L"pasteheight", i64Timestamp, L"TimeStamp,BoardNumber,PasteHeightMinMm,PasteHeightMaxMm,PasteHeightMeasuredMm\n", data);

	text.Format(_T("Paste Height Data :  TimeStamp=%s BoardId=%d  PasteHeightMinMm=%f  PasteHeightMaxMm=%f  PasteHeightMeasuredMm=%f \r\n"), (LPCWSTR)strDate, lBoardId, dPasteHeightMinMm, dPasteHeightMaxMm, dPasteHeightMeasuredMm);
	UpdateCEdit(text);
}

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
