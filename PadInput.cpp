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
//if (PadInput::flgY == 0 && PadInput::inputY < -MARGIN) {
//    //処理をかく
//}
////上方向
//if (PadInput::flgY == 0 && PadInput::inputY > MARGIN) {
//    //処理をかく
//}
////左方向
//if (PadInput::flgX == 0 && PadInput::inputX < -MARGIN) {
//    //処理をかく
//}
////右方向
//if (PadInput::flgX == 0 && PadInput::inputX > MARGIN) {
//    //処理をかく
//}

//OnClick,OnRelece,OnPresseに渡す引数
/***********
XINPUT_BUTTON_DPAD_UP		(0)	// デジタル方向ボタン上
XINPUT_BUTTON_DPAD_DOWN		(1)	// デジタル方向ボタン下
XINPUT_BUTTON_DPAD_LEFT		(2)	// デジタル方向ボタン左
XINPUT_BUTTON_DPAD_RIGHT	(3)	// デジタル方向ボタン右
XINPUT_BUTTON_START		(4)	// STARTボタン
XINPUT_BUTTON_BACK		(5)	// BACKボタン
XINPUT_BUTTON_LEFT_THUMB	(6)	// 左スティック押し込み
XINPUT_BUTTON_RIGHT_THUMB	(7)	// 右スティック押し込み
XINPUT_BUTTON_LEFT_SHOULDER	(8)	// LBボタン
XINPUT_BUTTON_RIGHT_SHOULDER	(9)	// RBボタン
XINPUT_BUTTON_A			(12)	// Aボタン
XINPUT_BUTTON_B			(13)	// Bボタン
XINPUT_BUTTON_X			(14)	// Xボタン
XINPUT_BUTTON_Y			(15)	// Yボタン
*************/