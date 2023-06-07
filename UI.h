#pragma once
class UI
{
public:
	mutable int gWaitTime = 3600;
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