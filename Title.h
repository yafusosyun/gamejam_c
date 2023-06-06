#pragma once
#include "SceneManager.h"
class Title :
    public SceneManager
{
public:
	Title();

	//描画以外の更新を実装
	virtual AbstractScene* Update() override;

	//描画に関することを実装
	virtual void Draw() const override;

private:
	int CursorX, CursorY;  //カーソルの座標
};

