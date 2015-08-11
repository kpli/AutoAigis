#include "stdafx.h"
#include "Pnt5.h"
#include "Tools.h"
 
 
CPnt5::CPnt5(int x, int y)
{
	mp.x = x;
	mp.y = y;
	for (int i = 0; i < EPD_MAX; i++)
	{
		ac[i] = COLORREF(0x000000);
	}
}

CPnt5::CPnt5(int x, int y, COLORREF c0, COLORREF c1, COLORREF c2, COLORREF c3, COLORREF c4)
{
	mp.x = x;
	mp.y = y;
	ac[0] = c0;
	ac[1] = c1;
	ac[2] = c2;
	ac[3] = c3;
	ac[4] = c4;
}

CPnt5::~CPnt5()
{
}

POINT CPnt5::getPoint(E_POINT_DIRECTION epd)
{
	POINT pnt = mp;
	switch (epd)
	{
	case EPD_MID:
		break;
	case EPD_LEFT:
		pnt.x -= POINT_INTERVAL;
		break;
	case EPD_TOP:
		pnt.y -= POINT_INTERVAL;
		break;
	case EPD_RIGHT:
		pnt.x += POINT_INTERVAL;
		break;
	case EPD_BOTTOM:
		pnt.y += POINT_INTERVAL;
		break;
	default:
		break;
	}
	return pnt;
}

const COLORREF CPnt5::getColor(E_POINT_DIRECTION epd)
{
	POINT pnt = getPoint(epd);
	COLORREF crf = CTools::getInstance()->getColor(pnt);
	return crf;
}

bool CPnt5::find()
{
	if ( getColor(EPD_MID) == ac[EPD_MID]
		&& getColor(EPD_LEFT) == ac[EPD_LEFT]
		&& getColor(EPD_TOP) == ac[EPD_TOP]
		&& getColor(EPD_RIGHT) == ac[EPD_RIGHT]
		&& getColor(EPD_BOTTOM) == ac[EPD_BOTTOM])
	{
		return true;
	}
	return false;
}

void CPnt5::print()
{
	cout << dec
		<< mp.x << ", " << mp.y << ", "
		<< hex 
		<< getColor(EPD_MID) << ", "
		<< getColor(EPD_LEFT) << ", "
		<< getColor(EPD_TOP) << ", "
		<< getColor(EPD_RIGHT) << ", "
		<< getColor(EPD_BOTTOM)
		<< endl;
}

