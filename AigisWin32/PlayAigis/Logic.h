#pragma once
class CPnt5;
class CRolePnt;
class CLogic
{
public:
	static CLogic* getInstance();

	void startPlay();

	// 启动注册流程
	void startRegist();

protected:

	void playStory1();

	void playStory2();

	void playStory3();

	// 什么都不做，直到游戏开始
	void waitIcon_nothing();

	// 点击确认， 直到第二关入口
	void waitEntry_clickOK();

	// 点击确认， 直到选择增益
	void waitBound_clickOK();

	// 点击返回， 直到第三关入口
	void waitEntry_clickBack();

	// 点击确认， 直到可以抽卡
	void waitCard_clickOK();


private:
	void waitPnt_clickPnt(CPnt5* pClick, CPnt5* pWait, bool bfirst = false);

	// 点击加速， 直到角色上场
	void waitRole_bySpeedup(CPnt5* pntSpeed, CRolePnt* role, bool bfirst = false);

	// 点击加速， 直到完成关卡
	void waitOK_bySpeedup(CPnt5* pntSpeed);

	// 点击加速, 满足条件
	void clickSpeedUp(CPnt5* pntSpeed);

	void waitCard();

	// 等待
	void waitTime(size_t nseconds);

	// 超时重玩
	static void DetectTimeout(size_t bt, size_t iSecs);

	// 超时前都可以等待
	static bool canWait();

	// 线程主循环
	static void ThreadPlaying(void *);

private:
	CLogic();
	~CLogic();
	static bool s_bWaitFor;			// 没超时继续等待

	static CPnt5 s_CardSilver;
	static CPnt5 s_CardGold;
	static CPnt5 s_CardWhite;
	static CPnt5 s_CardBlack;
		   
	static CPnt5 s_GameIcon;		// 游戏开始图标
	static CPnt5 s_GameStory;		// 第二关第三关入口
	static CPnt5 s_GameBtnOK;		// 确认按钮
	static CPnt5 s_GameBtnBack;		// 返回按钮
	static CPnt5 s_GameSpeed1;		// 第一关加速
	static CPnt5 s_GameSpeed2;		// 第二关加速
	static CPnt5 s_GameSpeed3;		// 第三关加速
	static CPnt5 s_Bounding1;		// 选择增益1步
	static CPnt5 s_Bounding2;		// 选择增益2步
	static CPnt5 s_Bounding3;		// 选择增益3步
	static CPnt5 s_Bounding4;		// 选择增益4步
	static CPnt5 s_Random1;			// 抽卡1步
	static CPnt5 s_Random2;			// 抽卡2步
	static CPnt5 s_Random3;			// 抽卡3步
	static CPnt5 s_Random4;			// 抽卡4步
	static CRolePnt s_ST1_Role1;		// 第1关角色1
	static CRolePnt s_ST1_Role2;		// 第1关角色2
	static CRolePnt s_ST1_Role3;		// 第1关角色3
	static CRolePnt s_ST1_Role4;		// 第1关角色4
	static CRolePnt s_ST1_Role5;		// 第1关角色5
	static CRolePnt s_ST2_Role1;		// 第2关角色1
	static CRolePnt s_ST2_Role2;		// 第2关角色2
	static CRolePnt s_ST2_Role3;		// 第2关角色3
	static CRolePnt s_ST2_Role4;		// 第2关角色4
	static CRolePnt s_ST2_Role5;		// 第2关角色5
	static CRolePnt s_ST3_Role1;		// 第3关角色1
	static CRolePnt s_ST3_Role2;		// 第3关角色2
	static CRolePnt s_ST3_Role3;		// 第3关角色3
	static CRolePnt s_ST3_Role4;		// 第3关角色4
	static CRolePnt s_ST3_Role5;		// 第3关角色5
};

