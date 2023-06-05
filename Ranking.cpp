#include"DxLib.h"
#include"Ranking.h"

#define RANKING_DATA 5    // ランキング上位５人 
int g_RankingImg;   // ランキング画像
struct RankingData g_Ranking[RANKING_DATA];    // ランキングデータの変数宣言

void DrawRanking(int key, int& gamemode)
{
	// ランキング画像表示
	DrawGraph(0, 0, g_RankingImg, FALSE);
	// ランキング一覧を表示
	SetFontSize(40);
	for (int i = 0; i < RANKING_DATA; i++)
	{
		DrawFormatString(450, 200 + i * 86, 0xffffff, "%-10s  %10d", g_Ranking[i].name, g_Ranking[i].score);
	}

	SetFontSize(30);
}

/******************************************
 * ランキング並べ替え
 ******************************************/ 
	void SortRanking(void)
{
	int i, j;
	RankingData work;

	// 選択法ソート
	for (i = 0; i < RANKING_DATA - 1; i++)
	{
		for (j = i + 1; j < RANKING_DATA; j++)
		{
			if (g_Ranking[i].score <= g_Ranking[j].score)
			{
				work = g_Ranking[i];
				g_Ranking[i] = g_Ranking[j];
				g_Ranking[j] = work;
			}
		}
	}
	// 順位付け
	for (i = 0; i < RANKING_DATA; i++)
	{
		g_Ranking[i].no = 1;
	}
	// 得点が同じ場合は、同じ順位とする
	// 同順位があった場合の次の順位はデータ個数が加算された順位とする
	for (i = 0; i < RANKING_DATA - 1; i++)
	{
		for (j = i + 1; j < RANKING_DATA; j++)
		{
			if (g_Ranking[i].score > g_Ranking[j].score)
			{
				g_Ranking[j].no++;
			}
		}
	}
}

/***********************************************
 * ランキングデータの保存
 ***********************************************/
	int  SaveRanking(void)
	{
		FILE* fp;
#pragma warning(disable:4996)

		// ファイルオープン
		if ((fp = fopen("dat/rankingdata.txt", "w")) == NULL)
		{
			/* エラー処理 */
			printf("Ranking Data Error\n");
			return -1;
		}

		// ランキングデータ分配列データを書き込む
		for (int i = 0; i < RANKING_DATA; i++)
		{
			fprintf(fp, "%2d %10s %10d\n", g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
		}

		// ファイルクローズ
		fclose(fp);

		return 0;

	}

/*************************************
 * ランキングデータ読み込み
*************************************/
	int ReadRanking(void)
	{
		FILE* fp;
#pragma warning(disable:4996)

		// ファイルオープン
		if ((fp = fopen("dat/rankingdata.txt", "r")) == NULL)
		{
			// エラー処理
			printf("Ranking Data Error\n");
			return -1;
		}

		// ランキングデータ配分列データを読み込む
		for (int i = 0; i < RANKING_DATA; i++)
		{
			int dammy = fscanf(fp, "%2d %10s %10d", &g_Ranking[i].no, g_Ranking[i].name, &g_Ranking[i].score);
		}

		// ファイルクローズ
		fclose(fp);

		return 0;
	}
		//ランキング画像読み込み
		int LoadRankingImage()
		{
			// ランキング画像読込
			if ((g_RankingImg = LoadGraph("images/Ranking/input.png")) == -1) return -1;

			return 0;
		}