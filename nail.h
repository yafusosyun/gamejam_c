#pragma once

class Nail {
public:
	int count = 0;
	int miss = 0;
	int judge;
	int trunflg = true;
	int fps;

	int F;//F�͎��s�AT�͐���
	int FF;
	int FFF;
	int FFT;
	int T;
	int TF;
	int TT;
	int TTF;
	int TTT;
	int FFFF;
	int FFFT;
	int TTFF;
	int TTTF;
	int TTTT;
	int Start;//�łO�̉摜
public:
	void Init();
	int LoadImages(void);//�摜�Ǎ�����
	void nail(void);//�B�̃V�X�e��	
	void Draw();
	void SetNailCount();
	void Update();
};

