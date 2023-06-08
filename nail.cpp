#include<DxLib.h>
#include<stdio.h>
#include"nail.h"
#include"Timing.h"

/***********************************
*@•Ï”‚ÌéŒ¾iƒNƒ[ƒoƒ‹•Ï”j
************************************/

/*******************
ŠÖ”éŒ¾
*************************/



void Nail::Init() {
	count = 0;
	miss = 0;
	fps = 0;
}




/***********************************
* ‰æ‘œ“Çž
************************************/
int Nail::LoadImages(void)
{
	//“B‚ð‘Å‚Â‘O
	 Start = LoadGraph("images/Start.png");

	 //1‰ñ–Ú
	 F = LoadGraph("images/F.png");
	 T = LoadGraph("images/T.png");
	
	
	 //2‰ñ–Ú
	 TT = LoadGraph("images/TT.png");
	FF = LoadGraph("images/FF.png");
	TF = LoadGraph("images/TF.png");

	//3‰ñ–Ú
	 TTF = LoadGraph("images/TTF.png");
	 TTT = LoadGraph("images/TTT.png");
	 FFT = LoadGraph("images/FFT.png");
	 FFF = LoadGraph("images/FFT.png");

	 //4‰ñ–Ú
	 FFFF = LoadGraph("images/FFFF.png");
	 FFFT = LoadGraph("images/FFFT.png");
	 TTFF = LoadGraph("images/TTFF.png");
	 TTTF = LoadGraph("images/TTTF.png");
	 TTTT = LoadGraph("images/TTTT.png");
	return 0;
}

/**********************************
“B‚ÌƒVƒXƒeƒ€
*****************************/
void Nail::nail(void)
{

	switch (count) {

	case 0://“B‚ð‘Å‚Â‘O
			DrawGraph(450, 150, Start, TRUE);
			miss = 0;
			break;

	case 1://“B‚ð‘Å‚Â1‰ñ–Ú
		if (judge == 0)
		{
			DrawGraph(450, 150, F, TRUE);//1‰ñ–Úƒ~ƒX
			miss = 1;
		}
		else
			DrawGraph(450, 150, T, TRUE);//1‰ñ–Ú¬Œ÷
		break;
			
	case 2://“B‚ð‘Å‚Â2‰ñ–Ú
		if (judge == 0)
		{
			if (miss == 1 || miss == 2)
			{
				DrawGraph(450, 150, FF, TRUE);//2‰ñ˜A‘±Ž¸”s
				miss = 2;
			}
			else 
			{
				DrawGraph(450, 150, TF, TRUE);//2‰ñ–Ú¬Œ÷
				miss = 1;
			}
		}
		
		else
		{
			if (miss == 2) {
				DrawGraph(450, 150, FF, TRUE);
			}
			if (miss == 1) {
				DrawGraph(450, 150, TF, TRUE);//2‰ñ–Ú¬Œ÷
			}
			else if (miss == 0) {
				DrawGraph(450, 150, TT, TRUE);//2‰ñ–Ú˜A‘±¬Œ÷
			}
		}
		break;

	case 3://“B‚ð‘Å‚Â3‰ñ–Ú
		if (judge == 0)
		{
			if (miss == 0) {
				DrawGraph(450, 150, TTF, TRUE);//2‰ñ¬Œ÷A1‰ñŽ¸”s
				miss = 1;
			}

			else if (miss == 1) {
				DrawGraph(450, 150, FFT, TRUE);//2‰ñŽ¸”sA1‰ñ¬Œ÷
			}

			else if (miss == 2 || miss == 3)
			{
				DrawGraph(450, 150, FFF, TRUE);//3‰ñ˜A‘±Ž¸”s
				miss = 3;
			}
		}
		else {
			if (miss == 2)
			{
			DrawGraph(450, 150, FFT, TRUE);//2‰ñŽ¸”sA1‰ñ¬Œ÷
			}
			else if (miss == 1)
			{
			DrawGraph(450, 150, TTF, TRUE);//2‰ñ¬Œ÷A1‰ñŽ¸”s
			}
			else if (miss == 0)
			{
			DrawGraph(450, 150, TTT, TRUE);//3‰ñ˜A‘±¬Œ÷
			}
		}
		break;

	case 4://“B‚ð‘Å‚Â4‰ñ–ÚiÅŒã‚Ì–„‚Ü‚é‚Æ‚±‚ëj
		if (judge == 0)
		{
			if (miss == 3 || miss == 4)
			{
				DrawGraph(450, 150, FFFF, TRUE);//4‰ñ˜A‘±ƒ~ƒX
				miss = 4;
			}
			
			else if (miss == 3)//3‰ñŽ¸”sA1‰ñ¬Œ÷
			{
				DrawGraph(450, 150, FFFT, TRUE);
			}
			else if (miss == 2)
			{
				DrawGraph(450, 150, TTFF, TRUE);//2‰ñŽ¸”sA2¬Œ÷a
			}
			else if (miss == 1)
			{
				DrawGraph(450, 150, TTTF, TRUE);//3‰ñ¬Œ÷A1‰ñŽ¸”sa
			}
			else if (miss == 0)
			{
				DrawGraph(450, 150, TTTT, TRUE);//4‰ñ˜A‘±¬Œ÷a
			}
		}
		else {
			if (miss == 3)//3‰ñŽ¸”sA1‰ñ¬Œ÷
			{
			DrawGraph(450, 150, FFFT, TRUE);
			}
			else if (miss == 2)
			{
			DrawGraph(450, 150, TTFF, TRUE);//2‰ñŽ¸”sA2¬Œ÷a
			}
			else if (miss == 1)
			{
			DrawGraph(450, 150, TTTF, TRUE);//3‰ñ¬Œ÷A1‰ñŽ¸”sa
			}
			else if (miss == 0)
			{
			DrawGraph(450, 150, TTTT, TRUE);//4‰ñ˜A‘±¬Œ÷a
			}
		}
		break;
			
	}
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
