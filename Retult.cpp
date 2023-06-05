#include"DxLib.h"
#include"Result.h"

int page = 0;		//ページ移動

//エンド描画
void DrawResult(int key, int& gamemode, int score)
{
	//リザルト画像表示
	//DrawGraph(0, 0, g_Img, FALSE);

	static int menuNo = 0;

	//リザルト画面から選択画面に移動する用
	if (key & PAD_INPUT_4) {
		page = 1;

	}
	switch (page) {
	case 0:
		SetFontSize(46);//フォントサイズ設定

		//スコア表示
		DrawFormatString(830, 350, 0xff4040, "%d", score);
	}
}