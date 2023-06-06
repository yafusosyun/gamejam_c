#include"DxLib.h"
#include"Result.h"
#include"GameMain.h"
#include"Ranking.h"
#include"PadInput.h"

AbstractScene* Result::Update() {	//描画以外の更新・変数の値の初期化・前の画面への上書き
	if (PadInput::OnClick(XINPUT_BUTTON_A)) {	//もし、Aキーが押されたら
		return new GameMain();		//ゲームメインに移動する
	}
	return this;					//それ以外ならこのシーンを描画し続ける
}

void Result::Draw()const		//描画に関することだけ
{
	DrawFormatString(20, 110, GetColor(255, 255, 255), "結果は・・・");
}