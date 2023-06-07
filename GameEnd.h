#pragma once
#include "AbstractScene.h"
#include "DxLib.h"
class GameEnd :
    public AbstractScene
{
public:
	GameEnd();
	~GameEnd()
	{
		DeleteGraph(EndImage);
		DeleteFontToHandle(Font);
	}

	//描画以外の更新を実装
	virtual AbstractScene* Update() override;

	//描画に関することを実装
	virtual void Draw() const override;

private:
	int Font;      //フォント
	int EndImage;  //背景画像
	int SentenceY[9] = { 730,760,840,910,980,1100,1170,1240,1500 };
	int Time;
	const int MaxSentence = 9;
	const int EndTime = 1200;  //終わる時間  予定：１分
	const int FontSiz = 50;   //フォントサイズ
};

