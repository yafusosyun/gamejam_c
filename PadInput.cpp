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
//if (PadInput::flgY == 0 && PadInput::JoyPadY < -MARGIN) {
//    if (++MenuNumY > 2) MenuNumY = 0;
//}
////�����
//if (PadInput::flgY == 0 && PadInput::JoyPadY > MARGIN) {
//    if (--MenuNumY < 0) MenuNumY = 2;
//}