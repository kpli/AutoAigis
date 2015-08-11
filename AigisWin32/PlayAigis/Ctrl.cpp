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
	if (!RegisterHotKey(NULL, VK_F1, MOD_ALT | MOD_NOREPEAT, VK_F1))
		cout << "RegisterHotKey error, key: " << hex << VK_F1 << endl;
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
				cout << "press VK_F1" << endl;
				CFrame::getInstance()->logColor();
				break;
			case VK_F10:
				cout << "press VK_F10" << endl;
				start();
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
	cout << "______VK_F12_FOR_STOP______" << endl;
	CCtrl::s_bEffect = false;
}

bool CCtrl::canPlay()
{
	return CCtrl::s_bEffect;
}



