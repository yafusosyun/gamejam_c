#include "Title.h"
#include "PadInput.h"

/*
・ゲームスタート
・ランキング
・ゲームエンド
*/
Title::Title()
{
    CursorX = 500;
    CursorY = 300;
}

AbstractScene* Title::Update()
{
    if (2500 < PadInput::GetPadThumbLY())  //下移動
    {
        ++CursorY;
        if (2 < CursorY)
        {
            CursorY = 0;
        }
    }
    if (PadInput::GetPadThumbLY() < 2500)  //上移動
    {
        --CursorY;
        if (CursorY < 0)
        {
            CursorY = 2;
        }
    }

    if (PadInput::OnClick(XINPUT_BUTTON_B) == 1)
    {
        switch (CursorY)
        {
        case 0:
            return nullptr/*ゲームスタート*/;
            break;
        case 1:
            return nullptr/*ランキング*/;
            break;
        case 2:
            return nullptr/*ゲームエンド*/;
            break;
        }
    }

    return nullptr;
}

void Title::Draw() const
{
    DrawString(600, 300, "ゲームスタート", 0xffffff);
    DrawString(600, 350, "ランキング", 0xffffff);
    DrawString(600, 400, "ゲームを終わる", 0xffffff);

    DrawCircle(CursorX, CursorY*50+300, 10, 0xffffff, TRUE);
}
