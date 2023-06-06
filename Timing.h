#pragma once
#include "AbstractScene.h"

#define bar 1000

class Timing : public AbstractScene {
private:
	int timing;
	int gauge = 0;
	int speed = 1;
	bool numgaugeflg = true;
	bool gaugeflg = true;
	int tmp = 0;
	int judgepoint = 50;
	static int judge;

	int goodleft = ((bar / 100) * judgepoint - 100);
	int goodright = ((bar / 100) * judgepoint + 100);
	int greatleft = ((bar / 100) * judgepoint - 10);
	int greatright = ((bar / 100) * judgepoint + 10);

	int fps;
public:
	//デスストラクタ
	virtual ~Timing() {};

	//描画以外の更新を実装する
	virtual AbstractScene* Update() override;

	//描画に関することを実装する
	virtual void Draw() const override;

	//judgeを取得
	static int GetJudge() { return judge; }
};