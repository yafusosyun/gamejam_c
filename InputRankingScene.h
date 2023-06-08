#pragma once
#include "AbstractScene.h"
#include "Ranking.h"
#include "DxLib.h"

class InputRankingScene : public AbstractScene
{
private:
	Ranking ranking;
	Ranking::RANKING_DATA rankingData[5];

	int score;
	std::string name;

	POINT cursorPoint;
	const char keyboard[5][14] = { "ABCDEFGHIJKLM" ,"NOPQRSTUVWXYZ" ,"abcdefghijklm" ,"nopqrstuvwxyz" ,"0123456789<" };

	int image;
	int cursorSE;
	int decisionSE;

public:
	InputRankingScene(int _score);

public:
	virtual void Draw()const override;
	virtual AbstractScene*  Update()override;
	
};

