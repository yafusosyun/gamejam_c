#pragma once

class Nail {
public:
	int count = 0;
	int miss = 0;
	int judge;
	int trunflg = true;
	int fps;

	int F;//Fは失敗、Tは成功
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
	int Start;//打つ前の画像
public:
	void Init();
	int LoadImages(void);//画像読込処理
	void nail(void);//釘のシステム	
	void Draw();
	void SetNailCount();
	void Update();
};

