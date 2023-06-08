#pragma once
#include "AbstractScene.h"
#include "DxLib.h"
class Title :
    public AbstractScene
{
private:
	int CursorY;  //カーソルの座標
	int Font;     //フォント
	int TitileFont; //タイトル用フォント
	const int FontSiz = 65;  //フォントサイズ
	int TitleImage;  //タイトル画像
	int CursorImage; //カーソル画像
	int CursorSE;
	int DecisionSE;

public:
	Title();
	~Title()
	{
		DeleteFontToHandle(Font);
		DeleteGraph(TitleImage);
	}

	//描画以外の更新を実装
	virtual AbstractScene* Update() override;

	//描画に関することを実装
	virtual void Draw() const override;
};

