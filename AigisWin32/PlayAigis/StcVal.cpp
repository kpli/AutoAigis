#include "stdafx.h"
#include "StcVal.h"


CStcVal::CStcVal()
{
}


CStcVal::~CStcVal()
{
}

CPnt5 CStcVal::s_CardSilver(205, 573, 0xb1b1b1, 0x878787, 0x9a9a9a, 0x9f9f9f, 0xa6a6a6);	// ����
CPnt5 CStcVal::s_CardGold(204, 576, 0x3af9ff, 0x1feff, 0x15e3f1, 0x39e8f3, 0x2b1cc);		// ��
CPnt5 CStcVal::s_CardWhite(203, 575, 0xecede9, 0xbbbdb2, 0xadb0a5, 0xfcfdfc, 0xe0e1dc);	// �׽�
CPnt5 CStcVal::s_CardBlack(155, 574, 0x1879d, 0x13b47, 0x1414d, 0x35a66, 0x24f5f);		// �ڽ�

CPnt5 CStcVal::s_GameIcon(452, 203, 0x1615bc, 0x2423f8, 0x5958f3, 0x1413a5, 0x1413a5);	// ��ʼ������ϷLOGO
CPnt5 CStcVal::s_GameStory(592, 175, 0xdce8ff, 0xe4efff, 0x302e2d, 0xa3c1a1, 0xeaf4ff);	// �ڶ��ص��������
CPnt5 CStcVal::s_GameBtnOK(474, 424, 0xffffff, 0xb67600, 0xffffff, 0xad6400, 0xbf7600);	// ȷ�ϰ�ť
CPnt5 CStcVal::s_GameBtnBack(892, 67, 0xc0cb2, 0xc0cac, 0x101094, 0xa4a4b0, 0x3737cd);	// ���ذ�ť

CPnt5 CStcVal::s_GameSpeed1(871, 36, 0x212455, 0x1e214e, 0x292d6b, 0x212455, 0x181a3d);	// ��1�ؼ���
CPnt5 CStcVal::s_GameSpeed2(871, 36, 0x212455, 0x1e214e, 0x292d6b, 0x212455, 0x181a3d);	// ��2�ؼ���
CPnt5 CStcVal::s_GameSpeed3(871, 37, 0x1f2250, 0x1c1f49, 0x272b67, 0x1f2250, 0x161839);	// ��3�ؼ���
CPnt5 CStcVal::s_GameSpeed4(872, 36, 0x212455, 0x212455, 0x292d6b, 0x212455, 0x181a3d);	// ��4�ؼ���
CPnt5 CStcVal::s_GameSpeed5(870, 39, 0x1b1e47, 0xe0f24, 0x24285e, 0x1b1e47, 0x121430);	// ��5�ؼ���
CPnt5 CStcVal::s_GameSpeed6(872, 39, 0x1b1e47, 0x1b1e47, 0x24285e, 0x1b1e47, 0x121430);	// ��6�ؼ���
CPnt5 CStcVal::s_GameSpeed7(871, 36, 0x212455, 0x1e214e, 0x292d6b, 0x212455, 0x181a3d);	// ��7�ؼ���

CPnt5 CStcVal::s_Bounding1(93, 563, 0xcfffff, 0x152ca, 0xe2ffff, 0xa6ebff, 0xa5f6ff);			// ѡ������1��
CPnt5 CStcVal::s_Bounding2(398, 286, 0xf098ff, 0xae6eb9, 0xef95ff, 0x1e3d50, 0xef94ff);	// ѡ������2��
CPnt5 CStcVal::s_Bounding3(430, 166, 0xe4f6ff, 0xedf6ff, 0xedf6ff, 0xe4edff, 0xb6c0ff);	// ѡ������3��
CPnt5 CStcVal::s_Bounding4(256, 454, 0xf3f3fa, 0x282491, 0x6562cb, 0x2d2a91, 0x201d95);	// ѡ������4��

CPnt5 CStcVal::s_Random1(355, 301, 0xb2bad4, 0x3b51bb, 0xbcc0d6, 0x9a96a9, 0x4062d9);		// �鿨1��
CPnt5 CStcVal::s_Random2(57, 318, 0x32bd, 0x44a0e8, 0x2ab9, 0x147ddb, 0x54e9ff);					// �鿨2��
CPnt5 CStcVal::s_Random3(395, 442, 0x72ae7, 0x6578d8, 0xecfbff, 0x71e1fb, 0x2037d1);		// �鿨3��
CPnt5 CStcVal::s_Random4(392, 419, 0xad, 0xc0c0ed, 0x1b12c0, 0x9b92e4, 0xb6);		// �鿨4��

// for got the form size
RECT CStcVal::s_rcRange;			// ������ɫ�ķ�Χ
COLORREF CStcVal::s_arrColor[5];	// Ҫ��������ɫ

CPnt5 CStcVal::s_pnt5Rider(444, 180, 0xa464ad, 0xbfedff, 0x9bc0ff, 0x643f64, 0x522d40);	// ��ʿ��������������ɫ
CPnt5 CStcVal::s_GameUnit1(s_Random1);													// ѡ����ʿ1��
CPnt5 CStcVal::s_GameUnit2(107, 227, 0x3bc0, 0xc5ffff, 0x32bd, 0x41c3, 0xb8feff);			// ѡ����ʿ2��
CPnt5 CStcVal::s_GameUnit3(323, 155, 0x31211b, 0x693515, 0x522c14, 0xa9e2fc, 0x552b15);	// ѡ����ʿ3��
CPnt5 CStcVal::s_GameUnit4(564, 311, 0x6c3400, 0x6c3400, 0x713500, 0x6c3400, 0x743700);	// ѡ����ʿ4��, ����ϰ��������ͼ
CPnt5 CStcVal::s_GameUnit5(265, 532, 0xffffff, 0xd7d7ef, 0x211d8a, 0x2f2c96, 0x2e2b94);	// ѡ����ʿ5��

CPnt5 CStcVal::s_scrollCtrl(939, 116, 0x334f77, 0x335c80, 0x334f77, 0x33597d, 0x334f77);
CPnt5 CStcVal::s_SelectStory0_1(347, 198, 0x28449e, 0x162167, 0x28449e, 0x132589, 0x10);		// ѡ���x�أ� new��ǩ
CPnt5 CStcVal::s_SelectStory4_2(632, 114, 0x3633b2, 0x6b68ef, 0x496fc3, 0x4f45b1, 0x3634b2);		// ѡ���4��
CPnt5 CStcVal::s_SelectStory5_2(632, 114, 0x3633b2, 0x6b68ef, 0x496fc3, 0x4f45b1, 0x3634b2);		// ѡ���5��
CPnt5 CStcVal::s_SelectStory6_2(632, 114, 0x3633b2, 0x6b68ef, 0x496fc3, 0x4f45b1, 0x3634b2);		// ѡ���6��
CPnt5 CStcVal::s_SelectStory7_2(632, 114, 0x3633b2, 0x6b68ef, 0x496fc3, 0x4f45b1, 0x3634b2);		// ѡ���7��
CPnt5 CStcVal::s_SelectStory0_3(359, 564, 0xf9f9f9, 0x8030a, 0xffffff, 0xb5, 0xf2f2f2);		// ѡ���x�أ���ʼ��ť
CPnt5 CStcVal::s_SelectStory0_4(387, 534, 0x20104, 0xe6e6e6, 0x20104, 0x1213b6, 0x20104);		// ѡ���x�أ�ȷ�Ͽ�ʼ

CRolePnt CStcVal::s_ST1_Role1(CPnt5(161, 599, 0x525b5b, 0x49525b, 0xc9e4ff, 0x526480, 0x8992a4), 542, 340);		// ��1�ؽ�ɫ1
CRolePnt CStcVal::s_ST1_Role2(CPnt5(180, 595, 0x120900, 0x494040, 0x241b12, 0x363636, 0x5b5252), 506, 244);		// ��1�ؽ�ɫ2
CRolePnt CStcVal::s_ST1_Role3(CPnt5(164, 597, 0xdbffff, 0xd2f6ff, 0x243f5b, 0x5b9bf6, 0xb6c0b6), 433, 262);		// ��1�ؽ�ɫ3
CRolePnt CStcVal::s_ST1_Role4(CPnt5(137, 569, 0x2452bf, 0x91b49, 0x5bdbff, 0x4989db, 0x243f80), 576, 246);		// ��1�ؽ�ɫ4
CRolePnt CStcVal::s_ST1_Role5(CPnt5(145, 582, 0x404064, 0xffffff, 0xadc0e4, 0xf6ffff, 0xadc9e4), 655, 251);			// ��1�ؽ�ɫ5
CRolePnt CStcVal::s_ST2_Role1(CPnt5(549, 601, 0x646d80, 0x646d89, 0xe4edff, 0xf6ffff, 0x646d80), 551, 361);		// ��2�ؽ�ɫ1
CRolePnt CStcVal::s_ST2_Role2(CPnt5(348, 598, 0x7f807f, 0xbfc9bf, 0x3f3f3f, 0x404040, 0xc0d2bf), 494, 382);		// ��2�ؽ�ɫ2
CRolePnt CStcVal::s_ST2_Role3(CPnt5(152, 582, 0x2d3f6d, 0x6d7f80, 0x2d365b, 0xc9e4ff, 0x9122d), 379, 322);		// ��2�ؽ�ɫ3
CRolePnt CStcVal::s_ST2_Role4(CPnt5(71, 588, 0x5b769b, 0x809bc9, 0x5b7692, 0x2d1212, 0x1b1b24), 484, 302);		// ��2�ؽ�ɫ4
CRolePnt CStcVal::s_ST2_Role5(CPnt5(347, 594, 0x7f899b, 0xd2a464, 0x404040, 0xb6e4ff, 0xadd2ff), 364, 253);		// ��2�ؽ�ɫ5
CRolePnt CStcVal::s_ST3_Role1(CPnt5(151, 590, 0x364092, 0xc0d2e4, 0x12, 0xb6c9f6, 0x405bbf), 327, 256);			// ��3�ؽ�ɫ1
CRolePnt CStcVal::s_ST3_Role2(CPnt5(155, 597, 0x928992, 0x898080, 0xe4ffff, 0xa49ba4, 0x7f7676), 302, 396);		// ��3�ؽ�ɫ2
CRolePnt CStcVal::s_ST3_Role3(CPnt5(251, 577, 0xedffff, 0xbfd2e4, 0x4989db, 0xdbffff, 0xd2f6ff), 531, 472);		// ��3�ؽ�ɫ3
CRolePnt CStcVal::s_ST3_Role4(CPnt5(249, 584, 0x7f92b6, 0xf6f6ed, 0xd2e4f6, 0xedf6ff, 0x495264), 385, 348);		// ��3�ؽ�ɫ4
CRolePnt CStcVal::s_ST3_Role5(CPnt5(343, 594, 0xd2a464, 0xb6641b, 0x6dadd2, 0x3f4980, 0x80491b), 467, 387);		// ��3�ؽ�ɫ5

CRolePnt CStcVal::s_ST4_Role1(CPnt5(170, 581, 0x5276d2, 0x89b6ff, 0x808080, 0x90912, 0x7692db), 431, 239);		// ��4�ؽ�ɫ1
CRolePnt CStcVal::s_ST4_Role2(CPnt5(151, 594, 0x524952, 0x403f40, 0x7680ad, 0xedffff, 0x807f7f), 656, 241);		// ��4�ؽ�ɫ2
CRolePnt CStcVal::s_ST4_Role4(CPnt5(139, 583, 0x5b89f6, 0x1b, 0x6480c0, 0xedffff, 0xededed), 759, 277);		// ��4�ؽ�ɫ3
CRolePnt CStcVal::s_ST4_Role3(CPnt5(52, 585, 0x405b80, 0x5b6d76, 0x2d3f52, 0x1b121b, 0x405b80), 322, 261);		// ��4�ؽ�ɫ4
CRolePnt CStcVal::s_ST4_Role5(CPnt5(451, 587, 0x76766d, 0x40493f, 0x6d7664, 0x9ba492, 0x7f7f6d), 551, 213);		// ��4�ؽ�ɫ5
CRolePnt CStcVal::s_ST4_Role6(CPnt5(354, 592, 0x527f92, 0xa4c0ff, 0xbfedff, 0x89c0db, 0xbfedff), 465, 304);		// ��4�ؽ�ɫ6
CRolePnt CStcVal::s_ST4_Role7(CPnt5(241, 583, 0x3f36ad, 0x924989, 0x90909, 0xc05bd2, 0x6d49ad), 595, 310);		// ��4�ؽ�ɫ7
CRolePnt CStcVal::s_ST4_Role8(CPnt5(138, 581, 0x5b649b, 0xb6c9e4, 0x8092a4, 0x40496d, 0xadc0e4), 665, 337);		// ��4�ؽ�ɫ8

CRolePnt CStcVal::s_ST5_Role1(CPnt5(453, 576, 0xb6dbff, 0x76525b, 0x499bed, 0xedffff, 0xdbf6ff), 694, 468);		// ��5�ؽ�ɫ1
CRolePnt CStcVal::s_ST5_Role2(CPnt5(151, 588, 0x1b2d5b, 0xadbfc0, 0x364092, 0xc0e4ff, 0x1b2440), 810, 400);		// ��5�ؽ�ɫ2
CRolePnt CStcVal::s_ST5_Role3(CPnt5(449, 588, 0x6476b6, 0x5b5289, 0xd2b6e4, 0x6d649b, 0x496d92), 593, 202);		// ��5�ؽ�ɫ3
CRolePnt CStcVal::s_ST5_Role4(CPnt5(51, 586, 0x7f89b6, 0x242424, 0x120909, 0x526489, 0xbfd2ff), 805, 295);		// ��5�ؽ�ɫ4
CRolePnt CStcVal::s_ST5_Role5(CPnt5(455, 588, 0x929b89, 0x6d6d64, 0x929b89, 0xe4e4db, 0x89897f), 600, 280);		// ��5�ؽ�ɫ5
CRolePnt CStcVal::s_ST5_Role6(CPnt5(359, 586, 0xa4b6d2, 0xffffff, 0xb69b76, 0xffffff, 0x527f92), 744, 325);		// ��5�ؽ�ɫ6
CRolePnt CStcVal::s_ST5_Role7(CPnt5(249, 592, 0xdbe4ff, 0xdbe4ff, 0xc9e4ff, 0xe4edff, 0xe4f6ff), 746, 423);		// ��5�ؽ�ɫ7
CRolePnt CStcVal::s_ST5_Role8(CPnt5(47, 591, 0x525b89, 0xb6adb6, 0x40527f, 0xdbffff, 0x3f363f), 686, 348);		// ��5�ؽ�ɫ8

CRolePnt CStcVal::s_ST6_Role1(CPnt5(863, 588, 0x929b89, 0x6d6d64, 0x929b89, 0xe4e4db, 0x89897f), 585, 335);		// ��6�ؽ�ɫ1
CRolePnt CStcVal::s_ST6_Role2(CPnt5(47, 587, 0x494949, 0x90000, 0x241b24, 0x526480, 0xb6c9f6), 570, 254);			// ��6�ؽ�ɫ2
CRolePnt CStcVal::s_ST6_Role3(CPnt5(549, 594, 0xb6dbff, 0xbf7fbf, 0x9bc0ff, 0xbfedff, 0x92b6c9), 504, 307);		// ��6�ؽ�ɫ3
CRolePnt CStcVal::s_ST6_Role4(CPnt5(359, 580, 0xdbf6ff, 0xd2f6ff, 0x3f80e4, 0xdbf6ff, 0xdbf6ff), 525, 439);		// ��6�ؽ�ɫ4
CRolePnt CStcVal::s_ST6_Role5(CPnt5(460, 591, 0xbfffff, 0xa4e4ed, 0xc0c0c0, 0xa4c0ff, 0xb6e4ff), 412, 374);		// ��6�ؽ�ɫ5
CRolePnt CStcVal::s_ST6_Role6(CPnt5(343, 587, 0xdbedff, 0xbfd2ed, 0x899bb6, 0xadc0e4, 0x92a4bf), 499, 376);		// ��6�ؽ�ɫ6
CRolePnt CStcVal::s_ST6_Role7(CPnt5(268, 590, 0x1b3649, 0x3f6d92, 0x1b3649, 0x1b2d40, 0x3f64bf), 416, 274);		// ��6�ؽ�ɫ7

CRolePnt CStcVal::s_ST7_Role1(CPnt5(49, 586, 0x120909, 0x6d89bf, 0x361b24, 0x526489, 0xbfd2f6), 353, 190);		// ��7�ؽ�ɫ1
CRolePnt CStcVal::s_ST7_Role2(CPnt5(758, 589, 0x89897f, 0x495240, 0x80807f, 0xc9d2c9, 0x767f6d), 261, 232);		// ��7�ؽ�ɫ2
CRolePnt CStcVal::s_ST7_Role3(CPnt5(662, 584, 0x898989, 0x646464, 0x643f24, 0x6492d2, 0xbfedff), 376, 252);		// ��7�ؽ�ɫ3
CRolePnt CStcVal::s_ST7_Role4(CPnt5(551, 589, 0x89bfff, 0x3f3f64, 0x8952c9, 0xbfedff, 0xc9ffff), 329, 294);		// ��7�ؽ�ɫ4
CRolePnt CStcVal::s_ST7_Role5(CPnt5(454, 586, 0xdbdbdb, 0xdbedff, 0x646dbf, 0xedf6ff, 0xedf6ff), 429, 216);		// ��7�ؽ�ɫ5
CRolePnt CStcVal::s_ST7_Role6(CPnt5(255, 591, 0xbfbfd2, 0x649bed, 0x497fad, 0x646d52, 0xdbffff), 329, 294);		// ��7�ؽ�ɫ6



// --END

