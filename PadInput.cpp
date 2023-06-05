#include "PadInput.h"

char PadInput::oldKey[BUTTONS];    //前回の入力キー
char PadInput::nowKey[BUTTONS];    //今回の入力キー
PADSTATE PadInput::state = PADSTATE::NOT;
XINPUT_STATE PadInput::Input;
int PadInput::inputX = -1, PadInput::inputY = -1;
int PadInput::oldX = -1, PadInput::oldY = -1;
int PadInput::flgX = 0, PadInput::flgY = 0;

void PadInput::UpdateKey()
{
    // 入力キー取得
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

////書き方
////メニューカーソル移動処理
////下方向
//if (PadInput::flgY == 0 && PadInput::JoyPadY < -MARGIN) {
//    if (++MenuNumY > 2) MenuNumY = 0;
//}
////上方向
//if (PadInput::flgY == 0 && PadInput::JoyPadY > MARGIN) {
//    if (--MenuNumY < 0) MenuNumY = 2;
//}