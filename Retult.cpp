#include"DxLib.h"
#include"Result.h"

int g_ResultImg;					//リザルト画像用
int page = 0;		//ページ移動

//エンド描画
void DrawResult(int key, int& gamemode, int score)
{
	//リザルト画像表示
	DrawGraph(0, 0, g_ResultImg, FALSE);

	static int menuNo = 0;

	//リザルト画面から選択画面に移動する用
	if (key & PAD_INPUT_4) {
		page = 1;

	}
	switch (page) {
	case 0:
		//リザルト画像表示
		DrawGraph(0, 0, g_ResultImg, FALSE);
		SetFontSize(46);//フォントサイズ設定

		//スコア表示
		DrawFormatString(830, 350, 0xff4040, "%d", score);

		if (key & PAD_INPUT_B)
		{
			switch (menuNo)
			{
			case 0:
				gamemode = 2;	//ゲームメインに飛ぶ
				break;
			case 1:
				gamemode = 0;	//タイトル
				break;
			case 2:
				gamemode = 7;	//エンドに飛ぶ
				break;
			}

		}
		break;
	}
}
//リザルト画像読み込み
int LoadResultImage()
{
	if ((g_ResultImg = LoadGraph("images/Result/Score.png")) == -1)return -1;	//リザルト画像読込

	return 0;
}