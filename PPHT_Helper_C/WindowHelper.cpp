// WindowHelper.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PPHT_Helper_C.h"
#include "WindowHelper.h"


// WindowHelper

IMPLEMENT_DYNCREATE(WindowHelper, CWnd)

WindowHelper::WindowHelper()
{

	EnableAutomation();
	
	// Ϊ��ʹӦ�ó����� OLE �Զ��������ڻ״̬ʱ����
	//	���У����캯������ AfxOleLockApp��
	
	AfxOleLockApp();
}

WindowHelper::~WindowHelper()
{
	// Ϊ������ OLE �Զ����������ж������ֹӦ�ó���
	// 	������������ AfxOleUnlockApp��
	
	AfxOleUnlockApp();
}

void WindowHelper::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease�����ཫ�Զ�
	// ɾ���ö����ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CWnd::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(WindowHelper, CWnd)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(WindowHelper, CWnd)
	DISP_FUNCTION_ID(WindowHelper, "FlashWindow", dispidFlashWindow, FlashWindow, VT_I4, VTS_UI4)
	DISP_FUNCTION_ID(WindowHelper, "GetWindowTitle", dispidGetWindowTitle, GetWindowTitle, VT_BSTR, VTS_UI4)
	DISP_FUNCTION_ID(WindowHelper, "GetForegroundWindow", dispidGetForegroundWindow, GetForegroundWindow, VT_UI4, VTS_NONE)
	DISP_FUNCTION_ID(WindowHelper, "IsMin", dispidIsMin, IsMin, VT_I4, VTS_UI4)
	DISP_FUNCTION_ID(WindowHelper, "IsWindow", dispidIsWindow, IsWindow, VT_I4, VTS_UI4)
	DISP_FUNCTION_ID(WindowHelper, "IsMax", dispidIsMax, IsMax, VT_I4, VTS_UI4)
	DISP_FUNCTION_ID(WindowHelper, "SetForegroundWindow", dispidSetForegroundWindow, SetForegroundWindow, VT_I4, VTS_UI4)
	DISP_FUNCTION_ID(WindowHelper, "MinWindow", dispidMinWindow, MinWindow, VT_EMPTY, VTS_UI4)
	DISP_FUNCTION_ID(WindowHelper, "RestoreWindow", dispidRestoreWindow, RestoreWindow, VT_EMPTY, VTS_UI4)
	DISP_FUNCTION_ID(WindowHelper, "MaxWindow", dispidMaxWindow, MaxWindow, VT_EMPTY, VTS_UI4)
	DISP_FUNCTION_ID(WindowHelper, "GetWindowSize", dispidGetWindowSize, GetWindowSize, VT_BSTR, VTS_UI4)
	DISP_FUNCTION_ID(WindowHelper, "GetClientSize", dispidGetClientSize, GetClientSize, VT_BSTR, VTS_UI4)
	DISP_FUNCTION_ID(WindowHelper, "MoveWindow", dispidMoveWindow, MoveWindow, VT_EMPTY, VTS_UI4 VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(WindowHelper, "SetWindowSize", dispidSetWindowSize, SetWindowSize, VT_EMPTY, VTS_UI4 VTS_UI4 VTS_UI4)
	DISP_FUNCTION_ID(WindowHelper, "SetClientSize", dispidSetClientSize, SetClientSize, VT_EMPTY, VTS_UI4 VTS_UI4 VTS_UI4)
	DISP_FUNCTION_ID(WindowHelper, "WindowFromPoint", dispidWindowFromPoint, WindowFromPoint, VT_UI4, VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(WindowHelper, "GetDC", dispidGetDC, GetDC, VT_UI4, VTS_UI4)
	DISP_FUNCTION_ID(WindowHelper, "GetClientRect", dispidGetClientRect, GetClientRect, VT_EMPTY, VTS_UI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4)
END_DISPATCH_MAP()

// ע��: ������� IID_IWindowHelper ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡��� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {0F49A766-672F-4D97-BE2A-487D32C569EE}
static const IID IID_IWindowHelper =
{ 0xF49A766, 0x672F, 0x4D97, { 0xBE, 0x2A, 0x48, 0x7D, 0x32, 0xC5, 0x69, 0xEE } };

BEGIN_INTERFACE_MAP(WindowHelper, CWnd)
	INTERFACE_PART(WindowHelper, IID_IWindowHelper, Dispatch)
END_INTERFACE_MAP()

// {2539E6F3-C471-4340-8AE1-914269F7BE66}
IMPLEMENT_OLECREATE(WindowHelper, "PPHT_Helper_C.WindowHelper", 0x2539e6f3, 0xc471, 0x4340, 0x8a, 0xe1, 0x91, 0x42, 0x69, 0xf7, 0xbe, 0x66)


// WindowHelper ��Ϣ�������

//��˸����
LONG WindowHelper::FlashWindow(ULONG hwnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return ::FlashWindow((HWND)hwnd,0);
}

//��ô��ڱ���
BSTR WindowHelper::GetWindowTitle(ULONG hwnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;
	LPWSTR tmpstr;
	::GetWindowText((HWND)hwnd,tmpstr,255);
	strResult=tmpstr;
	return strResult.AllocSysString();
}

//��õ�ǰ����
ULONG WindowHelper::GetForegroundWindow(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return (ULONG)::GetForegroundWindow();
}

//�жϴ����Ƿ�����С��
LONG WindowHelper::IsMin(ULONG hwnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return ::IsIconic((HWND)hwnd);
}

//�жϴ��ھ���Ƿ���Ч
LONG WindowHelper::IsWindow(ULONG hwnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return ::IsWindow((HWND)hwnd);
}

//�жϴ����Ƿ����
LONG WindowHelper::IsMax(ULONG hwnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return ::IsZoomed((HWND)hwnd);
}

//��������Ϊϵͳ��ǰ̨����
LONG WindowHelper::SetForegroundWindow(ULONG hwnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return (LONG)::SetForegroundWindow((HWND)hwnd);
}

//��С������
void WindowHelper::MinWindow(ULONG hwnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::ShowWindow((HWND)hwnd,SW_MINIMIZE);
}

//��ԭ����
void WindowHelper::RestoreWindow(ULONG hwnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::ShowWindow((HWND)hwnd,SW_RESTORE);
}

//��󻯴���
void WindowHelper::MaxWindow(ULONG hwnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	::ShowWindow((HWND)hwnd,SW_MAXIMIZE);
}

//��ô���λ�úʹ�С
BSTR WindowHelper::GetWindowSize(ULONG hwnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	RECT *size=new RECT();
	::GetWindowRect((HWND)hwnd,size);
	strResult.Format(L"%d|%d|%d|%d",size->left,size->top,size->right-size->left,size->bottom-size->top);

	return strResult.AllocSysString();
}

//��ÿͻ���λ�úʹ�С
BSTR WindowHelper::GetClientSize(ULONG hwnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	POINT *p=new POINT();
	::ClientToScreen((HWND)hwnd,p);
	RECT *size=new RECT();
	::GetClientRect((HWND)hwnd,size);
	strResult.Format(L"%d|%d|%d|%d",p->x,p->y,size->right-size->left,size->bottom-size->top);

	return strResult.AllocSysString();
}

//�ƶ�����
void WindowHelper::MoveWindow(ULONG hwnd, LONG x, LONG y)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	RECT *size=new RECT();
	::GetWindowRect((HWND)hwnd,size);
	::MoveWindow((HWND)hwnd,x,y,size->right-size->left,size->bottom-size->top,true);
}

//���ô��ڴ�С
void WindowHelper::SetWindowSize(ULONG hwnd, ULONG width, ULONG height)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	RECT *size=new RECT();
	::GetWindowRect((HWND)hwnd,size);
	::MoveWindow((HWND)hwnd,size->left,size->top,width,height,true);
}

//���ÿͻ�����С
void WindowHelper::SetClientSize(ULONG hwnd, ULONG width, ULONG height)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	RECT *wsize=new RECT();
	RECT *csize=new RECT();
	ULONG w,h;
	::GetWindowRect((HWND)hwnd,wsize);
	::GetClientRect((HWND)hwnd,csize);
	w=width+((wsize->right-wsize->left)-(csize->right-csize->left));
	h=height+((wsize->bottom-wsize->top)-(csize->bottom-csize->top));
	::MoveWindow((HWND)hwnd,wsize->left,wsize->top,w,h,true);
}


ULONG WindowHelper::WindowFromPoint(LONG x, LONG y)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������
	POINT *point =new POINT();
	point->x=x;
	point->y=y;
	return (ULONG)::WindowFromPoint(*point);
}


ULONG WindowHelper::GetDC(ULONG hwnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return (ULONG)::GetDC((HWND)hwnd);
}


void WindowHelper::GetClientRect(ULONG hwnd, LONG* left, LONG* right, LONG* top, LONG* bottom)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	RECT *rect=new RECT();
	::GetClientRect((HWND)hwnd,rect);
	*left=rect->left;
	*right=rect->right;
	*top=rect->top;
	*bottom=rect->bottom;
}
