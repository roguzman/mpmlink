

/* this ALWAYS GENERATED file contains the RPC server stubs */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Wed Jun 06 13:58:06 2018
 */
/* Compiler settings for PICliMessageIF.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#include <string.h>
#include "PICliMessageIF.h"

#define TYPE_FORMAT_STRING_SIZE   19                                
#define PROC_FORMAT_STRING_SIZE   55                                
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _PICliMessageIF_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } PICliMessageIF_MIDL_TYPE_FORMAT_STRING;

typedef struct _PICliMessageIF_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } PICliMessageIF_MIDL_PROC_FORMAT_STRING;

typedef struct _PICliMessageIF_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } PICliMessageIF_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};

extern const PICliMessageIF_MIDL_TYPE_FORMAT_STRING PICliMessageIF__MIDL_TypeFormatString;
extern const PICliMessageIF_MIDL_PROC_FORMAT_STRING PICliMessageIF__MIDL_ProcFormatString;
extern const PICliMessageIF_MIDL_EXPR_FORMAT_STRING PICliMessageIF__MIDL_ExprFormatString;

/* Standard interface: PICliMessageInterface, ver. 1.0,
   GUID={0x16289bda,0x208d,0x4dd6,{0xb1,0xcb,0xd1,0xc9,0xf4,0x73,0x23,0x4e}} */


extern const MIDL_SERVER_INFO PICliMessageInterface_ServerInfo;

extern const RPC_DISPATCH_TABLE PICliMessageInterface_v1_0_DispatchTable;

static const RPC_SERVER_INTERFACE PICliMessageInterface___RpcServerInterface =
    {
    sizeof(RPC_SERVER_INTERFACE),
    {{0x16289bda,0x208d,0x4dd6,{0xb1,0xcb,0xd1,0xc9,0xf4,0x73,0x23,0x4e}},{1,0}},
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    (RPC_DISPATCH_TABLE*)&PICliMessageInterface_v1_0_DispatchTable,
    0,
    0,
    0,
    &PICliMessageInterface_ServerInfo,
    0x04000000
    };
RPC_IF_HANDLE PICliMessageInterface_v1_0_s_ifspec = (RPC_IF_HANDLE)& PICliMessageInterface___RpcServerInterface;

extern const MIDL_STUB_DESC PICliMessageInterface_StubDesc;

extern const NDR_RUNDOWN RundownRoutines[];

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const PICliMessageIF_MIDL_PROC_FORMAT_STRING PICliMessageIF__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure RpcPIPostMessage */

			0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x0 ),	/* 0 */
/*  8 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 10 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 12 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 14 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 16 */	NdrFcShort( 0x3a ),	/* 58 */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	0x42,		/* Oi2 Flags:  clt must size, has ext, */
			0x4,		/* 4 */
/* 22 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */
/* 26 */	NdrFcShort( 0x1 ),	/* 1 */
/* 28 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phContext */

/* 30 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 32 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 34 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter i64Timestamp */

/* 36 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 38 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 40 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter sMessageLen */

/* 42 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 44 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 46 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter usMessage */

/* 48 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 50 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 52 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

			0x0
        }
    };

static const PICliMessageIF_MIDL_TYPE_FORMAT_STRING PICliMessageIF__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	0x30,		/* FC_BIND_CONTEXT */
			0x41,		/* Ctxt flags:  in, can't be null */
/*  4 */	0x0,		/* 0 */
			0x0,		/* 0 */
/*  6 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/*  8 */	NdrFcShort( 0x2 ),	/* 2 */
/* 10 */	0x26,		/* Corr desc:  parameter, FC_SHORT */
			0x0,		/*  */
/* 12 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 14 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 16 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */

			0x0
        }
    };

static const NDR_RUNDOWN RundownRoutines[] = 
    {
    PCONTEXT_HDL_TYPE_rundown
    };


static const unsigned short PICliMessageInterface_FormatStringOffsetTable[] =
    {
    0
    };


static const MIDL_STUB_DESC PICliMessageInterface_StubDesc = 
    {
    (void *)& PICliMessageInterface___RpcServerInterface,
    MIDL_user_allocate,
    MIDL_user_free,
    0,
    RundownRoutines,
    0,
    0,
    0,
    PICliMessageIF__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x700022b, /* MIDL Version 7.0.555 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

static const RPC_DISPATCH_FUNCTION PICliMessageInterface_table[] =
    {
    NdrServerCall2,
    0
    };
static const RPC_DISPATCH_TABLE PICliMessageInterface_v1_0_DispatchTable = 
    {
    1,
    (RPC_DISPATCH_FUNCTION*)PICliMessageInterface_table
    };

static const SERVER_ROUTINE PICliMessageInterface_ServerRoutineTable[] = 
    {
    (SERVER_ROUTINE)RpcPIPostMessage
    };

static const MIDL_SERVER_INFO PICliMessageInterface_ServerInfo = 
    {
    &PICliMessageInterface_StubDesc,
    PICliMessageInterface_ServerRoutineTable,
    PICliMessageIF__MIDL_ProcFormatString.Format,
    PICliMessageInterface_FormatStringOffsetTable,
    0,
    0,
    0,
    0};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

