#include "stdafx.h"
#include "Ctrl.h"
#include "Frame.h"
#include "Tools.h"
#include "Logic.h"

bool CCtrl::s_bEffect = true;


CCtrl::CCtrl()
{
	cout << "Alt+(F1|F2) (COLOR|TEST)" << endl;
	cout << "Alt+(F10|F12) (START|STOP)" << endl;
}


CCtrl::~CCtrl()
{
}

void CCtrl::initHotKey()
{
	if (!RegisterHotKey(NULL, VK_F1, MOD_ALT | MOD_NOREPEAT, VK_F1))
		cout << "RegisterHotKey error, key: " << hex << VK_F1 << endl;
	if (!RegisterHotKey(NULL, VK_F2, MOD_ALT | MOD_NOREPEAT, VK_F2))
		cout << "RegisterHotKey error, key: " << hex << VK_F2 << endl;
	if (!RegisterHotKey(NULL, VK_F10, MOD_ALT | MOD_NOREPEAT, VK_F10))
		cout << "RegisterHotKey error, key: " << hex << VK_F10 << endl;
	if (!RegisterHotKey(NULL, VK_F12, MOD_ALT | MOD_NOREPEAT, VK_F12))
		cout << "RegisterHotKey error, key: " << hex << VK_F12 << endl;

	MSG msg = {0};  
	while (GetMessage(&msg, NULL, 0, 0) != 0)  
	{  
		if (msg.message == WM_HOTKEY)  
		{ 
			WORD wPressed = HIWORD(msg.lParam);
			switch (wPressed)
			{
			case VK_F1:
				CTools::getInstance()->printSystemTime();
				CFrame::getInstance()->logColor();
				break;
			case VK_F2:
				CTools::getInstance()->printSystemTime();
				CLogic::getInstance()->playStory4();
				break;
			case VK_F10:
				start();
				break;
			case VK_F12:
				stop();
				break;
			default:
				break;
			}
		}  
	}   

	UnregisterHotKey(NULL, VK_F1);
	UnregisterHotKey(NULL, VK_F10);
	UnregisterHotKey(NULL, VK_F12);
}

void CCtrl::start()
{
	CCtrl::s_bEffect = true;
	CLogic::getInstance()->startPlay();
}

void CCtrl::stop()
{
	CCtrl::s_bEffect = false;
}

bool CCtrl::canPlay()
{
	return CCtrl::s_bEffect;
}



