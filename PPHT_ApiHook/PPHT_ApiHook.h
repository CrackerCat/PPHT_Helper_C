// PPHT_ApiHook.h : PPHT_ApiHook DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������



// CPPHT_ApiHookApp
// �йش���ʵ�ֵ���Ϣ������� PPHT_ApiHook.cpp
//

class CPPHT_ApiHookApp : public CWinApp
{
public:
	CPPHT_ApiHookApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()

public:
	
};
