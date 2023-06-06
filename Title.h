#pragma once
#include "SceneManager.h"
#include "DxLib.h"
class Title :
    public AbstractScene
{
private:
	int CursorY;  //カーソルの座標
	int Font;     //フォント
	int FontSiz;  //フォントサイズ

public:
	Title();
	~Title()
	{
		DeleteFontToHandle(Font);
	}

	//描画以外の更新を実装
	virtual AbstractScene* Update() override;

	//描画に関することを実装
	virtual void Draw() const override;
};

