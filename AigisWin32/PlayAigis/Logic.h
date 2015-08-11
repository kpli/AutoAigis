#pragma once
class CPnt5;
class CRolePnt;
class CLogic
{
public:
	static CLogic* getInstance();

	void startPlay();

	// ����ע������
	void startRegist();

protected:

	void playStory1();

	void playStory2();

	void playStory3();

	// ʲô��������ֱ����Ϸ��ʼ
	void waitIcon_nothing();

	// ���ȷ�ϣ� ֱ���ڶ������
	void waitEntry_clickOK();

	// ���ȷ�ϣ� ֱ��ѡ������
	void waitBound_clickOK();

	// ������أ� ֱ�����������
	void waitEntry_clickBack();

	// ���ȷ�ϣ� ֱ�����Գ鿨
	void waitCard_clickOK();


private:
	void waitPnt_clickPnt(CPnt5* pClick, CPnt5* pWait, bool bfirst = false);

	// ������٣� ֱ����ɫ�ϳ�
	void waitRole_bySpeedup(CPnt5* pntSpeed, CRolePnt* role, bool bfirst = false);

	// ������٣� ֱ����ɹؿ�
	void waitOK_bySpeedup(CPnt5* pntSpeed);

	// �������, ��������
	void clickSpeedUp(CPnt5* pntSpeed);

	void waitCard();

	// �ȴ�
	void waitTime(size_t nseconds);

	// ��ʱ����
	static void DetectTimeout(size_t bt, size_t iSecs);

	// ��ʱǰ�����Եȴ�
	static bool canWait();

	// �߳���ѭ��
	static void ThreadPlaying(void *);

private:
	CLogic();
	~CLogic();
	static bool s_bWaitFor;			// û��ʱ�����ȴ�

	static CPnt5 s_CardSilver;
	static CPnt5 s_CardGold;
	static CPnt5 s_CardWhite;
	static CPnt5 s_CardBlack;
		   
	static CPnt5 s_GameIcon;		// ��Ϸ��ʼͼ��
	static CPnt5 s_GameStory;		// �ڶ��ص��������
	static CPnt5 s_GameBtnOK;		// ȷ�ϰ�ť
	static CPnt5 s_GameBtnBack;		// ���ذ�ť
	static CPnt5 s_GameSpeed1;		// ��һ�ؼ���
	static CPnt5 s_GameSpeed2;		// �ڶ��ؼ���
	static CPnt5 s_GameSpeed3;		// �����ؼ���
	static CPnt5 s_Bounding1;		// ѡ������1��
	static CPnt5 s_Bounding2;		// ѡ������2��
	static CPnt5 s_Bounding3;		// ѡ������3��
	static CPnt5 s_Bounding4;		// ѡ������4��
	static CPnt5 s_Random1;			// �鿨1��
	static CPnt5 s_Random2;			// �鿨2��
	static CPnt5 s_Random3;			// �鿨3��
	static CPnt5 s_Random4;			// �鿨4��
	static CRolePnt s_ST1_Role1;		// ��1�ؽ�ɫ1
	static CRolePnt s_ST1_Role2;		// ��1�ؽ�ɫ2
	static CRolePnt s_ST1_Role3;		// ��1�ؽ�ɫ3
	static CRolePnt s_ST1_Role4;		// ��1�ؽ�ɫ4
	static CRolePnt s_ST1_Role5;		// ��1�ؽ�ɫ5
	static CRolePnt s_ST2_Role1;		// ��2�ؽ�ɫ1
	static CRolePnt s_ST2_Role2;		// ��2�ؽ�ɫ2
	static CRolePnt s_ST2_Role3;		// ��2�ؽ�ɫ3
	static CRolePnt s_ST2_Role4;		// ��2�ؽ�ɫ4
	static CRolePnt s_ST2_Role5;		// ��2�ؽ�ɫ5
	static CRolePnt s_ST3_Role1;		// ��3�ؽ�ɫ1
	static CRolePnt s_ST3_Role2;		// ��3�ؽ�ɫ2
	static CRolePnt s_ST3_Role3;		// ��3�ؽ�ɫ3
	static CRolePnt s_ST3_Role4;		// ��3�ؽ�ɫ4
	static CRolePnt s_ST3_Role5;		// ��3�ؽ�ɫ5
};

