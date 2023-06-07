#pragma once
#include "SceneManager.h"
class GameEnd :
    public AbstractScene
{
public:
	GameEnd();

	//描画以外の更新を実装
	virtual AbstractScene* Update() override;

	//描画に関することを実装
	virtual void Draw() const override;

private:
	int Font;      //フォント
	int EndImage;  //背景画像
	int ScrollY;
	int EndTime;  //終わる時間
	const int FontSiz = 50;   //フォントサイズ
};

