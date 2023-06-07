#include<DxLib.h>
#include<stdio.h>
#include"nail.h"
#include"Timing.h"

/***********************************
*�@�ϐ��̐錾�i�N���[�o���ϐ��j
************************************/

/*******************
�֐��錾
*************************/


/********************
�v���O�����̊J�n
***************************/
//int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hprevInstance, _In_ LPSTR lpCmdLine, _In_
//	int nCmdShow)
//{
//  
//	ChangeWindowMode(TRUE); // �E�B���h�E���[�h�ݒ�
//	if (DxLib_Init() == -1) return -1; // DX���C�u��������������
//
//	//�摜�Ǎ��֐��̌Ăяo��
//	if (LoadImages() == -1) return -1;
//
//	nail();
//
//
//	WaitKey(); // ���ʂ����邽�߂ɃL�[�҂�
//	
//
//	DxLib_End(); // DX���C�u�����g�p�̏I������
//	return 0; // �\�t�g�̏I��
//}

void Nail::Init() {
	count = 0;
	miss = 0;
	fps = 0;
}




/***********************************
* �摜�Ǎ�
************************************/
int Nail::LoadImages(void)
{
	//�B��łO
	 Start = LoadGraph("images/Start.png");

	 //1���
	 F = LoadGraph("images/F.png");
	 T = LoadGraph("images/T.png");
	
	
	 //2���
	 TT = LoadGraph("images/TT.png");
	FF = LoadGraph("images/FF.png");
	TF = LoadGraph("images/TF.png");

	//3���
	 TTF = LoadGraph("images/TTF.png");
	 TTT = LoadGraph("images/TTT.png");
	 FFT = LoadGraph("images/FFT.png");
	 FFF = LoadGraph("images/FFT.png");

	 //4���
	 FFFF = LoadGraph("images/FFFF.png");
	 FFFT = LoadGraph("images/FFFT.png");
	 TTFF = LoadGraph("images/TTFF.png");
	 TTTF = LoadGraph("images/TTTF.png");
	 TTTT = LoadGraph("images/TTTT.png");
	return 0;
}

/**********************************
�B�̃V�X�e��
*****************************/
void Nail::nail(void)
{

	switch (count) {

	case 0://�B��łO
			DrawGraph(450, 150, Start, TRUE);
			miss = 0;
			break;

	case 1://�B��ł�1���
		if (judge == 0)
		{
			DrawGraph(450, 150, F, TRUE);//1��ڃ~�X
			miss = 1;
		}
		else
			DrawGraph(450, 150, T, TRUE);//1��ڐ���
		break;
			
	case 2://�B��ł�2���
		if (judge == 0)
		{
			if (miss == 1 || miss == 2)
			{
				DrawGraph(450, 150, FF, TRUE);//2��A�����s
				miss = 2;
			}
			else 
			{
				DrawGraph(450, 150, TF, TRUE);//2��ڐ���
				miss = 1;
			}
		}
		
		else
		{
			if (miss == 2) {
				DrawGraph(450, 150, FF, TRUE);
			}
			if (miss == 1) {
				DrawGraph(450, 150, TF, TRUE);//2��ڐ���
			}
			else if (miss == 0) {
				DrawGraph(450, 150, TT, TRUE);//2��ژA������
			}
		}
		break;

	case 3://�B��ł�3���
		if (judge == 0)
		{
			if (miss == 0) {
				DrawGraph(450, 150, TTF, TRUE);//2�񐬌��A1�񎸔s
				miss = 1;
			}

			else if (miss == 1) {
				DrawGraph(450, 150, FFT, TRUE);//2�񎸔s�A1�񐬌�
			}

			else if (miss == 2 || miss == 3)
			{
				DrawGraph(450, 150, FFF, TRUE);//3��A�����s
				miss = 3;
			}
		}
		else {
			if (miss == 2)
			{
			DrawGraph(450, 150, FFT, TRUE);//2�񎸔s�A1�񐬌�
			}
			else if (miss == 1)
			{
			DrawGraph(450, 150, TTF, TRUE);//2�񐬌��A1�񎸔s
			}
			else if (miss == 0)
			{
			DrawGraph(450, 150, TTT, TRUE);//3��A������
			}
		}
		break;

	case 4://�B��ł�4��ځi�Ō�̖��܂�Ƃ���j
		if (judge == 0)
		{
			if (miss == 3 || miss == 4)
			{
				DrawGraph(450, 150, FFFF, TRUE);//4��A���~�X
				miss = 4;
			}
			
			else if (miss == 3)//3�񎸔s�A1�񐬌�
			{
				DrawGraph(450, 150, FFFT, TRUE);
			}
			else if (miss == 2)
			{
				DrawGraph(450, 150, TTFF, TRUE);//2�񎸔s�A2����a
			}
			else if (miss == 1)
			{
				DrawGraph(450, 150, TTTF, TRUE);//3�񐬌��A1�񎸔sa
			}
			else if (miss == 0)
			{
				DrawGraph(450, 150, TTTT, TRUE);//4��A������a
			}
		}
		else {
			if (miss == 3)//3�񎸔s�A1�񐬌�
			{
			DrawGraph(450, 150, FFFT, TRUE);
			}
			else if (miss == 2)
			{
			DrawGraph(450, 150, TTFF, TRUE);//2�񎸔s�A2����a
			}
			else if (miss == 1)
			{
			DrawGraph(450, 150, TTTF, TRUE);//3�񐬌��A1�񎸔sa
			}
			else if (miss == 0)
			{
			DrawGraph(450, 150, TTTT, TRUE);//4��A������a
			}
		}
		break;
			
	}
	DrawFormatString(50, 600, 0xffffff, "miss%d", miss);
	DrawFormatString(50, 650, 0xffffff, "count%d", count);
}

void Nail::Draw() {
	DrawGraph(0, 0, TTTT, TRUE);
}

void Nail::SetNailCount() {
	count += 1;
}

void Nail::Update() {
	judge = Timing::GetJudge();

	if (count == 4 && fps++ >= 60) {
		count = 0;
		fps = 0;
	}
}
