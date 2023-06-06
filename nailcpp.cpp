#include<DxLib.h>
#include<stdio.h>



#define _SCREEN_HEIGHT_ 720
#define _SCREEN_WIDHT_	1280
#define _SCREEN_COLOR_BIT_16_ 16
#define _SCREEN_COLOR_BIT_32_ 32

/***********************************
*�@�ϐ��̐錾�i�N���[�o���ϐ��j
************************************/
int isu1;//�֎q1�摜�̕ϐ�
int isu2;//�֎q2�摜�̕ϐ�
int isu3;//�֎q�R�摜�̕ϐ�

int miss1;//���s��1�̉摜�p�̕ϐ�
int miss2;//���s��2�̉摜�p�̕ϐ�
int miss3;//���s��3�̉摜�p�̕ϐ�
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
	//�摜�̓Ǎ�
	isu1 = LoadGraph("images/1.png");//�֎q�P�摜�̓Ǎ�
	isu2 = LoadGraph("images/2.png");//�֎q�Q�摜�̓Ǎ�
	isu3 = LoadGraph("images/3.png");//�֎q�R�摜�̓Ǎ�

	miss1 =  LoadGraph("images/miss1.png");//�~�X�����Ƃ��̉摜�̓Ǎ�
	miss2 = LoadGraph("images/miss1.png");//�~�X�����Ƃ��̉摜�̓Ǎ�
	miss3 = LoadGraph("images/miss1.png");//�~�X�����Ƃ��̉摜�̓Ǎ�

	//���s���̈֎q�摜�̓Ǎ�
	

	return 0;
}

/**********************************
�B�̃V�X�e��
*****************************/
void nail(void)
{
	int a;
	int count;
	int miss = 0;

	
	switch (count) {

	case 0://�B��łO
			DrawGraph(0, 0, isu1, TRUE);
			break;

	case 1://�B��ł�1���
		if (a == 0)
		{
			DrawGraph(0, 0, miss1, TRUE);//1��ڃ~�X
			miss = 1;
		}
		else
			DrawGraph(0, 0, isu2, TRUE);//1��ڐ���
			break;
			
		case 2://�B��ł�2���
			if (a == 0)
			{
				if (miss == 1)
				{
					DrawGraph(0, 0, miss, TRUE);//2��A�����s
					miss = 2;
				}
			}
				else if(miss == 1)
				{
					DrawGraph(0, 0, miss, TRUE);//2��ڐ���
					miss = 2;
				}
				else if (miss == 0)
			{
				DrawGraph(0, 0, miss, TRUE);//2��ژA������
			}
				break;

		case 3://�B��ł�3���
			if (a == 0)
			{
				if (miss == 2)
				{
					DrawGraph(0, 0, miss, TRUE);//3��A�����s
				}
			}
			else if (miss == 2)
			{
				DrawGraph(0, 0, miss, TRUE);//2�񎸔s�A1�񐬌�
			}
			else if (miss == 1)
			{
				DrawGraph(0, 0, miss, TRUE);//2�񐬌��A1�񎸔s
			}
			else if (miss == 0)
			{
				DrawGraph(0, 0, miss, TRUE);//3��A������
			}
			break;

		case 4://�B��ł�4��ځi�Ō�̖��܂�Ƃ���j
			if (a == 0)
			{
				if (miss == 3)
				{
					DrawTurnGraph(0, 0, isu2, TRUE);//4��A���~�X
				}
			}
				else if (miss == 3)//3�񎸔s�A1�񐬌�
				{
					DrawGraph(0, 0, miss, TRUE);
				}
				else if (miss == 2)
				{
					DrawGraph(0, 0, miss, TRUE);//2�񎸔s�A2����
				}
				else if (miss == 1)
			{
				DrawGraph(0, 0, miss, TRUE);//3�񐬌��A1�񎸔s
			}
				else if (miss == 0)
			{
				DrawGraph(0, 0, miss, TRUE);//4��A������
			}
				break;
			
		}

}

