#pragma once

//キーの種類
enum class CURSOR_TYPE
{
	NONE = 0,   // 入力0（なにも押されていない）
	NORMAL,     // A〜B,a〜b,1〜9
	CANCEL,     //「×」(ひとつ消す)
	DONE,       //「OK」(確定)

	MISS = 99
};
//更新
void KeyBoard_Update(int nowkey);                                 //nowkey　は"押されている"キー
//keyflg　 は"押された瞬間"キー
//カーソルの移動・ボタンの長押しを調整
bool CursorControl();

//Bボタンが押された時の処理  入力が終わると 1 が返ってくる
int KeyBoard_PushB(int nowkey, char* name);

//入力情報表示
void DrawInputInfo();