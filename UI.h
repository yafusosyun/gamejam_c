#pragma once
class UI
{
	mutable int gWaitTime = 6000;
	mutable int gScore = 0;
	
public:

	void CountDown() const;		//��������
	void DrawCountDown();
	int Score() ;				//�X�R�A�v�Z
	void DrawScore();			//�X�R�A�\��

	void AddScore(int point) { gScore += point; }
	int GetTime();
	int GetScore() { return gScore; }
};