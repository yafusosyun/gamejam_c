#include "PadInput.h"

char PadInput::oldKey[BUTTONS];    //�O��̓��̓L�[
char PadInput::nowKey[BUTTONS];    //����̓��̓L�[
PADSTATE PadInput::state = PADSTATE::NOT;
XINPUT_STATE PadInput::Input;
int PadInput::inputX = -1, PadInput::inputY = -1;
int PadInput::oldX = -1, PadInput::oldY = -1;
int PadInput::flgX = 0, PadInput::flgY = 0;

void PadInput::UpdateKey()
{
    // ���̓L�[�擾
    GetJoypadXInputState(DX_INPUT_KEY_PAD1, &Input);
    for (int i = 0; i < BUTTONS; i++)
    {
        oldKey[i] = nowKey[i];
        nowKey[i] = Input.Buttons[i];
    }

}

void PadInput::StickControl()
{
    inputX = GetPadThumbLX();
    inputY = GetPadThumbLY();

    if (oldX > MARGIN && inputX > MARGIN)
    {
        flgX = 1;
    }
    else if (oldX < -MARGIN && inputX < -MARGIN) flgX = 1;
    else flgX = 0;

    if (oldY > MARGIN && inputY > MARGIN)
    {
        flgY = 1;
    }
    else if (oldY < -MARGIN && inputY < -MARGIN) flgY = 1;
    else flgY = 0;

    oldX = inputX;
    oldY = inputY;
}

////������
////���j���[�J�[�\���ړ�����
////������
//if (PadInput::flgY == 0 && PadInput::inputY < -MARGIN) {
//    //����������
//}
////�����
//if (PadInput::flgY == 0 && PadInput::inputY > MARGIN) {
//    //����������
//}
////������
//if (PadInput::flgX == 0 && PadInput::inputX < -MARGIN) {
//    //����������
//}
////�E����
//if (PadInput::flgX == 0 && PadInput::inputX > MARGIN) {
//    //����������
//}

//OnClick,OnRelece,OnPresse�ɓn������
/***********
XINPUT_BUTTON_DPAD_UP		(0)	// �f�W�^�������{�^����
XINPUT_BUTTON_DPAD_DOWN		(1)	// �f�W�^�������{�^����
XINPUT_BUTTON_DPAD_LEFT		(2)	// �f�W�^�������{�^����
XINPUT_BUTTON_DPAD_RIGHT	(3)	// �f�W�^�������{�^���E
XINPUT_BUTTON_START		(4)	// START�{�^��
XINPUT_BUTTON_BACK		(5)	// BACK�{�^��
XINPUT_BUTTON_LEFT_THUMB	(6)	// ���X�e�B�b�N��������
XINPUT_BUTTON_RIGHT_THUMB	(7)	// �E�X�e�B�b�N��������
XINPUT_BUTTON_LEFT_SHOULDER	(8)	// LB�{�^��
XINPUT_BUTTON_RIGHT_SHOULDER	(9)	// RB�{�^��
XINPUT_BUTTON_A			(12)	// A�{�^��
XINPUT_BUTTON_B			(13)	// B�{�^��
XINPUT_BUTTON_X			(14)	// X�{�^��
XINPUT_BUTTON_Y			(15)	// Y�{�^��
*************/