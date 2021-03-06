

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Wed Feb 12 22:36:08 2014
 */
/* Compiler settings for PPHT_Helper_C.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_PPHT_Helper_C,0x74BDDAB6,0x04B3,0x40F7,0x8D,0xED,0xAD,0x92,0xE5,0x4F,0x1B,0x46);


MIDL_DEFINE_GUID(IID, DIID_IConvertHelper,0xBC39A831,0xE868,0x48B6,0xAC,0xD3,0x4C,0xB0,0x34,0x1B,0x53,0x1F);


MIDL_DEFINE_GUID(CLSID, CLSID_ConvertHelper,0x8B462A43,0x4FC8,0x493C,0x9E,0x11,0x41,0xCE,0x8B,0x2A,0x81,0xAB);


MIDL_DEFINE_GUID(IID, DIID_IColorHelper,0x125E83E6,0xE1D4,0x4021,0x92,0xE5,0x99,0xEC,0x29,0x75,0xEF,0x4D);


MIDL_DEFINE_GUID(CLSID, CLSID_ColorHelper,0x4F3E8376,0x2863,0x461C,0x8A,0x02,0x31,0x9A,0x19,0x8A,0xBB,0xB8);


MIDL_DEFINE_GUID(IID, DIID_IControlHelper,0x9C3DC0C5,0x927B,0x400E,0x81,0xEC,0x2A,0x7B,0xFA,0xB0,0x2B,0x62);


MIDL_DEFINE_GUID(CLSID, CLSID_ControlHelper,0xD815E262,0xABFA,0x4437,0xBF,0xBB,0xEF,0xB3,0x16,0xF4,0xA3,0x1E);


MIDL_DEFINE_GUID(IID, DIID_IMemoryHelper,0xDBA955B9,0x0175,0x4087,0xA3,0x6B,0xD4,0x7D,0x43,0xFD,0x7D,0xA9);


MIDL_DEFINE_GUID(CLSID, CLSID_MemoryHelper,0x45CB3674,0x3B8B,0x4F59,0x8E,0xF1,0xDA,0x15,0x66,0xAB,0x5B,0x3B);


MIDL_DEFINE_GUID(IID, DIID_IFileHelper,0xF6C73760,0xEAA2,0x4525,0xA8,0x5B,0x7C,0x56,0xE3,0x70,0xF8,0x59);


MIDL_DEFINE_GUID(CLSID, CLSID_FileHelper,0x0E270940,0xC4D7,0x4F5D,0x98,0xA2,0x3F,0xB0,0x0F,0x00,0x80,0xF2);


MIDL_DEFINE_GUID(IID, DIID_IXmlHelper,0xC620CE0F,0x8578,0x4405,0x80,0x5E,0xA8,0xAE,0xFF,0xE0,0x7F,0x87);


MIDL_DEFINE_GUID(CLSID, CLSID_XmlHelper,0x347858BE,0x4736,0x4FA7,0x9B,0x0C,0xE6,0xF0,0x1F,0xCD,0xE9,0xD6);


MIDL_DEFINE_GUID(IID, DIID_IStringHelper,0x59408ABD,0x8597,0x4678,0x80,0xEE,0xB3,0x59,0xEE,0x19,0x29,0x84);


MIDL_DEFINE_GUID(CLSID, CLSID_StringHelper,0xA1F09381,0x8B0A,0x4587,0xB8,0xFF,0x2B,0x49,0x0E,0xA8,0xE4,0x37);


MIDL_DEFINE_GUID(IID, DIID_IWindowHelper,0x0F49A766,0x672F,0x4D97,0xBE,0x2A,0x48,0x7D,0x32,0xC5,0x69,0xEE);


MIDL_DEFINE_GUID(CLSID, CLSID_WindowHelper,0x2539E6F3,0xC471,0x4340,0x8A,0xE1,0x91,0x42,0x69,0xF7,0xBE,0x66);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



