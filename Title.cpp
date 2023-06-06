#include "Title.h"
#include "PadInput.h"

/*
�E�Q�[���X�^�[�g
�E�����L���O
�E�Q�[���G���h
*/
Title::Title()
{
    CursorX = 500;
    CursorY = 300;
}

AbstractScene* Title::Update()
{
    if (2500 < PadInput::GetPadThumbLY())  //���ړ�
    {
        ++CursorY;
        if (2 < CursorY)
        {
            CursorY = 0;
        }
    }
    if (PadInput::GetPadThumbLY() < 2500)  //��ړ�
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
            return nullptr/*�Q�[���X�^�[�g*/;
            break;
        case 1:
            return nullptr/*�����L���O*/;
            break;
        case 2:
            return nullptr/*�Q�[���G���h*/;
            break;
        }
    }

    return nullptr;
}

void Title::Draw() const
{
    DrawString(600, 300, "�Q�[���X�^�[�g", 0xffffff);
    DrawString(600, 350, "�����L���O", 0xffffff);
    DrawString(600, 400, "�Q�[�����I���", 0xffffff);

    DrawCircle(CursorX, CursorY*50+300, 10, 0xffffff, TRUE);
}
