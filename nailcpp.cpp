#include<DxLib.h>
#include<stdio.h>



#define _SCREEN_HEIGHT_ 720
#define _SCREEN_WIDHT_	1280
#define _SCREEN_COLOR_BIT_16_ 16
#define _SCREEN_COLOR_BIT_32_ 32

/***********************************
*�@�ϐ��̐錾�i�N���[�o���ϐ��j
************************************/
int F;//F�͎��s�AT�͐���
int FF;
int FFF;
int FFT;
int T;
int TF;
int TT;
int TTF;
int TTT;
int FFFF;
int FFFT;
int TTFF;
int TTTF;
int TTTT;
int Start;//�łO�̉摜
/*******************
�֐��錾
*************************/

int LoadImages(void);//�摜�Ǎ�����
void nail(void);//�B�̃V�X�e��	


/********************
�v���O�����̊J�n
***************************/
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hprevInstance, _In_ LPSTR lpCmdLine, _In_
	int nCmdShow)
{
  
	ChangeWindowMode(TRUE); // �E�B���h�E���[�h�ݒ�
	if (DxLib_Init() == -1) return -1; // DX���C�u��������������

	//�摜�Ǎ��֐��̌Ăяo��
	if (LoadImages() == -1) return -1;

	nail();


	WaitKey(); // ���ʂ����邽�߂ɃL�[�҂�
	

	DxLib_End(); // DX���C�u�����g�p�̏I������
	return 0; // �\�t�g�̏I��
}

/***********************************
* �摜�Ǎ�
************************************/
int LoadImages(void)
{
	//�B��łO
	 Start = LoadGraph("images/Start.png");

	 //1���
	 F = LoadGraph("images/F.png");
	 T = LoadGraph("images/T.png");
	
	
	 //2���
	 TT = LoadGraph("images/TT.png");
	FF = LoadGraph("images/FF.png");
	TF = LoadGraph("images/TF.png");

	//3���
	 TTF = LoadGraph("images/TTF.png");
	 TTT = LoadGraph("images/TTT.png");
	 FFT = LoadGraph("images/FFT.png");
	 FFF = LoadGraph("images/FFF.png");

	 //4���
	 FFFF = LoadGraph("images/FFFF.png");
	 FFFT = LoadGraph("images/FFFT.png");
	 TTFF = LoadGraph("images/TTFF.png");
	 TTTF = LoadGraph("images/TTTF.png");
	 TTTT = LoadGraph("images/TTTT.png");
	return 0;
}

/**********************************
�B�̃V�X�e��
*****************************/
void nail(void)
{
	int a = 0;
	int count=0;
	int miss = 0;

	
	switch (count) {

	case 0://�B��łO
			DrawGraph(0, 0, Start, TRUE);
			break;

	case 1://�B��ł�1���
		if (a == 0)
		{
			DrawGraph(0, 0, F, TRUE);//1��ڃ~�X
			miss = 1;
		}
		else
			DrawGraph(0, 0, T, TRUE);//1��ڐ���
			break;
			
		case 2://�B��ł�2���
			if (a == 0)
			{
				if (miss == 1)
				{
					DrawGraph(0, 0, FF, TRUE);//2��A�����s
					miss = 2;
				}
			}
				else if(miss == 1)
				{
					DrawGraph(0, 0, TF, TRUE);//2��ڐ���
					miss = 2;
				}
				else if (miss == 0)
			{
				DrawGraph(0, 0, TT, TRUE);//2��ژA������
			}
				break;

		case 3://�B��ł�3���
			if (a == 0)
			{
				if (miss == 2)
				{
					DrawGraph(0, 0, FFF, TRUE);//3��A�����s
				}
			}
			else if (miss == 2)
			{
				DrawGraph(0, 0, FFT, TRUE);//2�񎸔s�A1�񐬌�
			}
			else if (miss == 1)
			{
				DrawGraph(0, 0, TTF, TRUE);//2�񐬌��A1�񎸔s
			}
			else if (miss == 0)
			{
				DrawGraph(0, 0, TTT, TRUE);//3��A������
			}
			break;

		case 4://�B��ł�4��ځi�Ō�̖��܂�Ƃ���j
			if (a == 0)
			{
				if (miss == 3)
				{
					DrawTurnGraph(0, 0, FFFF, TRUE);//4��A���~�X
				}
			}
				else if (miss == 3)//3�񎸔s�A1�񐬌�
				{
					DrawGraph(0, 0, FFFT, TRUE);
				}
				else if (miss == 2)
				{
					DrawGraph(0, 0, TTFF, TRUE);//2�񎸔s�A2����a
				}
				else if (miss == 1)
			{
				DrawGraph(0, 0, TTTF, TRUE);//3�񐬌��A1�񎸔sa
			}
				else if (miss == 0)
			{
				DrawGraph(0, 0, TTTT, TRUE);//4��A������a
			}
				break;
			
		}

}

