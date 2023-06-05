#pragma once
class GameSystem
{
	mutable int gWaitTime = 6000;
	mutable int HP = 3;
	mutable int gScore = 0;
	mutable int zanki;

public:

	void CountDown() const;
	void Score() const;

	void AddScore(int point) { gScore += point; }
	int GetTime();
	int GetScore() { return gScore; }
};