#pragma once
class CTools
{
public:
	static CTools* getInstance();

	void saveBmp(HWND hwnd, LPCTSTR name);
	void printMouseColor();
	void printSystemTime();
private:
	CTools();
	~CTools();

	void initDir();
	BOOL flushBmp(HBITMAP hbitmap, LPCTSTR name, int nColor = 8);
};


