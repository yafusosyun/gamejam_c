#include<DxLib.h>
#include<stdio.h>



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
	nailimag = LoadGraph("images/ringo");

	return 0;
}
/*******************
�֐��錾
*************************/
void nail(void);//�B�̃V�X�e��	


/********************
�v���O�����̊J�n
***************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    int a;

    if (DxLib_Init() == -1)        // �c�w���C�u��������������
    {
        return -1;        // �G���[���N�����璼���ɏI��
    }

    // test1.bmp�̓ǂݍ���
     LoadGraph("images/ringo");

    // �ǂ݂��񂾃O���t�B�b�N����ʍ���ɕ`��
    DrawGraph(100, 100, nailimag, TRUE);



    WaitKey();        // ���ʂ����邽�߂ɃL�[�҂�(�wWaitKey�x���g�p)

    DxLib_End();        // �c�w���C�u�����g�p�̏I������

    return 0;        // �\�t�g�̏I��
}