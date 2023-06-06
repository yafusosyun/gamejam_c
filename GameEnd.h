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
	int Time;
	const int EndTime = 300;  //終わる時間
};

