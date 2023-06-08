#pragma once
#include"AbstractScene.h"

class Result : public AbstractScene {
private:
	int Score, Comp, Score1;
	bool flg;
	int ResultImg;

public:
	Result(int score,int comp);
	//デストラクタ
	virtual ~Result() {};

	//描画以外の更新を実装する
	virtual AbstractScene* Update()override;

	//描画に関することを実装する
	virtual void Draw()const override;

	void getResult(int score, int time);
};


