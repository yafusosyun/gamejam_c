#pragma once
class UI
{
	mutable int gWaitTime = 6000;
	mutable int gScore = 0;
	
public:

	void CountDown() const;
	void Score() const;

	void AddScore();
	int GetTime();
	int GetScore() { return gScore; }
};