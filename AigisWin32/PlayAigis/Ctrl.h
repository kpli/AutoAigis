#pragma once
class CCtrl
{

public:
	CCtrl();
	~CCtrl();

	// ע�Ტ�����ȼ�
	void initHotKey();

	// �߳��Ƿ���Լ���
	static bool canPlay();

private:
	void stop();
	void start();
	static bool s_bEffect;
};

