#include "DxLib.h"
#define _USE_MATH_DEFINES
#include "math.h"

int WINAPI WinMain(HINSTANCE hlnstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    int Cr,PadInput;
    int x;
    // �E�B���h�E�T�C�Y�ݒ�
    SetGraphMode(1280, 720, 16);
    // �E�B���h�E���[�h�ݒ�
    ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1) return -1;
	

    // ���F�̒l���擾
    Cr = GetColor(255, 255, 255);

    // ������̕`��
    //DrawString(150, 240 - 32, "�p�b�h��START�{�^���������Ă�������", Cr);
    DrawBox(220, 10, 320, 20, 0xffffff,true);
    
    DrawBox(260, 10, 280, 20, 0xff0000,true);

    for (x = 220; x < 320; x++)
    {
        DrawBox(265+x , 5, 275+x, 25, 0x00ff00, true);
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
