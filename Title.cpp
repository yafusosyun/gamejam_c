#include "Title.h"
#include "PadInput.h"
#include "GameEnd.h"

#define WINDOW_CENTER 1280*0.4

/*
�E�Q�[���X�^�[�g
�E�����L���O
�E�Q�[���G���h
*/
Title::Title()
{
    CursorY = 0;
    FontSiz = 45;
    Font= CreateFontToHandle("UD �f�W�^�� ���ȏ��� NP-B", FontSiz, 3, DX_FONTTYPE_ANTIALIASING);
}

AbstractScene* Title::Update()
{
    PadInput::StickControl();

    //���ړ�
    if (PadInput::GetFlgY() == 0 && PadInput::GetPadThumbLY()< -MARGIN)
    {
        ++CursorY;
        if (2 < CursorY)
        {
            CursorY = 0;
        }
    }
    //��ړ�
    if (PadInput::GetFlgY() == 0 && MARGIN < PadInput::GetPadThumbLY())
    {
        --CursorY;
        if (CursorY < 0)
        {
            CursorY = 2;
        }
    }

    //B�{�^���������ꂽ��
    if (PadInput::OnClick(XINPUT_BUTTON_B) == 1)
    {
        switch (CursorY)
        {
        case 0:
            return this/*�Q�[���X�^�[�g*/;
            break;
        case 1:
            return this/*�����L���O*/;
            break;
        case 2:/*�Q�[���G���h*/
            return new GameEnd();
            break;
        }
    }

    DrawFormatString(0, 0, 0xff0000, "%d", PadInput::GetPadThumbLY());

    return this;
}

void Title::Draw() const
{
    DrawStringToHandle(static_cast<int>(WINDOW_CENTER) - 20, FontSiz, "�^�C�g��",0xffffff, Font);

    DrawStringToHandle(static_cast<int>(WINDOW_CENTER), 300 + FontSiz, "�Q�[���X�^�[�g", 0xffffff, Font);
    DrawStringToHandle(static_cast<int>(WINDOW_CENTER), 380 + FontSiz, "�����L���O", 0xffffff, Font);
    DrawStringToHandle(static_cast<int>(WINDOW_CENTER), 460 + FontSiz, "�Q�[�����I���", 0xffffff, Font);

    DrawCircle(static_cast<int>(WINDOW_CENTER)-30, CursorY * 80 + (320+FontSiz), 20, 0xff0000, TRUE);
}
