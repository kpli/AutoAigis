#pragma once 

class CPnt5
{
public:
	CPnt5(int x, int y);
	CPnt5(int x, int y, COLORREF c1, COLORREF c2, COLORREF c3, COLORREF c4, COLORREF c5);
	~CPnt5();

	bool find();
	void print();
private:
	POINT mp;
	COLORREF ac[EPD_MAX];

	const COLORREF getColor(E_POINT_DIRECTION epd);
	POINT getPoint(E_POINT_DIRECTION epd);
};

