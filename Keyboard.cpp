#include"DxLib.h"
#include"keyboard.h"

#define CENTER_X 320      //幅  720　用で作ったキーボードを無理やり中心に持ってくる
#define CENTER_Y 120      //高さ480　不要な時は CENTER_X,Y を0にしてください

#define ALPHA_MAX 26      //アルファベット総数

#define OUT_WIDTH 45 + CENTER_X     //画面左端～キーボードまでの幅
#define OUT_HEIGHT 200 + CENTER_Y    //画面上端～キーボードまでの高さ
#define SPACE 10          //キー間のスペース
#define KEY_WIDTH 40      //ノーマルキーの幅

const int CurStdX = OUT_WIDTH + SPACE + 5;    //カーソルのX座標基準    (「5」はカーソルの幅 ）
const int CurStdY = OUT_HEIGHT + SPACE + 5;   //カーソルのY座標基準

//入力文字   （実際に表示されているキーボードと同じ配置）
const char AllStr[5][ALPHA_MAX / 2 + 1] = {
	"ABCDEFGHIJKLM",
	"NOPQRSTUVWXYZ",
	"abcdefghijklm",
	"nopqrstuvwxyz",
	"0123456789"
};
