#include"DxLib.h"
#include"Ranking.h"

#define RANKING_DATA 5    // �����L���O��ʂT�l 
int g_RankingImg;   // �����L���O�摜
struct RankingData g_Ranking[RANKING_DATA];    // �����L���O�f�[�^�̕ϐ��錾

void DrawRanking(int key, int& gamemode)
{
	// �����L���O�摜�\��
	DrawGraph(0, 0, g_RankingImg, FALSE);
	// �����L���O�ꗗ��\��
	SetFontSize(40);
	for (int i = 0; i < RANKING_DATA; i++)
	{
		DrawFormatString(450, 200 + i * 86, 0xffffff, "%-10s  %10d", g_Ranking[i].name, g_Ranking[i].score);
	}

	SetFontSize(30);
}

/******************************************
 * �����L���O���בւ�
 ******************************************/ 
	void SortRanking(void)
{
	int i, j;
	RankingData work;

	// �I��@�\�[�g
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
	// ���ʕt��
	for (i = 0; i < RANKING_DATA; i++)
	{
		g_Ranking[i].no = 1;
	}
	// ���_�������ꍇ�́A�������ʂƂ���
	// �����ʂ��������ꍇ�̎��̏��ʂ̓f�[�^�������Z���ꂽ���ʂƂ���
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
 * �����L���O�f�[�^�̕ۑ�
 ***********************************************/
	int  SaveRanking(void)
	{
		FILE* fp;
#pragma warning(disable:4996)

		// �t�@�C���I�[�v��
		if ((fp = fopen("dat/rankingdata.txt", "w")) == NULL)
		{
			/* �G���[���� */
			printf("Ranking Data Error\n");
			return -1;
		}

		// �����L���O�f�[�^���z��f�[�^����������
		for (int i = 0; i < RANKING_DATA; i++)
		{
			fprintf(fp, "%2d %10s %10d\n", g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
		}

		// �t�@�C���N���[�Y
		fclose(fp);

		return 0;

	}

/*************************************
 * �����L���O�f�[�^�ǂݍ���
*************************************/
	int ReadRanking(void)
	{
		FILE* fp;
#pragma warning(disable:4996)

		// �t�@�C���I�[�v��
		if ((fp = fopen("dat/rankingdata.txt", "r")) == NULL)
		{
			// �G���[����
			printf("Ranking Data Error\n");
			return -1;
		}

		// �����L���O�f�[�^�z����f�[�^��ǂݍ���
		for (int i = 0; i < RANKING_DATA; i++)
		{
			int dammy = fscanf(fp, "%2d %10s %10d", &g_Ranking[i].no, g_Ranking[i].name, &g_Ranking[i].score);
		}

		// �t�@�C���N���[�Y
		fclose(fp);

		return 0;
	}
		//�����L���O�摜�ǂݍ���
		int LoadRankingImage()
		{
			// �����L���O�摜�Ǎ�
			if ((g_RankingImg = LoadGraph("images/Ranking/input.png")) == -1) return -1;

			return 0;
		}