#pragma once

#define SCREEN_SAVE_DIR _T("E:\\PlayAigis\\")
#define CHROME_CLASSNAME _T("Chrome_WidgetWin_1")


#define FRAME_COORD_LEFT 5
#define FRAME_COORD_TOP 0
#define FRAME_COORD_WIDTH 960
#define FRAME_COORD_HEIGHT 640

#define COORD_ZERO				0, 0
#define FRAME_BEGIN		FRAME_COORD_LEFT, FRAME_COORD_TOP
#define FRAME_SIZE		FRAME_COORD_WIDTH, FRAME_COORD_HEIGHT


#define POINT_INTERVAL 5
enum E_POINT_DIRECTION
{
	EPD_MID,
	EPD_LEFT,
	EPD_TOP,
	EPD_RIGHT,
	EPD_BOTTOM,
	EPD_MAX
};
