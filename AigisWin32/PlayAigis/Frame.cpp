#include "stdafx.h"
#include "Frame.h"
#include "Tools.h"


CFrame::CFrame()
{
}


CFrame::~CFrame()
{
}

CFrame* CFrame::getInstance()
{
	static CFrame ret;
	return &ret;
}

HWND CFrame::aigisHwnd()
{
	HWND hChrome = chromeHwnd();
	if (!hChrome)
	{
		return nullptr;
	}

	HWND hFrame = FindWindowEx(hChrome, 0, _T("Chrome_RenderWidgetHostHWND"), _T("Chrome Legacy Window"));
	if (!hFrame)
	{
		return nullptr;
	}

	return hFrame;
}

void CFrame::getAccount(LPTSTR lpBuf, int maxLen)
{
	HWND hChrome = chromeHwnd();
	if (!hChrome)
	{
		return;
	}

	GetWindowText(hChrome, lpBuf, maxLen);

	int nLen = _tcslen(lpBuf);
	if (nLen == 0 || nLen >= maxLen/2)
	{
		_tcscpy_s(lpBuf, maxLen, _T("ERR"));
	}
	else
	{
		for (int i = 1; i < nLen; i++)
		{
			if (lpBuf[i] == '-')
			{
				lpBuf[i - 1] = '\0';
			}
		}
	}

	SYSTEMTIME sysTime;
	GetLocalTime(&sysTime);
	TCHAR buffer[MAXCHAR] = { 0 };
	wsprintf(buffer, _T("_%04d%02d%02d%02d%02d%02d"), sysTime.wYear, sysTime.wMonth, sysTime.wDay, sysTime.wHour, sysTime.wMinute, sysTime.wSecond);

	_tcscat_s(lpBuf, MAXCHAR, buffer);
}

void CFrame::closeChrome()
{
	HWND hChrome = chromeHwnd();
	if (!hChrome)
	{
		return;
	}
	PostMessage(hChrome, WM_CLOSE, NULL, NULL);
}

HWND CFrame::chromeHwnd()
{
	HWND hTabMain = FindWindow(CHROME_CLASSNAME, nullptr);
	if (!hTabMain)
	{
		return nullptr;
	}
	HWND hChrome = GetParent(hTabMain);
	if (!hChrome)
	{
		return nullptr;
	}
	return hChrome;
}

void CFrame::saveImage()
{
	HWND hwnd = aigisHwnd();
	if (!hwnd)
	{
		return;
	}

	TCHAR fileName[MAXCHAR] = { 0 };
	getAccount(fileName, MAXCHAR);
	_tcscat_s(fileName, _T(".bmp"));

	CTools* pTools = CTools::getInstance();
	pTools->saveBmp(hwnd, fileName);
}

bool CFrame::findColor(CPnt5* pnt5)
{
	HWND hwnd = aigisHwnd();
	if (!hwnd)
	{
		return false;
	}
	HDC hdc = GetWindowDC(hwnd);
	if (!hdc)
	{
		return false;
	}

	bool bSame = true;
	for (size_t i = 0; i < EPD_MAX; i++)
	{
		POINT pntTmp = pnt5->getPoint((E_POINT_DIRECTION)i);
		COLORREF colorDefi = pnt5->getColor((E_POINT_DIRECTION)i);
		COLORREF colorFind = GetPixel(hdc, pntTmp.x, pntTmp.y);
		if (colorDefi != colorFind )
		{
			bSame = false;
			break;
		}
	}

	ReleaseDC(hwnd, hdc);
	return bSame;
}

void CFrame::logColor(CPnt5* pnt5)
{
	HWND hwnd = aigisHwnd();
	if (!hwnd)
	{
		return ;
	}
	HDC hdc = GetWindowDC(hwnd);
	if (!hdc)
	{
		return ;
	}

	cout << dec << pnt5->getPoint(EPD_MID).x << ", " << pnt5->getPoint(EPD_MID).y;
	for (size_t i = 0; i < EPD_MAX; i++)
	{
		POINT pntTmp = pnt5->getPoint((E_POINT_DIRECTION)i);
		COLORREF colorFind = GetPixel(hdc, pntTmp.x, pntTmp.y);
		cout << ", 0x" << hex << colorFind;
		CStcVal::s_arrColor[i] = colorFind;
	}
	cout << endl;
	
	ReleaseDC(hwnd, hdc);
}

void CFrame::logColor()
{
	HWND hwnd = aigisHwnd();
	if (!hwnd)
	{
		return;
	}
	POINT pntCursor;
	GetCursorPos(&pntCursor);
	ScreenToClient(hwnd, &pntCursor);
	CPnt5 pnt5(pntCursor);
	pnt5.print();
}

void CFrame::click(CPnt5* pnt5)
{
	HWND hwnd = aigisHwnd();
	if (!hwnd)
	{
		return;
	}

	POINT pt = pnt5->getPoint(EPD_MID);
	setCurSor(pt);
	PostMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(pt.x, pt.y));
	Sleep(50);
	PostMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(pt.x, pt.y));
	Sleep(50);
}

void CFrame::drag(CRolePnt* pntR)
{
	HWND hwnd = aigisHwnd();
	if (!hwnd)
	{
		return;
	}

	POINT p5 = pntR->p5.getPoint(EPD_MID);
	POINT pt = pntR->pt;

	setCurSor(p5);
	PostMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(p5.x, p5.y));
	Sleep(50);
	PostMessage(hwnd, WM_MOUSEMOVE, 0, MAKELPARAM(pt.x, pt.y));

	setCurSor(pt);
	Sleep(150);
	PostMessage(hwnd, WM_LBUTTONUP, 0, MAKELPARAM(pt.x, pt.y));
	Sleep(150);

}

void CFrame::setCurSor(POINT pnt)
{
	HWND hwnd = aigisHwnd();
	if (!hwnd)
	{
		return;
	}
	POINT ptScr = pnt;
	ClientToScreen(hwnd, &ptScr);
	SetCursorPos(ptScr.x, ptScr.y);
}

void CFrame::setRangeLT()
{
	HWND hwnd = aigisHwnd();
	if (!hwnd)
	{
		return;
	}
	POINT pntCursor;
	GetCursorPos(&pntCursor);
	ScreenToClient(hwnd, &pntCursor);
	CStcVal::s_rcRange.left = pntCursor.x;
	CStcVal::s_rcRange.top = pntCursor.y;
}

void CFrame::setRangeRB()
{
	HWND hwnd = aigisHwnd();
	if (!hwnd)
	{
		return;
	}
	POINT pntCursor;
	GetCursorPos(&pntCursor);
	ScreenToClient(hwnd, &pntCursor);
	CStcVal::s_rcRange.right = pntCursor.x;
	CStcVal::s_rcRange.bottom = pntCursor.y;
}

