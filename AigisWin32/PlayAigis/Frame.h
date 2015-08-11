#pragma once
class CFrame
{
public:
	static CFrame* getInstance();

	HWND aigisHwnd();
	void rePlay();
	void getAccount(LPTSTR lpBuf, int maxLen);
private:
	CFrame();
	~CFrame();
	HWND m_hFocus;
};

