#include<DxLib.h>
#include<stdio.h>



#define _SCREEN_HEIGHT_ 720
#define _SCREEN_WIDHT_	1280
#define _SCREEN_COLOR_BIT_16_ 16
#define _SCREEN_COLOR_BIT_32_ 32

/***********************************
*�@�ϐ��̐錾�i�N���[�o���ϐ��j
************************************/
int nailimg;

/***********************************
* �摜�Ǎ�
************************************/
int LoadImages(void)
{
	//�^�C�g���摜�̓Ǎ�
	nailimg = LoadGraph("images/ringo.png");

	return 0;
}
/*******************
�֐��錾
*************************/
/*void nail(void);*///�B�̃V�X�e��	


/********************
�v���O�����̊J�n
***************************/
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hprevInstance, _In_ LPSTR lpCmdLine, _In_
	int nCmdShow)
{
  
	ChangeWindowMode(TRUE); // �E�B���h�E���[�h�ݒ�
	if (DxLib_Init() == -1) return -1; // DX���C�u��������������

	// test1.bmp �̓ǂݍ���
	nailimg = LoadGraph("images/ringo.png");

	int b = 0;

	if (b ==0) DrawGraph(0, 0, nailimg, TRUE);



	WaitKey(); // ���ʂ����邽�߂ɃL�[�҂�
	

	DxLib_End(); // DX���C�u�����g�p�̏I������
	return 0; // �\�t�g�̏I��
}

/**********************************
�B�̃V�X�e��
*****************************/
//void nail(void)
//{
//	int b;
//	scanf_s("%d", &b);
//
//	switch (b) {
//	case 0:
//		DrawGraph(0, 0, nailimg, FALSE);
//
//		break;
//	case 1:
//
//		break;
//	case 2:
//
//		break;
//	case 3:
//
//		break;
//	}
//}