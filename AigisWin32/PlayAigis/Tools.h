#pragma once
class CTools
{
public:
	static CTools* getInstance();

	COLORREF getColor(POINT pnt);
	void save();
private:
	CTools();
	~CTools();

	void initDir();
	void save(HWND hwnd, LPCTSTR name);
	BOOL flushBmp(HBITMAP hbitmap, LPCTSTR name, int nColor = 8);
};


