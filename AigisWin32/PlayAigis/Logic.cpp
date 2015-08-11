#include "stdafx.h"
#include "Logic.h"
#include "Ctrl.h"
#include "Pnt5.h"
#include "Frame.h"
#include <process.h>


#define LOOP_BEGIN	size_t bt = GetTickCount();	while (CCtrl::canPlay() && canWait()) {
#define LOOP_END(sec)	DetectTimeout(bt, sec);}

bool CLogic::s_bWaitFor = true;

CPnt5 CLogic::s_GameIcon(0, 0, 0, 0, 0, 0, 0);		// ��ʼ������ϷLOGO
CPnt5 CLogic::s_GameStory(0, 0, 0, 0, 0, 0, 0);		// �ڶ��ص��������
CPnt5 CLogic::s_GameBtnOK(0, 0, 0, 0, 0, 0, 0);		// ȷ�ϰ�ť
CPnt5 CLogic::s_GameBtnBack(0, 0, 0, 0, 0, 0, 0);	// ���ذ�ť
CPnt5 CLogic::s_GameSpeed1(0, 0, 0, 0, 0, 0, 0);	// ��һ�ؼ���
CPnt5 CLogic::s_GameSpeed2(0, 0, 0, 0, 0, 0, 0);	// �ڶ��ؼ���
CPnt5 CLogic::s_GameSpeed3(0, 0, 0, 0, 0, 0, 0);	// �����ؼ���
CPnt5 CLogic::s_Bounding1(0, 0, 0, 0, 0, 0, 0);		// ѡ������1��
CPnt5 CLogic::s_Bounding2(0, 0, 0, 0, 0, 0, 0);		// ѡ������2��
CPnt5 CLogic::s_Bounding3(0, 0, 0, 0, 0, 0, 0);		// ѡ������3��
CPnt5 CLogic::s_Bounding4(0, 0, 0, 0, 0, 0, 0);		// ѡ������4��
CPnt5 CLogic::s_Random1(0, 0, 0, 0, 0, 0, 0);		// �鿨1��
CPnt5 CLogic::s_Random2(0, 0, 0, 0, 0, 0, 0);		// �鿨2��
CPnt5 CLogic::s_Random3(0, 0, 0, 0, 0, 0, 0);		// �鿨3��
CPnt5 CLogic::s_Random4(0, 0, 0, 0, 0, 0, 0);		// �鿨4��
CRolePnt CLogic::s_ST1_Role1(CPnt5(0, 0, 0, 0, 0, 0, 0), 0, 0);		// ��1�ؽ�ɫ1
CRolePnt CLogic::s_ST1_Role2(CPnt5(0, 0, 0, 0, 0, 0, 0), 0, 0);		// ��1�ؽ�ɫ2
CRolePnt CLogic::s_ST1_Role3(CPnt5(0, 0, 0, 0, 0, 0, 0), 0, 0);		// ��1�ؽ�ɫ3
CRolePnt CLogic::s_ST1_Role4(CPnt5(0, 0, 0, 0, 0, 0, 0), 0, 0);		// ��1�ؽ�ɫ4
CRolePnt CLogic::s_ST1_Role5(CPnt5(0, 0, 0, 0, 0, 0, 0), 0, 0);		// ��1�ؽ�ɫ5
CRolePnt CLogic::s_ST2_Role1(CPnt5(0, 0, 0, 0, 0, 0, 0), 0, 0);		// ��2�ؽ�ɫ1
CRolePnt CLogic::s_ST2_Role2(CPnt5(0, 0, 0, 0, 0, 0, 0), 0, 0);		// ��2�ؽ�ɫ2
CRolePnt CLogic::s_ST2_Role3(CPnt5(0, 0, 0, 0, 0, 0, 0), 0, 0);		// ��2�ؽ�ɫ3
CRolePnt CLogic::s_ST2_Role4(CPnt5(0, 0, 0, 0, 0, 0, 0), 0, 0);		// ��2�ؽ�ɫ4
CRolePnt CLogic::s_ST2_Role5(CPnt5(0, 0, 0, 0, 0, 0, 0), 0, 0);		// ��2�ؽ�ɫ5
CRolePnt CLogic::s_ST3_Role1(CPnt5(0, 0, 0, 0, 0, 0, 0), 0, 0);		// ��3�ؽ�ɫ1
CRolePnt CLogic::s_ST3_Role2(CPnt5(0, 0, 0, 0, 0, 0, 0), 0, 0);		// ��3�ؽ�ɫ2
CRolePnt CLogic::s_ST3_Role3(CPnt5(0, 0, 0, 0, 0, 0, 0), 0, 0);		// ��3�ؽ�ɫ3
CRolePnt CLogic::s_ST3_Role4(CPnt5(0, 0, 0, 0, 0, 0, 0), 0, 0);		// ��3�ؽ�ɫ4
CRolePnt CLogic::s_ST3_Role5(CPnt5(0, 0, 0, 0, 0, 0, 0), 0, 0);		// ��3�ؽ�ɫ5


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
		getInstance()->waitTime(10);	// �ȴ�ע��

		getInstance()->waitIcon_nothing();
		getInstance()->playStory1();

		getInstance()->waitEntry_clickOK();
		getInstance()->playStory2();

		getInstance()->waitBound_clickOK();

		getInstance()->waitEntry_clickBack();
		getInstance()->playStory3();

		getInstance()->waitCard_clickOK();
		getInstance()->waitTime(20);	// �ȴ��鿨���
		CFrame::getInstance()->saveImage();
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
	waitOK_bySpeedup(&s_GameSpeed1);
}

void CLogic::playStory2()
{
	cout << "______PLAY_STORY_2______" << endl;
	waitRole_bySpeedup(&s_GameSpeed2, &s_ST2_Role1);
	waitRole_bySpeedup(&s_GameSpeed2, &s_ST2_Role2);
	waitRole_bySpeedup(&s_GameSpeed2, &s_ST2_Role3);
	waitRole_bySpeedup(&s_GameSpeed2, &s_ST2_Role4);
	waitRole_bySpeedup(&s_GameSpeed2, &s_ST2_Role5);
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
	waitPnt_clickPnt(&s_GameBtnOK, &s_Bounding1);
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

void CLogic::waitPnt_clickPnt(CPnt5* pClick, CPnt5* pWait)
{
	LOOP_BEGIN
		if (pClick)
			pClick->click();
		if (pWait->find())
		{
			pWait->click();
			break;
		}
	LOOP_END(120)
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
	LOOP_END(120)
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
	LOOP_END(120)
}

void CLogic::clickSpeedUp(CPnt5* pntSpeed)
{
	if (!pntSpeed)
	{
		cout << "______ERR_PNT_SPEED_NULL______" << endl;
		return;
	}
	if (pntSpeed->find())
	{
		pntSpeed->click();
	}
}

void CLogic::waitTime(int nseconds)
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
		CLogic::s_bWaitFor = false;		// ���������׳飬������һ��
		cout << "______TIME_OUT_" << iSecs << "______"<< endl;
	}
}


bool CLogic::canWait()
{
	return CLogic::s_bWaitFor;
}

