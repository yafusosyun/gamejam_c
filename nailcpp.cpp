#include<DxLib.h>
#include<stdlib.h>



#define _SCREEN_HEIGHT_ 720
#define _SCREEN_WIDHT_	1280
#define _SCREEN_COLOR_BIT_16_ 16
#define _SCREEN_COLOR_BIT_32_ 32

/***********************************
*�@�ϐ��̐錾�i�N���[�o���ϐ��j
************************************/
int nailimag;

/***********************************
* �摜�Ǎ�
************************************/
int LoadImages(void)
{
	//�^�C�g���摜�̓Ǎ�
	nailimag = LoadGraph("images/nail1");

	return 0;
}
/*******************
�֐��錾
*************************/
void nail(void);//�B�̃V�X�e��	


/********************
�v���O�����̊J�n
***************************/
int WINAPI WinMain(_In_ HINSTANCE ih, _In_opt_ HINSTANCE ioh, _In_ LPSTR il, _In_ int ii)
{
	// �E�B���h�E���[�h�ŋN��
	if (ChangeWindowMode(TRUE) != DX_CHANGESCREEN_OK)
	{
		return -1;
	}

	//�摜�Ǎ��֐��̌Ăяo��
	if (LoadImages() == -1);


	// ��ʃT�C�Y��ύX
	if (SetGraphMode(_SCREEN_WIDHT_, _SCREEN_HEIGHT_, _SCREEN_COLOR_BIT_32_) != DX_CHANGESCREEN_OK)
	{
		return -1;
	}

	// DX���C�u�����̏�����
	if (DxLib_Init() == -1)
	{
		return -1;
	}

}

/*******************
�B�̃V�X�e��
*********************/
void nail(void)
{
	int b;

	scanf_s("%d", &b);

	printf("aaaa");
}