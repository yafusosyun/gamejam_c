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

//void SortRanking(void);  // �����L���O�̕��בւ�
//int SaveRanking(void);   // �����L���O�f�[�^�̕ۑ�
//int ReadRanking(void);   // �����L���O�f�[�^�̓Ǎ�

//int LoadRankingImage();                        //�����L���O�摜�ǂݍ���
