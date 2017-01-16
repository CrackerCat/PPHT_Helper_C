// ConvertHelper.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PPHT_Helper_C.h"
#include "ConvertHelper.h"


// ConvertHelper

IMPLEMENT_DYNCREATE(ConvertHelper, CWnd)

ConvertHelper::ConvertHelper()
{

	EnableAutomation();
	
	// Ϊ��ʹӦ�ó����� OLE �Զ��������ڻ״̬ʱ����
	//	���У����캯������ AfxOleLockApp��
	
	AfxOleLockApp();
}

ConvertHelper::~ConvertHelper()
{
	// Ϊ������ OLE �Զ����������ж������ֹӦ�ó���
	// 	������������ AfxOleUnlockApp��
	
	AfxOleUnlockApp();
}

void ConvertHelper::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease�����ཫ�Զ�
	// ɾ���ö����ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CWnd::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(ConvertHelper, CWnd)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(ConvertHelper, CWnd)
	DISP_FUNCTION_ID(ConvertHelper, "IntToHex", dispidIntToHex, IntToHex, VT_BSTR, VTS_UI4 VTS_UI4)
	DISP_FUNCTION_ID(ConvertHelper, "HexToInt", dispidHexToInt, HexToInt, VT_UI4, VTS_BSTR)
END_DISPATCH_MAP()

// ע��: ������� IID_IonvertHelper ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡��� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {BC39A831-E868-48B6-ACD3-4CB0341B531F}
static const IID IID_IonvertHelper =
{ 0xBC39A831, 0xE868, 0x48B6, { 0xAC, 0xD3, 0x4C, 0xB0, 0x34, 0x1B, 0x53, 0x1F } };

BEGIN_INTERFACE_MAP(ConvertHelper, CWnd)
	INTERFACE_PART(ConvertHelper, IID_IonvertHelper, Dispatch)
END_INTERFACE_MAP()

// {8B462A43-4FC8-493C-9E11-41CE8B2A81AB}
IMPLEMENT_OLECREATE(ConvertHelper, "PPHT_Helper_C.ConvertHelper", 0x8b462a43, 0x4fc8, 0x493c, 0x9e, 0x11, 0x41, 0xce, 0x8b, 0x2a, 0x81, 0xab)


// ConvertHelper ��Ϣ�������




BSTR ConvertHelper::IntToHex(ULONG val,ULONG len)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;
	if (len>0)
	{
		strResult.Format(L"%X",val);
	}
	for (int i=strResult.GetLength();i<len;i++)
	{
	strResult=L"0" + strResult;
	}
	
	return strResult.AllocSysString();
}


ULONG ConvertHelper::HexToInt(LPCTSTR val)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	ULONG r=0;
	r=wcstoul(val,NULL,16);
	return r;
}
