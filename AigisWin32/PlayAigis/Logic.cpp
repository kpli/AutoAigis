#include "stdafx.h"
#include "Logic.h"
#include "Ctrl.h"
#include "Pnt5.h"
#include "Frame.h"
#include <process.h>


#define LOOP_BEGIN	size_t bt = GetTickCount();	while (CCtrl::canPlay() && canWait()) {
#define LOOP_END(sec)	DetectTimeout(bt, sec);}

bool CLogic::s_bWaitFor = true;

CPnt5 CLogic::s_CardSilver(205, 573, 0xb1b1b1, 0x878787, 0x9a9a9a, 0x9f9f9f, 0xa6a6a6);
CPnt5 CLogic::s_CardGold(204, 576, 0x3af9ff, 0x1feff, 0x15e3f1, 0x39e8f3, 0x2b1cc);
CPnt5 CLogic::s_CardWhite(203, 575, 0xecede9, 0xbbbdb2, 0xadb0a5, 0xfcfdfc, 0xe1e1dc);
CPnt5 CLogic::s_CardBlack(203, 575, 0xecede9, 0xbbbdb2, 0xadb0a5, 0xfcfdfc, 0xe1e1dc);

CPnt5 CLogic::s_GameIcon(454, 261, 0xaeaeae, 0x12128d, 0x5e5e5e, 0xffffff, 0xe2e2e1);		// 开始界面游戏LOGO
CPnt5 CLogic::s_GameStory(654, 176, 0x8adafa, 0x8792bb, 0x6eb6e5, 0x45cbea, 0x62a0e6);		// 第二关第三关入口
CPnt5 CLogic::s_GameBtnOK(474, 424, 0xffffff, 0xb67600, 0xffffff, 0xad6400, 0xbf7600);		// 确认按钮
CPnt5 CLogic::s_GameBtnBack(908, 64, 0xf6f6f9, 0xeaeaf0, 0x5353c1, 0xe0e0eb, 0xffffff);	// 返回按钮
CPnt5 CLogic::s_GameSpeed1(871, 36, 0x212455, 0x1e214e, 0x292d6b, 0x212455, 0x181a3d);	// 第一关加速
CPnt5 CLogic::s_GameSpeed2(871, 36, 0x212455, 0x1e214e, 0x292d6b, 0x212455, 0x181a3d);	// 第二关加速
CPnt5 CLogic::s_GameSpeed3(871, 37, 0x1f2250, 0x1c1f49, 0x272b67, 0x1f2250, 0x161839);	// 第三关加速
//CPnt5 CLogic::s_Bounding1(95, 575, 0x469cb, 0x49b0da, 0xa1fdff, 0x26a6c4, 0x20d89b);		// 选择增益1步
CPnt5 CLogic::s_Bounding1(92, 577, 0x4d6a4, 0x4d6a4, 0x257c8, 0x9489, 0x4b37f);		// 选择增益1步
CPnt5 CLogic::s_Bounding2(399, 287, 0x3d5572, 0x5c7093, 0xc1d3dd, 0xd686e3, 0xef94ff);		// 选择增益2步
CPnt5 CLogic::s_Bounding3(442, 175, 0x92aded, 0xc9d2ff, 0x8092d2, 0x3f1b40, 0x3f1b40);		// 选择增益3步
CPnt5 CLogic::s_Bounding4(266, 448, 0x2f2d8a, 0xffffff, 0x373693, 0xcbcae6, 0x5050a4);		// 选择增益4步
CPnt5 CLogic::s_Random1(355, 301, 0xffffff, 0xefffff, 0x4f1ad8, 0x1a15b1, 0xffffff);		// 抽卡1步
CPnt5 CLogic::s_Random2(55, 326, 0x53c4, 0x53c4, 0xaa, 0x41c1, 0x1afde);		// 抽卡2步
CPnt5 CLogic::s_Random3(546, 422, 0x7ca6d5, 0x91b5f7, 0x325979, 0x698fb5, 0x4345c);		// 抽卡3步
CPnt5 CLogic::s_Random4(379, 410, 0x1b1bbf, 0xa4a4db, 0x1b12c0, 0xffffff, 0x3f3fc0);		// 抽卡4步
CRolePnt CLogic::s_ST1_Role1(CPnt5(161, 599, 0x525b5b, 0x49525b, 0xc9e4ff, 0x526480, 0x8992a4), 542, 340);		// 第1关角色1
CRolePnt CLogic::s_ST1_Role2(CPnt5(180, 595, 0x120900, 0x494040, 0x241b12, 0x363636, 0x5b5252), 506, 244);		// 第1关角色2
CRolePnt CLogic::s_ST1_Role3(CPnt5(164, 597, 0xdbffff, 0xd2f6ff, 0x243f5b, 0x5b9bf6, 0xb6c0b6), 433, 262);		// 第1关角色3
CRolePnt CLogic::s_ST1_Role4(CPnt5(137, 569, 0x2452bf, 0x91b49, 0x5bdbff, 0x4989db, 0x243f80), 576, 246);		// 第1关角色4
CRolePnt CLogic::s_ST1_Role5(CPnt5(143, 584, 0x9, 0xc0bfc0, 0x12122d, 0xedffff, 0x364064), 655, 251);		// 第1关角色5
CRolePnt CLogic::s_ST2_Role1(CPnt5(549, 601, 0x241b3f, 0x523f64, 0xd2e4ff, 0xedffff, 0x2d2d40), 551, 361);		// 第2关角色1
CRolePnt CLogic::s_ST2_Role2(CPnt5(348, 598, 0x7f807f, 0xbfc9bf, 0x3f3f3f, 0x404040, 0xc0d2bf), 494, 382);		// 第2关角色2
CRolePnt CLogic::s_ST2_Role3(CPnt5(152, 582, 0x2d3f6d, 0x6d7f80, 0x2d365b, 0xc9e4ff, 0x9122d), 379, 322);		// 第2关角色3
CRolePnt CLogic::s_ST2_Role4(CPnt5(71, 588, 0x5b769b, 0x809bc9, 0x5b7692, 0x2d1212, 0x1b1b24), 484, 302);		// 第2关角色4
CRolePnt CLogic::s_ST2_Role5(CPnt5(347, 594, 0x7f899b, 0xd2a464, 0x404040, 0xb6e4ff, 0xadd2ff), 364, 253);		// 第2关角色5
CRolePnt CLogic::s_ST3_Role1(CPnt5(151, 590, 0x364092, 0xc0d2e4, 0x12, 0xb6c9f6, 0x405bbf), 327, 256);		// 第3关角色1
CRolePnt CLogic::s_ST3_Role2(CPnt5(155, 597, 0x928992, 0x898080, 0xe4ffff, 0xa49ba4, 0x7f7676), 302, 396);		// 第3关角色2
CRolePnt CLogic::s_ST3_Role3(CPnt5(251, 577, 0xedffff, 0xbfd2e4, 0x4989db, 0xdbffff, 0xd2f6ff), 531, 472);		// 第3关角色3
CRolePnt CLogic::s_ST3_Role4(CPnt5(248, 579, 0x5b76a4, 0x12122d, 0x9bbfed, 0x8992bf, 0x767f9b), 385, 348);		// 第3关角色4
CRolePnt CLogic::s_ST3_Role5(CPnt5(343, 594, 0xd2a464, 0xb6641b, 0x6dadd2, 0x3f4980, 0x80491b), 467, 387);		// 第3关角色5


CLogic::CLogic()
{
}


CLogic::~CLogic()
{

}

CLogic* CLogic::getInstance()
{
	static CLogic ret;
	return &ret;
}

void CLogic::startPlay()
{
	uintptr_t hStdOut = _beginthread(ThreadPlaying, 0, NULL);
}

void CLogic::ThreadPlaying(void *)
{
	while (CCtrl::canPlay())
	{
 		getInstance()->startRegist();
 		getInstance()->waitTime(60);	// 等待注册
 
 		getInstance()->waitIcon_nothing();
 		getInstance()->playStory1();
 
 		getInstance()->waitEntry_clickOK();
 		getInstance()->playStory2();

		getInstance()->waitBound_clickOK();

		getInstance()->waitEntry_clickBack();
		getInstance()->playStory3();

		getInstance()->waitCard_clickOK();
		getInstance()->waitCard();	// 等待抽卡完成

		CFrame::getInstance()->saveImage();
		if (CCtrl::canPlay())
		{
			CFrame::getInstance()->closeChrome();
			getInstance()->waitTime(10);
		}
	}
	_endthread();
}

void CLogic::startRegist()
{
	CLogic::s_bWaitFor = true;
	ShellExecute(NULL, _T("open"), _T("chrome.exe"), _T("www.bccto.me"), _T(""), WM_SHOWWINDOW);
	cout << "______REGIST_START______" << endl;
}

void CLogic::playStory1()
{
	cout << "______PLAY_STORY_1______" << endl;
	waitRole_bySpeedup(&s_GameSpeed1, &s_ST1_Role1, true);
	waitRole_bySpeedup(&s_GameSpeed1, &s_ST1_Role2);
	waitRole_bySpeedup(&s_GameSpeed1, &s_ST1_Role3);
	waitRole_bySpeedup(&s_GameSpeed1, &s_ST1_Role4);
	waitRole_bySpeedup(&s_GameSpeed1, &s_ST1_Role5);
	CLogic::s_bWaitFor = true;
	waitOK_bySpeedup(&s_GameSpeed1);
}

void CLogic::playStory2()
{
	cout << "______PLAY_STORY_2______" << endl;
	waitRole_bySpeedup(&s_GameSpeed2, &s_ST2_Role1);
	CLogic::s_bWaitFor = true;
	waitRole_bySpeedup(&s_GameSpeed2, &s_ST2_Role2);
	CLogic::s_bWaitFor = true;
	waitRole_bySpeedup(&s_GameSpeed2, &s_ST2_Role3);
	CLogic::s_bWaitFor = true;
	waitRole_bySpeedup(&s_GameSpeed2, &s_ST2_Role4);
	CLogic::s_bWaitFor = true;
	waitRole_bySpeedup(&s_GameSpeed2, &s_ST2_Role5);
	CLogic::s_bWaitFor = true;
	waitOK_bySpeedup(&s_GameSpeed2);
}

void CLogic::playStory3()
{
	cout << "______PLAY_STORY_3______" << endl;
	waitRole_bySpeedup(&s_GameSpeed3, &s_ST3_Role1);
	waitRole_bySpeedup(&s_GameSpeed3, &s_ST3_Role2);
	waitRole_bySpeedup(&s_GameSpeed3, &s_ST3_Role3);
	waitRole_bySpeedup(&s_GameSpeed3, &s_ST3_Role4);
	waitRole_bySpeedup(&s_GameSpeed3, &s_ST3_Role5);
	CLogic::s_bWaitFor = true;
	waitOK_bySpeedup(&s_GameSpeed3);
}

void CLogic::waitIcon_nothing()
{
	cout << "______WAIT_ICON______" << endl;
	waitPnt_clickPnt(nullptr, &s_GameIcon);
}

void CLogic::waitEntry_clickOK()
{
	cout << "______WAIT_ENTRY_2______" << endl;
	waitPnt_clickPnt(&s_GameBtnOK, &s_GameStory);
}

void CLogic::waitBound_clickOK()
{
	cout << "______WAIT_BOUND______" << endl;
	waitPnt_clickPnt(&s_GameBtnOK, &s_Bounding1, true);
	waitPnt_clickPnt(nullptr, &s_Bounding2);
	waitPnt_clickPnt(nullptr, &s_Bounding3);
	waitPnt_clickPnt(nullptr, &s_Bounding4);
}

void CLogic::waitEntry_clickBack()
{
	cout << "______WAIT_ENTRY_3______" << endl;
	waitPnt_clickPnt(&s_GameBtnBack, &s_GameStory);
}

void CLogic::waitCard_clickOK()
{
	cout << "______WAIT_CARD______" << endl;
	waitPnt_clickPnt(&s_GameBtnOK, &s_Random1);
	waitPnt_clickPnt(nullptr, &s_Random2);
	waitPnt_clickPnt(nullptr, &s_Random3);
	waitPnt_clickPnt(nullptr, &s_Random4);
}

void CLogic::waitPnt_clickPnt(CPnt5* pClick, CPnt5* pWait, bool bfirst)
{
	LOOP_BEGIN
		if (pClick)
			pClick->click();
		if (pWait->find())
		{
			if (bfirst)
				waitTime(3);
			pWait->click();
			break;
		}
	LOOP_END(TIMEOUT_MAX_SECONDS)
}

void CLogic::waitRole_bySpeedup(CPnt5* pntSpeed, CRolePnt* role, bool bfirst)
{
	LOOP_BEGIN
		clickSpeedUp(pntSpeed);
		if (role->p5.find())
		{
			if (bfirst)
				waitTime(3);
			role->drag();
			break;
		}
	LOOP_END(TIMEOUT_MAX_SECONDS)
}


void CLogic::waitOK_bySpeedup(CPnt5* pntSpeed)
{
	LOOP_BEGIN
		clickSpeedUp(pntSpeed);
		if (s_GameBtnOK.find())
		{
			s_GameBtnOK.click();
			break;
		}
	LOOP_END(TIMEOUT_MAX_SECONDS)
}

void CLogic::clickSpeedUp(CPnt5* pntSpeed)
{
	if (!pntSpeed)
	{
		cout << "______ERR_PNT_SPEED_NULL______" << endl;
		return;
	}
	if (!pntSpeed->find())
	{
		pntSpeed->click();
	}
}
#if 0
void CLogic::waitCard()
{
	while (CCtrl::canPlay() && canWait())
	{
		Sleep(20);
		if (s_CardSilver.find())
		{
			waitTime(1);
			break;
		}
		if (s_CardGold.find())
		{
			waitTime(2);
			break;
		}
		if (s_CardWhite.find())
		{
			waitTime(3);
			break;
		}
		if (s_CardBlack.find())
		{
			waitTime(4);
			break;
		}
	}
}
#else
void CLogic::waitCard()
{
	LOOP_BEGIN
		Sleep(20);
		if (s_CardSilver.find())
		{
			waitTime(1);
			break;
		}
		if (s_CardGold.find())
		{
			waitTime(2);
			break;
		}
		if (s_CardWhite.find())
		{
			waitTime(3);
			break;
		}
		if (s_CardBlack.find())
		{
			waitTime(4);
			break;
		}
	LOOP_END(20)
}
#endif
void CLogic::waitTime(size_t nseconds)
{
	LOOP_BEGIN
		Sleep(100);
		size_t dt = GetTickCount() - bt;
		if (dt >= nseconds*1000)
		{
			break;
		}
	}
}

void CLogic::DetectTimeout(size_t bt, size_t iSecs)
{
	size_t dt = GetTickCount() - bt;
	if (dt >= iSecs * 1000)
	{
		CLogic::s_bWaitFor = false;		// 结束本次首抽，进行下一轮
		cout << "______TIME_OUT_" << iSecs << "______"<< endl;
	}
}


bool CLogic::canWait()
{
	return CLogic::s_bWaitFor;
}

