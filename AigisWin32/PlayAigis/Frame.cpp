#include "stdafx.h"
#include "Frame.h"


CFrame::CFrame()
	:m_hFocus(nullptr)
{
}


CFrame::~CFrame()
{
	m_hFocus = nullptr;
}

CFrame* CFrame::getInstance()
{
	static CFrame ret;
	return &ret;
}

HWND CFrame::aigisHwnd()
{
	if (m_hFocus)
	{
		return m_hFocus;
	}

	HWND hChrome = nullptr;
	hChrome = FindWindow(CHROME_CLASSNAME, nullptr);
	if (!hChrome)
	{
		return nullptr;
	}
	HWND hTab = GetParent(hChrome);
	if (!hTab)
	{
		return nullptr;
	}

	HWND hFrame = nullptr;
	hFrame = FindWindowEx(hTab, 0, _T("Chrome_RenderWidgetHostHWND"), _T("Chrome Legacy Window"));
	if (!hFrame)
	{
		return nullptr;
	}

	m_hFocus = hFrame;
	return m_hFocus;
}

void CFrame::rePlay()
{
	m_hFocus = nullptr;
}

void CFrame::getAccount(LPTSTR lpBuf, int maxLen)
{
	HWND hwnd = aigisHwnd();
	if (!hwnd)
	{
		return;
	}

	HWND hTab = GetParent(hwnd);
	if (!hTab)
	{
		return ;
	}

	GetWindowText(hTab, lpBuf, maxLen);

	int nLen = _tcslen(lpBuf);
	for (int i = 1; i < nLen; i++)
	{
		if (lpBuf[i] == '-')
		{
			lpBuf[i - 1] = '\0';
		}
	}
}

