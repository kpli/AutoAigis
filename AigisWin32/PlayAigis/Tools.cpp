#include "stdafx.h"
#include "Tools.h"
#include "Frame.h"
#include "Pnt5.h"


CTools::CTools()
{
	initDir();
}


CTools::~CTools()
{
}

CTools* CTools::getInstance()
{
	static CTools ret;
	return &ret;
}

void CTools::initDir()
{
	DWORD dwAttr = GetFileAttributes(SCREEN_SAVE_DIR);
	if (dwAttr == 0xFFFFFFFF)
	{
		CreateDirectory(SCREEN_SAVE_DIR, NULL);
	}
}

void CTools::saveBmp(HWND hwnd, LPCTSTR file)
{
	HDC hdc = GetWindowDC(hwnd);
	HDC hMemDC_Tmp = CreateCompatibleDC(hdc);							//创建与桌面窗口DC相适应的内存TMP
	HBITMAP hbitm_tmp = CreateCompatibleBitmap(hdc, FRAME_SIZE);	//创建相适应的位图
	SelectObject(hMemDC_Tmp, hbitm_tmp);
	BitBlt(hMemDC_Tmp, COORD_ZERO, FRAME_SIZE, hdc, FRAME_BEGIN, SRCCOPY);
	TCHAR szBuf[MAXCHAR];
	_tcscpy_s(szBuf, SCREEN_SAVE_DIR);
	_tcscat_s(szBuf, file);
	flushBmp(hbitm_tmp, szBuf);
	DeleteObject(hbitm_tmp);
	DeleteDC(hMemDC_Tmp);
	ReleaseDC(hwnd, hdc);
}

BOOL CTools::flushBmp(HBITMAP hbitmap, LPCTSTR filename, int nColor)
{
	BITMAP Bitmap ;
	HDC	hDC = nullptr;
	DWORD dwPaletteSize = 0, dwBmBitsSize, dwDIBSize, dwWritten;
	BITMAPFILEHEADER bmfHdr;
	BITMAPINFOHEADER bi;
	LPBITMAPINFOHEADER lpbi = nullptr;
	HANDLE fh, hDib, hPal, hOldPal = nullptr;

	if (nColor <= 8)
		dwPaletteSize = (1 << nColor)   *sizeof(RGBQUAD);
	GetObject(hbitmap, sizeof(BITMAP), (LPSTR)&Bitmap);
	bi.biSize = sizeof(BITMAPINFOHEADER);
	bi.biWidth = Bitmap.bmWidth;
	bi.biHeight = Bitmap.bmHeight;
	bi.biPlanes = 1;
	bi.biBitCount = nColor;
	bi.biCompression = BI_RGB;
	bi.biSizeImage = 0;
	bi.biXPelsPerMeter = 0;
	bi.biYPelsPerMeter = 0;
	bi.biClrUsed = 0;
	bi.biClrImportant = 0;
	dwBmBitsSize = ((Bitmap.bmWidth  *   nColor + 31) / 32 * 4)*Bitmap.bmHeight;
	//为位图分配内存
	hDib = GlobalAlloc(GHND, dwBmBitsSize + dwPaletteSize + sizeof(BITMAPINFOHEADER));
	lpbi = (LPBITMAPINFOHEADER)GlobalLock(hDib);
	*lpbi = bi;
	//设置调色板
	hPal = GetStockObject(DEFAULT_PALETTE);
	if (hPal)
	{
		hDC = ::GetDC(NULL);
		hOldPal = SelectPalette(hDC, (HPALETTE)hPal, FALSE);
		RealizePalette(hDC);
	}
	// 获取该调色板下新的像素值
	GetDIBits(hDC, hbitmap, 0, Bitmap.bmHeight,
		(LPSTR)lpbi + sizeof(BITMAPINFOHEADER) + dwPaletteSize,
		(BITMAPINFO   *)lpbi, DIB_RGB_COLORS);
	if (hOldPal)
	{
		SelectPalette(hDC, (HPALETTE)hOldPal, TRUE);
		RealizePalette(hDC);
		::ReleaseDC(NULL, hDC);
	}

	fh = CreateFile(filename, GENERIC_WRITE,
		0,//not   be   shared   
		NULL,   //cannot   be   inherited   
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN,
		NULL);

	if (fh == INVALID_HANDLE_VALUE)
		return   FALSE;
	//设置位图文件头
	bmfHdr.bfType = 0x4D42;     //   "BM"   
	dwDIBSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + dwPaletteSize + dwBmBitsSize;
	bmfHdr.bfSize = dwDIBSize;
	bmfHdr.bfReserved1 = 0;
	bmfHdr.bfReserved2 = 0;
	bmfHdr.bfOffBits = (DWORD)sizeof(BITMAPFILEHEADER)
		+ (DWORD)sizeof(BITMAPINFOHEADER) + dwPaletteSize;

	//write   file   header   
	WriteFile(fh, (LPSTR)&bmfHdr, sizeof(BITMAPFILEHEADER), &dwWritten, NULL);

	//write   bmp   data   
	WriteFile(fh, (LPSTR)lpbi, dwDIBSize, &dwWritten, NULL);

	GlobalUnlock(hDib);
	GlobalFree(hDib);
	CloseHandle(fh);
	DeleteObject(hbitmap);
	return TRUE;
}

void CTools::printMouseColor()
{

}



