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
	int SentenceY[6] = { 730,760,860,910,960,1100 };
	int Time;
	const int MaxSentence = 6;
	const int EndTime = 1800;  //終わる時間
	const int FontSiz = 50;   //フォントサイズ
};

