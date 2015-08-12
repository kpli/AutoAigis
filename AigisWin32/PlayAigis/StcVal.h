#pragma once
class CStcVal
{
public:
	CStcVal();
	~CStcVal();

public:

	static CPnt5 s_CardSilver;		// ����
	static CPnt5 s_CardGold;		// ��
	static CPnt5 s_CardWhite;		// �׽�
	static CPnt5 s_CardBlack;		// �ڽ�

	static CPnt5 s_GameIcon;		// ��ʼ������ϷLOGO
	static CPnt5 s_GameStory;		// �ڶ��ص��������
	static CPnt5 s_GameBtnOK;		// ȷ�ϰ�ť
	static CPnt5 s_GameBtnBack;		// ���ذ�ť

	static CPnt5 s_GameSpeed1;		// ��1�ؼ���
	static CPnt5 s_GameSpeed2;		// ��2�ؼ���
	static CPnt5 s_GameSpeed3;		// ��3�ؼ���
	static CPnt5 s_GameSpeed4;		// ��4�ؼ���
	static CPnt5 s_GameSpeed5;		// ��5�ؼ���
	static CPnt5 s_GameSpeed6;		// ��6�ؼ���
	static CPnt5 s_GameSpeed7;		// ��7�ؼ���

	//static CPnt5 s_Bounding1;		// ѡ������1��
	static CPnt5 s_Bounding1;		// ѡ������1��
	static CPnt5 s_Bounding2;		// ѡ������2��
	static CPnt5 s_Bounding3;		// ѡ������3��
	static CPnt5 s_Bounding4;		// ѡ������4��

	static CPnt5 s_Random1;			// �鿨1��
	static CPnt5 s_Random2;			// �鿨2��
	static CPnt5 s_Random3;			// �鿨3��
	static CPnt5 s_Random4;			// �鿨4��

	
	static RECT s_rcRange;				// ������ɫ�ķ�Χ (for got the form size)
	static COLORREF s_arrColor[5];		// Ҫ��������ɫ (for got the form size)
	static CPnt5 s_pnt5Rider;			// ��ʿ��������������ɫ
	static CPnt5 s_GameUnit1;			// ѡ����ʿ1��
	static CPnt5 s_GameUnit2;			// ѡ����ʿ2��
	static CPnt5 s_GameUnit3;			// ѡ����ʿ3��
	static CPnt5 s_GameUnit4;			// ѡ����ʿ4��, ����ϰ��������ͼ
	static CPnt5 s_GameUnit5;			// ѡ����ʿ5��

	static CPnt5 s_SelectStory0_1;		// ѡ���x��
	static CPnt5 s_SelectStory4_2;		// ѡ���4��
	static CPnt5 s_SelectStory5_2;		// ѡ���5��
	static CPnt5 s_SelectStory6_2;		// ѡ���6��
	static CPnt5 s_SelectStory7_2;		// ѡ���7��
	static CPnt5 s_SelectStory0_3;		// ѡ���x��
	static CPnt5 s_SelectStory0_4;		// ѡ���x��

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

	static CRolePnt s_ST4_Role1;		// ��4�ؽ�ɫ1
	static CRolePnt s_ST4_Role2;		// ��4�ؽ�ɫ2
	static CRolePnt s_ST4_Role3;		// ��4�ؽ�ɫ3
	static CRolePnt s_ST4_Role4;		// ��4�ؽ�ɫ4
	static CRolePnt s_ST4_Role5;		// ��4�ؽ�ɫ5
	static CRolePnt s_ST4_Role6;		// ��4�ؽ�ɫ6
	static CRolePnt s_ST4_Role7;		// ��4�ؽ�ɫ7
	static CRolePnt s_ST4_Role8;		// ��4�ؽ�ɫ8

	static CRolePnt s_ST5_Role1;		// ��5�ؽ�ɫ1
	static CRolePnt s_ST5_Role2;		// ��5�ؽ�ɫ2
	static CRolePnt s_ST5_Role3;		// ��5�ؽ�ɫ3
	static CRolePnt s_ST5_Role4;		// ��5�ؽ�ɫ4
	static CRolePnt s_ST5_Role5;		// ��5�ؽ�ɫ5
	static CRolePnt s_ST5_Role6;		// ��5�ؽ�ɫ6
	static CRolePnt s_ST5_Role7;		// ��5�ؽ�ɫ7

	static CRolePnt s_ST6_Role1;		// ��6�ؽ�ɫ1
	static CRolePnt s_ST6_Role2;		// ��6�ؽ�ɫ2
	static CRolePnt s_ST6_Role3;		// ��6�ؽ�ɫ3
	static CRolePnt s_ST6_Role4;		// ��6�ؽ�ɫ4
	static CRolePnt s_ST6_Role5;		// ��6�ؽ�ɫ5
	static CRolePnt s_ST6_Role6;		// ��6�ؽ�ɫ6
	static CRolePnt s_ST6_Role7;		// ��6�ؽ�ɫ7

	static CRolePnt s_ST7_Role1;		// ��7�ؽ�ɫ1
	static CRolePnt s_ST7_Role2;		// ��7�ؽ�ɫ2
	static CRolePnt s_ST7_Role3;		// ��7�ؽ�ɫ3
	static CRolePnt s_ST7_Role4;		// ��7�ؽ�ɫ4
	static CRolePnt s_ST7_Role5;		// ��7�ؽ�ɫ5
	static CRolePnt s_ST7_Role6;		// ��7�ؽ�ɫ6

};

// --END
