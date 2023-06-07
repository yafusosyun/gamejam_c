#pragma once
class UI
{
public:
	mutable int gWaitTime = 3600;
	mutable int gScore = 0;
	
public:

	void CountDown() const;		//制限時間
	void DrawCountDown();
	int Score() ;				//スコア計算
	void DrawScore();			//スコア表示

	void AddScore(int point) { gScore += point; }
	int GetTime();
	int GetScore() { return gScore; }
};