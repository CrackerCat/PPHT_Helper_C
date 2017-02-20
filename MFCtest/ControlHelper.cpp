// ControlHelper.cpp : ʵ���ļ�
//

#include "stdafx.h"
//#include "PPHT_Helper_C.h"
#include "ControlHelper.h"


// ControlHelper

IMPLEMENT_DYNCREATE(ControlHelper, CWnd)

ControlHelper::ControlHelper()
{

	EnableAutomation();
	
	// Ϊ��ʹӦ�ó����� OLE �Զ��������ڻ״̬ʱ����
	//	���У����캯������ AfxOleLockApp��
	
	AfxOleLockApp();
}

ControlHelper::~ControlHelper()
{
	// Ϊ������ OLE �Զ����������ж������ֹӦ�ó���
	// 	������������ AfxOleUnlockApp��
	
	AfxOleUnlockApp();
}

void ControlHelper::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease�����ཫ�Զ�
	// ɾ���ö����ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CWnd::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(ControlHelper, CWnd)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(ControlHelper, CWnd)
	DISP_FUNCTION_ID(ControlHelper, "MouseMove", dispidMouseMove, MouseMove, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(ControlHelper, "LMouseDown", dispidLMouseDown, LMouseDown, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(ControlHelper, "LMouseUp", dispidLMouseUp, LMouseUp, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(ControlHelper, "LMouseClick", dispidLMouseClick, LMouseClick, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(ControlHelper, "MMouseDown", dispidMMouseDown, MMouseDown, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(ControlHelper, "MMouseUp", dispidMMouseUp, MMouseUp, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(ControlHelper, "MMouseClick", dispidMMouseClick, MMouseClick, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(ControlHelper, "RMouseDown", dispidRMouseDown, RMouseDown, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(ControlHelper, "RMouseUp", dispidRMouseUp, RMouseUp, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(ControlHelper, "RMouseClick", dispidRMouseClick, RMouseClick, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(ControlHelper, "SendUnicodeString", dispidSendUnicodeString, SendUnicodeString, VT_EMPTY, VTS_UI4 VTS_BSTR)
	DISP_FUNCTION_ID(ControlHelper, "SendANSIString", dispidSendANSIString, SendANSIString, VT_EMPTY, VTS_UI4 VTS_BSTR)
	DISP_FUNCTION_ID(ControlHelper, "SendUTF8String", dispidSendUTF8String, SendUTF8String, VT_EMPTY, VTS_UI4 VTS_BSTR)
	DISP_FUNCTION_ID(ControlHelper, "KeyDown", dispidKeyDown, KeyDown, VT_EMPTY, VTS_UI4 VTS_UI4)
	DISP_FUNCTION_ID(ControlHelper, "KeyUp", dispidKeyUp, KeyUp, VT_EMPTY, VTS_UI4 VTS_UI4)
	DISP_FUNCTION_ID(ControlHelper, "KeyPress", dispidKeyPress, KeyPress, VT_EMPTY, VTS_UI4 VTS_UI4 VTS_UI4)
END_DISPATCH_MAP()

// ע��: ������� IID_IontrolHelper ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡��� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {9C3DC0C5-927B-400E-81EC-2A7BFAB02B62}
static const IID IID_IontrolHelper =
{ 0x9C3DC0C5, 0x927B, 0x400E, { 0x81, 0xEC, 0x2A, 0x7B, 0xFA, 0xB0, 0x2B, 0x62 } };

BEGIN_INTERFACE_MAP(ControlHelper, CWnd)
	INTERFACE_PART(ControlHelper, IID_IontrolHelper, Dispatch)
END_INTERFACE_MAP()

// {D815E262-ABFA-4437-BFBB-EFB316F4A31E}
IMPLEMENT_OLECREATE(ControlHelper, "PPHT_Helper_C.ControlHelper", 0xd815e262, 0xabfa, 0x4437, 0xbf, 0xbb, 0xef, 0xb3, 0x16, 0xf4, 0xa3, 0x1e)


// ControlHelper ��Ϣ�������




void ControlHelper::MouseMove(ULONG hwnd, LONG x, LONG y)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::PostMessageA((HWND)hwnd,WM_MOUSEMOVE,0,x+y*0x10000);
}


void ControlHelper::LMouseDown(ULONG hwnd, LONG x, LONG y)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::PostMessageA((HWND)hwnd,WM_MOUSEMOVE,0,x+y*0x10000);
	::PostMessageA((HWND)hwnd,WM_LBUTTONDOWN,0x1,x+y*0x10000);
}


void ControlHelper::LMouseUp(ULONG hwnd, LONG x, LONG y)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::PostMessageA((HWND)hwnd,WM_MOUSEMOVE,0,x+y*0x10000);
	::PostMessageA((HWND)hwnd,WM_LBUTTONUP,0,x+y*0x10000);
}


void ControlHelper::LMouseClick(ULONG hwnd, LONG x, LONG y)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::PostMessageA((HWND)hwnd,WM_MOUSEMOVE,0,x+y*0x10000);
	::PostMessageA((HWND)hwnd,WM_LBUTTONDOWN,0x1,x+y*0x10000);
	::PostMessageA((HWND)hwnd,WM_LBUTTONUP,0,x+y*0x10000);
}


void ControlHelper::MMouseDown(ULONG hwnd, LONG x, LONG y)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::PostMessageA((HWND)hwnd,WM_MOUSEMOVE,0,x+y*0x10000);
	::PostMessageA((HWND)hwnd,WM_MBUTTONDOWN,0x10,x+y*0x10000);
}


void ControlHelper::MMouseUp(ULONG hwnd, LONG x, LONG y)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::PostMessageA((HWND)hwnd,WM_MOUSEMOVE,0,x+y*0x10000);
	::PostMessageA((HWND)hwnd,WM_MBUTTONUP,0,x+y*0x10000);
}


void ControlHelper::MMouseClick(ULONG hwnd, LONG x, LONG y)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::PostMessageA((HWND)hwnd,WM_MOUSEMOVE,0,x+y*0x10000);
	::PostMessageA((HWND)hwnd,WM_MBUTTONDOWN,0x10,x+y*0x10000);
	::PostMessageA((HWND)hwnd,WM_MBUTTONUP,0,x+y*0x10000);
}


void ControlHelper::RMouseDown(ULONG hwnd, LONG x, LONG y)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::PostMessageA((HWND)hwnd,WM_MOUSEMOVE,0,x+y*0x10000);
	::PostMessageA((HWND)hwnd,WM_RBUTTONDOWN,0x2,x+y*0x10000);
}


void ControlHelper::RMouseUp(ULONG hwnd, LONG x, LONG y)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::PostMessageA((HWND)hwnd,WM_MOUSEMOVE,0,x+y*0x10000);
	::PostMessageA((HWND)hwnd,WM_RBUTTONUP,0,x+y*0x10000);
}


void ControlHelper::RMouseClick(ULONG hwnd, LONG x, LONG y)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::PostMessageA((HWND)hwnd,WM_MOUSEMOVE,0,x+y*0x10000);
	::PostMessageA((HWND)hwnd,WM_RBUTTONDOWN,0x2,x+y*0x10000);
	::PostMessageA((HWND)hwnd,WM_RBUTTONUP,0,x+y*0x10000);
}


void ControlHelper::SendUnicodeString(ULONG hwnd, LPCTSTR msgStr)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	BYTE *bytes;
	int len = convertHelper.StringToUnicodeBytes(msgStr,&bytes);
	for (int i=0;i<len;i++)
	{
		::PostMessageA((HWND)hwnd,WM_CHAR, bytes[i], 0);
	}
}


void ControlHelper::SendANSIString(ULONG hwnd, LPCTSTR msgStr)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	BYTE *bytes;
	int len = convertHelper.StringToANSIBytes(msgStr,&bytes);
	for (int i=0;i<len;i++)
	{
		::PostMessageA((HWND)hwnd,WM_CHAR, bytes[i], 0);
	}
}


void ControlHelper::SendUTF8String(ULONG hwnd, LPCTSTR msgStr)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	BYTE *bytes;
	int len = convertHelper.StringToUTF8Bytes(msgStr,&bytes);
	for (int i=0;i<len;i++)
	{
		::PostMessageA((HWND)hwnd,WM_CHAR, bytes[i], 0);
	}
}


void ControlHelper::KeyDown(ULONG hwnd, ULONG key)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::PostMessageA((HWND)hwnd, WM_KEYDOWN, key, 1);
}


void ControlHelper::KeyUp(ULONG hwnd, ULONG key)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::PostMessageA((HWND)hwnd, WM_KEYUP, key, 1);
}


void ControlHelper::KeyPress(ULONG hwnd, ULONG key, ULONG count)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::PostMessageA((HWND)hwnd, WM_KEYDOWN|WM_KEYUP, key, count);
}
