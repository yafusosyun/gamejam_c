#include "Title.h"
#include "PadInput.h"
#include "GameMain.h"
#include "GameEnd.h"
#include "Ranking.h"
#define _USE_MATH_DEFINES
#include <math.h>

#define WINDOW_CENTER 1280*0.35

Title::Title()
{
    CursorY = 0;
    TitileFont = CreateFontToHandle("UD デジタル 教科書体 NP-B", 80, 7, DX_FONTTYPE_ANTIALIASING_EDGE, -1, 3);
    Font= CreateFontToHandle("UD デジタル 教科書体 NP-B", FontSiz, 7, DX_FONTTYPE_ANTIALIASING_EDGE,-1,3);
    TitleImage = LoadGraph("images/Title.png");
    CursorImage = LoadGraph("images/cursor.png");
}

AbstractScene* Title::Update()
{
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
        case 0:/*ゲームスタート*/;
            return new GameMain();
            break;
        case 1:/*ランキング*/
            return this;
            break;
        case 2:/*ゲームエンド*/
            return new GameEnd();
            break;
        }
    }

    return this;
}

void Title::Draw() const
{
    DrawGraph(0, 0, TitleImage, FALSE);

    DrawStringToHandle(static_cast<int>(WINDOW_CENTER) + 15, 70, "タイトル", 0xffffff, TitileFont);

    DrawStringToHandle(static_cast<int>(WINDOW_CENTER), 300 + FontSiz, "ゲームスタート", 0x4169E1, Font,0xffffff);
    DrawStringToHandle(static_cast<int>(WINDOW_CENTER), 400 + FontSiz, "ランキング", 0x4169E1, Font, 0xffffff);
    DrawStringToHandle(static_cast<int>(WINDOW_CENTER), 500 + FontSiz, "ゲームを終わる", 0x4169E1, Font, 0xffffff);

    DrawRotaGraph(static_cast<int>(WINDOW_CENTER) - 30, CursorY * 100 + (330 + FontSiz), 1.0, M_PI / 2, CursorImage, TRUE, FALSE);
}
