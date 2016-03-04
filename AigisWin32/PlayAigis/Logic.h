#pragma once
class CLogic
{
public:
	static CLogic* getInstance();
	
	void setWebSite(wchar_t* websit);
	void startPlay();
	void startTest();

protected:
	void FirstRondomCard();
	void SecondRondomCard();
	
protected:

	// ѡ����ʿ
	void selectUnit();

	void selectStory4567(CPnt5* pStoryEntry);

	// ѡ���4��
	void playStory4();

	// ѡ���5��
	void playStory5();


	// ѡ���6��
	void playStory6();

	// ѡ���7��
	void playStory7();


protected:
	// ����ע������
	void startRegist();

	void playStory1();

	void playStory2();

	void playStory3();

	// ʲô��������ֱ����Ϸ��ʼ
	void waitIcon_nothing();

	// ���ȷ�ϣ� ֱ���ڶ������
	void waitEntry_clickOK();

	// ���ȷ�ϣ� ֱ��ѡ������
	void waitBound_clickOK();

	// ������أ� ֱ���������Ĺ����
	void waitEntry_clickBack();

	// ���ȷ�ϣ� ֱ����ʾ���ذ�ť
	void waitBack_clickOK();

	// ���ȷ�ϣ� ֱ�����Գ鿨
	void waitCard_clickOK();
	void waitCard_clickOK2();


private:
	void waitPnt_clickPnt(CPnt5* pClick, CPnt5* pWait, bool bfirst = true);

	// ������٣� ֱ����ɫ�ϳ�
	void waitRole_bySpeedup(CPnt5* pntSpeed, CRolePnt* role, bool bfirst = true);

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

	// ����ѭ��
	static void ThreadTest(void *);
private:
	CLogic();
	~CLogic();
	static bool s_bWaitFor;			// û��ʱ�����ȴ�
	static int s_iCardStar;		// ���Զ���
	wchar_t* s_website;
};

