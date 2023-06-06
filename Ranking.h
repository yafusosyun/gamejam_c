#pragma once

struct RankingData                            // ランキングデータ構造体
{
	int  no;
	char name[11];
	long score;
};

void SortRanking(void);  // ランキングの並べ替え
int SaveRanking(void);   // ランキングデータの保存
int ReadRanking(void);   // ランキングデータの読込

int LoadRankingImage();                        //ランキング画像読み込み
int LoadRankingSounds();                       //ランキングサウンド読み込み