#include "Title.h"
#include "PadInput.h"
#include "GameEnd.h"

#define WINDOW_CENTER 1280*0.4

/*
・ゲームスタート
・ランキング
・ゲームエンド
*/
Title::Title()
{
    CursorY = 0;
    FontSiz = 45;
    Font= CreateFontToHandle("UD デジタル 教科書体 NP-B", FontSiz, 3, DX_FONTTYPE_ANTIALIASING);
}

AbstractScene* Title::Update()
{
    PadInput::StickControl();

    //下移動
    if (PadInput::GetFlgY() == 0 && PadInput::GetPadThumbLY()< -MARGIN)
    {
        ++CursorY;
        if (2 < CursorY)
        {
            CursorY = 0;
        }
    }
    //上移動
    if (PadInput::GetFlgY() == 0 && MARGIN < PadInput::GetPadThumbLY())
    {
        --CursorY;
        if (CursorY < 0)
        {
            CursorY = 2;
        }
    }

    //Bボタンが押された時
    if (PadInput::OnClick(XINPUT_BUTTON_B) == 1)
    {
        switch (CursorY)
        {
        case 0:
            return this/*ゲームスタート*/;
            break;
        case 1:
            return this/*ランキング*/;
            break;
        case 2:/*ゲームエンド*/
            return new GameEnd();
            break;
        }
    }

    DrawFormatString(0, 0, 0xff0000, "%d", PadInput::GetPadThumbLY());

    return this;
}

void Title::Draw() const
{
    DrawStringToHandle(static_cast<int>(WINDOW_CENTER) - 20, FontSiz, "タイトル",0xffffff, Font);

    DrawStringToHandle(static_cast<int>(WINDOW_CENTER), 300 + FontSiz, "ゲームスタート", 0xffffff, Font);
    DrawStringToHandle(static_cast<int>(WINDOW_CENTER), 380 + FontSiz, "ランキング", 0xffffff, Font);
    DrawStringToHandle(static_cast<int>(WINDOW_CENTER), 460 + FontSiz, "ゲームを終わる", 0xffffff, Font);

    DrawCircle(static_cast<int>(WINDOW_CENTER)-30, CursorY * 80 + (320+FontSiz), 20, 0xff0000, TRUE);
}
