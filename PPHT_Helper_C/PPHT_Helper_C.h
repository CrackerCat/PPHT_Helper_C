// PPHT_Helper_C.h : PPHT_Helper_C DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CPPHT_Helper_CApp
// �йش���ʵ�ֵ���Ϣ������� PPHT_Helper_C.cpp
//

class CPPHT_Helper_CApp : public CWinApp
{
public:
	CPPHT_Helper_CApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
