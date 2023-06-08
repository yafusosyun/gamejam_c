#pragma once
#include <string>

class Ranking
{
public:
	struct RANKING_DATA{
	int  no;
	std::string name;
	long int score;
	};
public:
	static RANKING_DATA rankingData[5];

public:
	void ReadRanking();
	void WriteRanking(std::string _name, long int _score);

	static RANKING_DATA GetRankingData(int index) { return rankingData[index]; };
};

//void SortRanking(void);  // ランキングの並べ替え
//int SaveRanking(void);   // ランキングデータの保存
//int ReadRanking(void);   // ランキングデータの読込

//int LoadRankingImage();                        //ランキング画像読み込み
