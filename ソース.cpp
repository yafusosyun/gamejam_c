#include "DxLib.h"
#define _USE_MATH_DEFINES
#include "math.h"

int WINAPI WinMain(HINSTANCE hlnstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    
    // �E�B���h�E�T�C�Y�ݒ�
    SetGraphMode(1280, 720, 16);
    // �E�B���h�E���[�h�ݒ�
    ChangeWindowMode(TRUE);

    int Cr,PadInput;
    int x0,x1,i;
    int crs;
	
    if (DxLib_Init() == -1) return -1;

    // ���F�̒l���擾
    Cr = GetColor(255, 255, 255);

    // ������̕`��
    //DrawString(150, 240 - 32, "�p�b�h��START�{�^���������Ă�������", Cr);
    DrawBox(220, 10, 320, 20, 0xffffff,true);
    
    crs = DrawBox(260, 10, 280, 20, 0xff0000,true);

    for (i = 0; i <= 100; i++)
    {
        DrawFormatString(50, 50, 0xffffff, "%3d", i);

        if (i >= 100)
        {
            for (i = 100; i > 0; i--)
            {
                 DrawFormatString(50, 50, 0xffffff, "%3d", i);
            }
        } 
    }
    
    
    

    // ���͑҂�
    PadInput = GetJoypadInputState(DX_INPUT_KEY_PAD1);
    while ((PadInput & PAD_INPUT_9) == 0)
    {
        // ���b�Z�[�W����
        if (ProcessMessage() == -1)
        {
            break;    // �G���[�����������烋�[�v�𔲂���
        }

        // �p�b�h�P�̓��͂��擾
        PadInput = GetJoypadInputState(DX_INPUT_KEY_PAD1);
    }

	DxLib_End();

	return 0;
}
