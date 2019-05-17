

/* this ALWAYS GENERATED file contains the RPC server stubs */


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
#include "PICliStateIF.h"

#define TYPE_FORMAT_STRING_SIZE   103                               
#define PROC_FORMAT_STRING_SIZE   1285                              
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _PICliStateIF_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } PICliStateIF_MIDL_TYPE_FORMAT_STRING;

typedef struct _PICliStateIF_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } PICliStateIF_MIDL_PROC_FORMAT_STRING;

typedef struct _PICliStateIF_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } PICliStateIF_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};

extern const PICliStateIF_MIDL_TYPE_FORMAT_STRING PICliStateIF__MIDL_TypeFormatString;
extern const PICliStateIF_MIDL_PROC_FORMAT_STRING PICliStateIF__MIDL_ProcFormatString;
extern const PICliStateIF_MIDL_EXPR_FORMAT_STRING PICliStateIF__MIDL_ExprFormatString;

/* Standard interface: PICliStateInterface, ver. 1.0,
   GUID={0xbd2bc8ba,0x4b62,0x4e88,{0xac,0x29,0x02,0x10,0x59,0x5e,0xcd,0xfb}} */


extern const MIDL_SERVER_INFO PICliStateInterface_ServerInfo;

extern const RPC_DISPATCH_TABLE PICliStateInterface_v1_0_DispatchTable;

static const RPC_SERVER_INTERFACE PICliStateInterface___RpcServerInterface =
    {
    sizeof(RPC_SERVER_INTERFACE),
    {{0xbd2bc8ba,0x4b62,0x4e88,{0xac,0x29,0x02,0x10,0x59,0x5e,0xcd,0xfb}},{1,0}},
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    (RPC_DISPATCH_TABLE*)&PICliStateInterface_v1_0_DispatchTable,
    0,
    0,
    0,
    &PICliStateInterface_ServerInfo,
    0x04000000
    };
RPC_IF_HANDLE PICliStateInterface_v1_0_s_ifspec = (RPC_IF_HANDLE)& PICliStateInterface___RpcServerInterface;

extern const MIDL_STUB_DESC PICliStateInterface_StubDesc;

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


static const PICliStateIF_MIDL_PROC_FORMAT_STRING PICliStateIF__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure RpcPIMachineStateChange */

			0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x0 ),	/* 0 */
/*  8 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 10 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 12 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 14 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 16 */	NdrFcShort( 0x3a ),	/* 58 */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	0x40,		/* Oi2 Flags:  has ext, */
			0x3,		/* 3 */
/* 22 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */
/* 26 */	NdrFcShort( 0x0 ),	/* 0 */
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

	/* Parameter eNewState */

/* 42 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 44 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 46 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Procedure RpcPIWipeStarted */

/* 48 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 50 */	NdrFcLong( 0x0 ),	/* 0 */
/* 54 */	NdrFcShort( 0x1 ),	/* 1 */
/* 56 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 58 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 60 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 62 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 64 */	NdrFcShort( 0x3a ),	/* 58 */
/* 66 */	NdrFcShort( 0x0 ),	/* 0 */
/* 68 */	0x42,		/* Oi2 Flags:  clt must size, has ext, */
			0x4,		/* 4 */
/* 70 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 72 */	NdrFcShort( 0x0 ),	/* 0 */
/* 74 */	NdrFcShort( 0x1 ),	/* 1 */
/* 76 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phContext */

/* 78 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 80 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 82 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter i64Timestamp */

/* 84 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 86 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 88 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter sProfileNameLen */

/* 90 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 92 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 94 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter usProfileName */

/* 96 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 98 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 100 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Procedure RpcPIWipeComplete */

/* 102 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 104 */	NdrFcLong( 0x0 ),	/* 0 */
/* 108 */	NdrFcShort( 0x2 ),	/* 2 */
/* 110 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 112 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 114 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 116 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 118 */	NdrFcShort( 0x34 ),	/* 52 */
/* 120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 122 */	0x40,		/* Oi2 Flags:  has ext, */
			0x2,		/* 2 */
/* 124 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 130 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phContext */

/* 132 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 134 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 136 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter i64Timestamp */

/* 138 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 140 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 142 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Procedure RpcPIManualStencilCleanStarted */

/* 144 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 146 */	NdrFcLong( 0x0 ),	/* 0 */
/* 150 */	NdrFcShort( 0x3 ),	/* 3 */
/* 152 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 154 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 156 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 158 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 160 */	NdrFcShort( 0x34 ),	/* 52 */
/* 162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 164 */	0x40,		/* Oi2 Flags:  has ext, */
			0x2,		/* 2 */
/* 166 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 172 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phContext */

/* 174 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 176 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 178 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter i64Timestamp */

/* 180 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 182 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 184 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Procedure RpcPIManualStencilCleanComplete */

/* 186 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 188 */	NdrFcLong( 0x0 ),	/* 0 */
/* 192 */	NdrFcShort( 0x4 ),	/* 4 */
/* 194 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 196 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 198 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 200 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 202 */	NdrFcShort( 0x34 ),	/* 52 */
/* 204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 206 */	0x40,		/* Oi2 Flags:  has ext, */
			0x2,		/* 2 */
/* 208 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 214 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phContext */

/* 216 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 218 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 220 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter i64Timestamp */

/* 222 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 224 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 226 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Procedure RpcPIDispenseStarted */

/* 228 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 230 */	NdrFcLong( 0x0 ),	/* 0 */
/* 234 */	NdrFcShort( 0x5 ),	/* 5 */
/* 236 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 238 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 240 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 242 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 244 */	NdrFcShort( 0x3a ),	/* 58 */
/* 246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 248 */	0x42,		/* Oi2 Flags:  clt must size, has ext, */
			0x4,		/* 4 */
/* 250 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 254 */	NdrFcShort( 0x1 ),	/* 1 */
/* 256 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phContext */

/* 258 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 260 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 262 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter i64Timestamp */

/* 264 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 266 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 268 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter sProfileNameLen */

/* 270 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 272 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 274 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter usProfileName */

/* 276 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 278 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 280 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Procedure RpcPIDispenseComplete */

/* 282 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 284 */	NdrFcLong( 0x0 ),	/* 0 */
/* 288 */	NdrFcShort( 0x6 ),	/* 6 */
/* 290 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 292 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 294 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 296 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 298 */	NdrFcShort( 0x34 ),	/* 52 */
/* 300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 302 */	0x40,		/* Oi2 Flags:  has ext, */
			0x2,		/* 2 */
/* 304 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 310 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phContext */

/* 312 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 314 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 316 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter i64Timestamp */

/* 318 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 320 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 322 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Procedure RpcPIManualAddPasteStarted */

/* 324 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 326 */	NdrFcLong( 0x0 ),	/* 0 */
/* 330 */	NdrFcShort( 0x7 ),	/* 7 */
/* 332 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 334 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 336 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 338 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 340 */	NdrFcShort( 0x34 ),	/* 52 */
/* 342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 344 */	0x40,		/* Oi2 Flags:  has ext, */
			0x2,		/* 2 */
/* 346 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 352 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phContext */

/* 354 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 356 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 358 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter i64Timestamp */

/* 360 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 362 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 364 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Procedure RpcPIManualAddPasteComplete */

/* 366 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 368 */	NdrFcLong( 0x0 ),	/* 0 */
/* 372 */	NdrFcShort( 0x8 ),	/* 8 */
/* 374 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 376 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 378 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 380 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 382 */	NdrFcShort( 0x34 ),	/* 52 */
/* 384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 386 */	0x40,		/* Oi2 Flags:  has ext, */
			0x2,		/* 2 */
/* 388 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 390 */	NdrFcShort( 0x0 ),	/* 0 */
/* 392 */	NdrFcShort( 0x0 ),	/* 0 */
/* 394 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phContext */

/* 396 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 398 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 400 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter i64Timestamp */

/* 402 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 404 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 406 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Procedure RpcPIChangePasteStarted */

/* 408 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 410 */	NdrFcLong( 0x0 ),	/* 0 */
/* 414 */	NdrFcShort( 0x9 ),	/* 9 */
/* 416 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 418 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 420 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 422 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 424 */	NdrFcShort( 0x34 ),	/* 52 */
/* 426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 428 */	0x40,		/* Oi2 Flags:  has ext, */
			0x2,		/* 2 */
/* 430 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 432 */	NdrFcShort( 0x0 ),	/* 0 */
/* 434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 436 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phContext */

/* 438 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 440 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 442 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter i64Timestamp */

/* 444 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 446 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 448 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Procedure RpcPIChangePasteComplete */

/* 450 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 452 */	NdrFcLong( 0x0 ),	/* 0 */
/* 456 */	NdrFcShort( 0xa ),	/* 10 */
/* 458 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 460 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 462 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 464 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 466 */	NdrFcShort( 0x34 ),	/* 52 */
/* 468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 470 */	0x40,		/* Oi2 Flags:  has ext, */
			0x2,		/* 2 */
/* 472 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 474 */	NdrFcShort( 0x0 ),	/* 0 */
/* 476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 478 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phContext */

/* 480 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 482 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 484 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter i64Timestamp */

/* 486 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 488 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 490 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Procedure RpcPIStencilRemoved */

/* 492 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 494 */	NdrFcLong( 0x0 ),	/* 0 */
/* 498 */	NdrFcShort( 0xb ),	/* 11 */
/* 500 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 502 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 504 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 506 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 508 */	NdrFcShort( 0x34 ),	/* 52 */
/* 510 */	NdrFcShort( 0x0 ),	/* 0 */
/* 512 */	0x40,		/* Oi2 Flags:  has ext, */
			0x2,		/* 2 */
/* 514 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 516 */	NdrFcShort( 0x0 ),	/* 0 */
/* 518 */	NdrFcShort( 0x0 ),	/* 0 */
/* 520 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phContext */

/* 522 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 524 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 526 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter i64Timestamp */

/* 528 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 530 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 532 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Procedure RpcPIStencilInserted */

/* 534 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 536 */	NdrFcLong( 0x0 ),	/* 0 */
/* 540 */	NdrFcShort( 0xc ),	/* 12 */
/* 542 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 544 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 546 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 548 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 550 */	NdrFcShort( 0x34 ),	/* 52 */
/* 552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 554 */	0x40,		/* Oi2 Flags:  has ext, */
			0x2,		/* 2 */
/* 556 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 558 */	NdrFcShort( 0x0 ),	/* 0 */
/* 560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 562 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phContext */

/* 564 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 566 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 568 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter i64Timestamp */

/* 570 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 572 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 574 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Procedure RpcPIPrintStrokeStarted */

/* 576 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 578 */	NdrFcLong( 0x0 ),	/* 0 */
/* 582 */	NdrFcShort( 0xd ),	/* 13 */
/* 584 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 586 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 588 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 590 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 592 */	NdrFcShort( 0x3f ),	/* 63 */
/* 594 */	NdrFcShort( 0x0 ),	/* 0 */
/* 596 */	0x40,		/* Oi2 Flags:  has ext, */
			0x4,		/* 4 */
/* 598 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 604 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phContext */

/* 606 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 608 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 610 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter i64Timestamp */

/* 612 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 614 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 616 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter bIsFrontToRear */

/* 618 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 620 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 622 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Parameter sStrokeNumber */

/* 624 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 626 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 628 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Procedure RpcPIPrintStrokeEnded */

/* 630 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 632 */	NdrFcLong( 0x0 ),	/* 0 */
/* 636 */	NdrFcShort( 0xe ),	/* 14 */
/* 638 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 640 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 642 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 644 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 646 */	NdrFcShort( 0x34 ),	/* 52 */
/* 648 */	NdrFcShort( 0x0 ),	/* 0 */
/* 650 */	0x40,		/* Oi2 Flags:  has ext, */
			0x2,		/* 2 */
/* 652 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 654 */	NdrFcShort( 0x0 ),	/* 0 */
/* 656 */	NdrFcShort( 0x0 ),	/* 0 */
/* 658 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phContext */

/* 660 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 662 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 664 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter i64Timestamp */

/* 666 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 668 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 670 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Procedure RpcPIKneadNotification */

/* 672 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 674 */	NdrFcLong( 0x0 ),	/* 0 */
/* 678 */	NdrFcShort( 0xf ),	/* 15 */
/* 680 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 682 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 684 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 686 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 688 */	NdrFcShort( 0x3c ),	/* 60 */
/* 690 */	NdrFcShort( 0x0 ),	/* 0 */
/* 692 */	0x40,		/* Oi2 Flags:  has ext, */
			0x3,		/* 3 */
/* 694 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 700 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phContext */

/* 702 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 704 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 706 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter i64Timestamp */

/* 708 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 710 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 712 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter lBoardId */

/* 714 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 716 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 718 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RpcPIWipeRequested */

/* 720 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 722 */	NdrFcLong( 0x0 ),	/* 0 */
/* 726 */	NdrFcShort( 0x10 ),	/* 16 */
/* 728 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 730 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 732 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 734 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 736 */	NdrFcShort( 0x3f ),	/* 63 */
/* 738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 740 */	0x42,		/* Oi2 Flags:  clt must size, has ext, */
			0x5,		/* 5 */
/* 742 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 746 */	NdrFcShort( 0x1 ),	/* 1 */
/* 748 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phContext */

/* 750 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 752 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 754 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter i64Timestamp */

/* 756 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 758 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 760 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter bIsRequesting */

/* 762 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 764 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 766 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Parameter sRequesterNameLen */

/* 768 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 770 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 772 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter usRequesterName */

/* 774 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 776 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 778 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Procedure RpcPISnapoffStarted */

/* 780 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 782 */	NdrFcLong( 0x0 ),	/* 0 */
/* 786 */	NdrFcShort( 0x11 ),	/* 17 */
/* 788 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 790 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 792 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 794 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 796 */	NdrFcShort( 0x40 ),	/* 64 */
/* 798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 800 */	0x42,		/* Oi2 Flags:  clt must size, has ext, */
			0xa,		/* 10 */
/* 802 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 804 */	NdrFcShort( 0x0 ),	/* 0 */
/* 806 */	NdrFcShort( 0x1 ),	/* 1 */
/* 808 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phContext */

/* 810 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 812 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 814 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter i64Timestamp */

/* 816 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 818 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 820 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter sProfileNameLen */

/* 822 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 824 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 826 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter usProfileName */

/* 828 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 830 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 832 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Parameter sNumSnapffSegments */

/* 834 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 836 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 838 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pSegmentMoveType */

/* 840 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 842 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 844 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Parameter pdSegmentDistanceMm */

/* 846 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 848 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 850 */	NdrFcShort( 0x30 ),	/* Type Offset=48 */

	/* Parameter pdSegmentSpeedMmPerSec */

/* 852 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 854 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 856 */	NdrFcShort( 0x30 ),	/* Type Offset=48 */

	/* Parameter pdSegmentStepSizeMm */

/* 858 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 860 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 862 */	NdrFcShort( 0x30 ),	/* Type Offset=48 */

	/* Parameter pdSegmentStepDelayMilliSecs */

/* 864 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 866 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 868 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Procedure RpcPIWipeStartedWithData */

/* 870 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 872 */	NdrFcLong( 0x0 ),	/* 0 */
/* 876 */	NdrFcShort( 0x12 ),	/* 18 */
/* 878 */	NdrFcShort( 0x40 ),	/* x86 Stack size/offset = 64 */
/* 880 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 882 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 884 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 886 */	NdrFcShort( 0x72 ),	/* 114 */
/* 888 */	NdrFcShort( 0x0 ),	/* 0 */
/* 890 */	0x42,		/* Oi2 Flags:  clt must size, has ext, */
			0xd,		/* 13 */
/* 892 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 894 */	NdrFcShort( 0x0 ),	/* 0 */
/* 896 */	NdrFcShort( 0x1 ),	/* 1 */
/* 898 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phContext */

/* 900 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 902 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 904 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter i64Timestamp */

/* 906 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 908 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 910 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter sProfileNameLen */

/* 912 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 914 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 916 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter usProfileName */

/* 918 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 920 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 922 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Parameter dHopOver */

/* 924 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 926 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 928 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter dTravelOffset */

/* 930 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 932 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 934 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter ePaperFeedMode */

/* 936 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 938 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 940 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter eWipeEventType */

/* 942 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 944 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 946 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter sWipeFrequency */

/* 948 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 950 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 952 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter sNumSegments */

/* 954 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 956 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 958 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter dSegmentIndexDistanceMm */

/* 960 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 962 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 964 */	NdrFcShort( 0x48 ),	/* Type Offset=72 */

	/* Parameter dSegmentSpeedMmPerSec */

/* 966 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 968 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 970 */	NdrFcShort( 0x48 ),	/* Type Offset=72 */

	/* Parameter eStrokeType */

/* 972 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 974 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 976 */	NdrFcShort( 0x54 ),	/* Type Offset=84 */

	/* Procedure RpcPIProcessModeChange */

/* 978 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 980 */	NdrFcLong( 0x0 ),	/* 0 */
/* 984 */	NdrFcShort( 0x13 ),	/* 19 */
/* 986 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 988 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 990 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 992 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 994 */	NdrFcShort( 0x3a ),	/* 58 */
/* 996 */	NdrFcShort( 0x0 ),	/* 0 */
/* 998 */	0x40,		/* Oi2 Flags:  has ext, */
			0x3,		/* 3 */
/* 1000 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1002 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1006 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phContext */

/* 1008 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1010 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1012 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter i64Timestamp */

/* 1014 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1016 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1018 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter eNewProcessMode */

/* 1020 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1022 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1024 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Procedure RpcPIDiagnosticsModeStarted */

/* 1026 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1028 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1032 */	NdrFcShort( 0x14 ),	/* 20 */
/* 1034 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1036 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1038 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1040 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1042 */	NdrFcShort( 0x34 ),	/* 52 */
/* 1044 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1046 */	0x40,		/* Oi2 Flags:  has ext, */
			0x2,		/* 2 */
/* 1048 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1050 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1052 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1054 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phContext */

/* 1056 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1058 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1060 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter i64Timestamp */

/* 1062 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1064 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1066 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Procedure RpcPIDiagnosticsModeEnded */

/* 1068 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1070 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1074 */	NdrFcShort( 0x15 ),	/* 21 */
/* 1076 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1078 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1080 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1082 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1084 */	NdrFcShort( 0x34 ),	/* 52 */
/* 1086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1088 */	0x40,		/* Oi2 Flags:  has ext, */
			0x2,		/* 2 */
/* 1090 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1092 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1096 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phContext */

/* 1098 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1100 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1102 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter i64Timestamp */

/* 1104 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1106 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1108 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Procedure RpcPIChangeoverStarted */

/* 1110 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1112 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1116 */	NdrFcShort( 0x16 ),	/* 22 */
/* 1118 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1120 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1122 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1124 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1126 */	NdrFcShort( 0x34 ),	/* 52 */
/* 1128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1130 */	0x40,		/* Oi2 Flags:  has ext, */
			0x2,		/* 2 */
/* 1132 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1138 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phContext */

/* 1140 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1142 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1144 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter i64Timestamp */

/* 1146 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1148 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1150 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Procedure RpcPIChangeoverEnded */

/* 1152 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1154 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1158 */	NdrFcShort( 0x17 ),	/* 23 */
/* 1160 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1162 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1164 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1166 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1168 */	NdrFcShort( 0x39 ),	/* 57 */
/* 1170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1172 */	0x40,		/* Oi2 Flags:  has ext, */
			0x3,		/* 3 */
/* 1174 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1180 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phContext */

/* 1182 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1184 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1186 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter i64Timestamp */

/* 1188 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1190 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1192 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter bUserCancelled */

/* 1194 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1196 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1198 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Procedure RpcPIManualReducePasteStarted */

/* 1200 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1202 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1206 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1208 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1210 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1212 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1214 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1216 */	NdrFcShort( 0x34 ),	/* 52 */
/* 1218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1220 */	0x40,		/* Oi2 Flags:  has ext, */
			0x2,		/* 2 */
/* 1222 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1228 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phContext */

/* 1230 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1232 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1234 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter i64Timestamp */

/* 1236 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1238 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1240 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Procedure RpcPIManualReducePasteComplete */

/* 1242 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1244 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1248 */	NdrFcShort( 0x19 ),	/* 25 */
/* 1250 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1252 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1254 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1256 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1258 */	NdrFcShort( 0x34 ),	/* 52 */
/* 1260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1262 */	0x40,		/* Oi2 Flags:  has ext, */
			0x2,		/* 2 */
/* 1264 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1266 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1270 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phContext */

/* 1272 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1274 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1276 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter i64Timestamp */

/* 1278 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1280 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1282 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

			0x0
        }
    };

static const PICliStateIF_MIDL_TYPE_FORMAT_STRING PICliStateIF__MIDL_TypeFormatString =
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
/* 18 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 20 */	NdrFcShort( 0x2 ),	/* 2 */
/* 22 */	0x26,		/* Corr desc:  parameter, FC_SHORT */
			0x0,		/*  */
/* 24 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 26 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 28 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 30 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x1,		/* 1 */
/* 32 */	NdrFcShort( 0x0 ),	/* 0 */
/* 34 */	0x26,		/* Corr desc:  parameter, FC_SHORT */
			0x0,		/*  */
/* 36 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 38 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 40 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 44 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 46 */	0xd,		/* FC_ENUM16 */
			0x5b,		/* FC_END */
/* 48 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 50 */	NdrFcShort( 0x8 ),	/* 8 */
/* 52 */	0x26,		/* Corr desc:  parameter, FC_SHORT */
			0x0,		/*  */
/* 54 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 56 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 58 */	0xc,		/* FC_DOUBLE */
			0x5b,		/* FC_END */
/* 60 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 62 */	NdrFcShort( 0x4 ),	/* 4 */
/* 64 */	0x26,		/* Corr desc:  parameter, FC_SHORT */
			0x0,		/*  */
/* 66 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 68 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 70 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 72 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 74 */	NdrFcShort( 0x8 ),	/* 8 */
/* 76 */	0x26,		/* Corr desc:  parameter, FC_SHORT */
			0x0,		/*  */
/* 78 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 80 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 82 */	0xc,		/* FC_DOUBLE */
			0x5b,		/* FC_END */
/* 84 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x1,		/* 1 */
/* 86 */	NdrFcShort( 0x0 ),	/* 0 */
/* 88 */	0x26,		/* Corr desc:  parameter, FC_SHORT */
			0x0,		/*  */
/* 90 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 92 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 94 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 98 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 100 */	0xd,		/* FC_ENUM16 */
			0x5b,		/* FC_END */

			0x0
        }
    };

static const NDR_RUNDOWN RundownRoutines[] = 
    {
    PCONTEXT_HDL_TYPE_rundown
    };


static const unsigned short PICliStateInterface_FormatStringOffsetTable[] =
    {
    0,
    48,
    102,
    144,
    186,
    228,
    282,
    324,
    366,
    408,
    450,
    492,
    534,
    576,
    630,
    672,
    720,
    780,
    870,
    978,
    1026,
    1068,
    1110,
    1152,
    1200,
    1242
    };


static const MIDL_STUB_DESC PICliStateInterface_StubDesc = 
    {
    (void *)& PICliStateInterface___RpcServerInterface,
    MIDL_user_allocate,
    MIDL_user_free,
    0,
    RundownRoutines,
    0,
    0,
    0,
    PICliStateIF__MIDL_TypeFormatString.Format,
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

static const RPC_DISPATCH_FUNCTION PICliStateInterface_table[] =
    {
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    0
    };
static const RPC_DISPATCH_TABLE PICliStateInterface_v1_0_DispatchTable = 
    {
    26,
    (RPC_DISPATCH_FUNCTION*)PICliStateInterface_table
    };

static const SERVER_ROUTINE PICliStateInterface_ServerRoutineTable[] = 
    {
    (SERVER_ROUTINE)RpcPIMachineStateChange,
    (SERVER_ROUTINE)RpcPIWipeStarted,
    (SERVER_ROUTINE)RpcPIWipeComplete,
    (SERVER_ROUTINE)RpcPIManualStencilCleanStarted,
    (SERVER_ROUTINE)RpcPIManualStencilCleanComplete,
    (SERVER_ROUTINE)RpcPIDispenseStarted,
    (SERVER_ROUTINE)RpcPIDispenseComplete,
    (SERVER_ROUTINE)RpcPIManualAddPasteStarted,
    (SERVER_ROUTINE)RpcPIManualAddPasteComplete,
    (SERVER_ROUTINE)RpcPIChangePasteStarted,
    (SERVER_ROUTINE)RpcPIChangePasteComplete,
    (SERVER_ROUTINE)RpcPIStencilRemoved,
    (SERVER_ROUTINE)RpcPIStencilInserted,
    (SERVER_ROUTINE)RpcPIPrintStrokeStarted,
    (SERVER_ROUTINE)RpcPIPrintStrokeEnded,
    (SERVER_ROUTINE)RpcPIKneadNotification,
    (SERVER_ROUTINE)RpcPIWipeRequested,
    (SERVER_ROUTINE)RpcPISnapoffStarted,
    (SERVER_ROUTINE)RpcPIWipeStartedWithData,
    (SERVER_ROUTINE)RpcPIProcessModeChange,
    (SERVER_ROUTINE)RpcPIDiagnosticsModeStarted,
    (SERVER_ROUTINE)RpcPIDiagnosticsModeEnded,
    (SERVER_ROUTINE)RpcPIChangeoverStarted,
    (SERVER_ROUTINE)RpcPIChangeoverEnded,
    (SERVER_ROUTINE)RpcPIManualReducePasteStarted,
    (SERVER_ROUTINE)RpcPIManualReducePasteComplete
    };

static const MIDL_SERVER_INFO PICliStateInterface_ServerInfo = 
    {
    &PICliStateInterface_StubDesc,
    PICliStateInterface_ServerRoutineTable,
    PICliStateIF__MIDL_ProcFormatString.Format,
    PICliStateInterface_FormatStringOffsetTable,
    0,
    0,
    0,
    0};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

