#pragma once

struct RankingData                            // �����L���O�f�[�^�\����
{
	int  no;
	char name[11];
	long score;
};

void SortRanking(void);  // �����L���O�̕��בւ�
int SaveRanking(void);   // �����L���O�f�[�^�̕ۑ�
int ReadRanking(void);   // �����L���O�f�[�^�̓Ǎ�

int LoadRankingImage();                        //�����L���O�摜�ǂݍ���
int LoadRankingSounds();                       //�����L���O�T�E���h�ǂݍ���