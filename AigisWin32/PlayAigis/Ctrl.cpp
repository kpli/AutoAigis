#include "stdafx.h"
#include "Ctrl.h"
#include "Frame.h"
#include "Logic.h"

bool CCtrl::s_bEffect = true;


CCtrl::CCtrl()
{
	cout << "Alt+(F10|F12) (START|STOP)" << endl;
}


CCtrl::~CCtrl()
{
}

void CCtrl::initHotKey()
{
	for (WORD i = VK_F1; i <= VK_F12; i++)
	{
		if (!RegisterHotKey(NULL, i, MOD_ALT | MOD_NOREPEAT, i))
			cout << "RegisterHotKey error, key: " << hex << i << endl;
	}

	MSG msg = {0};  
	while (GetMessage(&msg, NULL, 0, 0) != 0)  
	{  
		if (msg.message == WM_HOTKEY)  
		{ 
			WORD wPressed = HIWORD(msg.lParam);
			switch (wPressed)
			{
			case VK_F1:
				cout << "press VK_F1" << endl;
				CFrame::getInstance()->logColor();
				break;
			case VK_F2:
				cout << "press VK_F2" << endl;
				// Test();
				break;
			case VK_F3:
				cout << "press VK_F3" << endl;
				// Test();
				break;
			case VK_F4:
				cout << "press VK_F4" << endl;
				break;
			case VK_F5:
				cout << "press VK_F5" << endl;
				// runPlay();
				break;
			case VK_F6:
				cout << "press VK_F6" << endl;
				// playStart();
				break;
			case VK_F7:
				cout << "press VK_F7" << endl;
				// playStory1();
				break;
			case VK_F8:
				cout << "press VK_F8" << endl;
				// playStory2();
				break;
			case VK_F9:
				cout << "press VK_F9" << endl;
				// playBounding();
				break;
			case VK_F10:
				cout << "press VK_F10" << endl;
				//
				start();
				break;
			case VK_F11:
				cout << "press VK_F11" << endl;
				// playRandom();
				break;
			case VK_F12:
				cout << "press VK_F12" << endl;
				stop();
				break;
			default:
				break;
			}
		}  
	}   

	for (WORD i = VK_F1; i <= VK_F12; i++)
	{
		if (!UnregisterHotKey(NULL, i))
			cout << "UnregisterHotKey error, key: " << hex << i << endl;
	}
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



