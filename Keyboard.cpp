#include"DxLib.h"
#include"keyboard.h"

#define CENTER_X 320      //幅  720　用で作ったキーボードを無理やり中心に持ってくる
#define CENTER_Y 120      //高さ480　不要な時は CENTER_X,Y を0にしてください

#define ALPHA_MAX 26      //アルファベット総数

#define OUT_WIDTH 45 + CENTER_X     //画面左端〜キーボードまでの幅
#define OUT_HEIGHT 200 + CENTER_Y    //画面上端〜キーボードまでの高さ
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

/************* 変数 *************/

int backimage = 0;            //背景画像
int Cursorimage[2] = { 0 };   //カーソル画像
int Cancelimage[2] = { 0 };   //画像をキャンセル
int OKimage[2] = { 0 };       //OK(確定)

//キーボード音声
int ClickKeyboard;
int CursorMoveKeyboard;

bool pushFlag = false;           //Aが　押されている/押されてない フラグ    TRUE:押されている　FALSE:押されていない

int frame = 0;                   //フレームをカウント

//移動量   (キーボード〇番目)
int movekeyX = 0;
int movekeyY = 0;

CURSOR_TYPE CURSOR_NOW = CURSOR_TYPE::NORMAL;  //現在のカーソル

char InputName[11];              //入力した文字が入る配列 0〜9に文字(10文字ﾏﾃﾞ)　10番目には \0 です
int input_Pos;                   //入力中の配列の〇番目

int key_font = 0;                //キーボードで使用するフォント

/********************************
*キーボード初期化
********************************/
void KeyBoardInit()
{
	//カーソルの初期位置は"A"
	movekeyX = 0;             //ｘ方向0番目
	movekeyY = 0;             //ｙ方向1番目

	//カーソルの初期位置は「A」なのでノーマル
	CURSOR_NOW = CURSOR_TYPE::NORMAL;

	//入力文字列　初期化
	for (int i = 0; i < 10; i++)
	{
		InputName[i] = 0;
	}
	InputName[10] = '\0';     //配列の一番最後に"\0"(終端の目印)を入れておく

	input_Pos = -1;           //

	pushFlag = FALSE;         //最初はAボタンは押されていない
	key_font = CreateFontToHandle(NULL, 30, 10, DX_FONTTYPE_ANTIALIASING_8X8);
}

//更新
void KeyBoard_Update(int nowkey)
{
	//フレーム数カウント
	frame++;


	//→ 右 
	if (nowkey & PAD_INPUT_RIGHT)
	{
		if (CursorControl() == true)
		{
			movekeyX++;     //タイミング調整 + 移動
			ChangeNextPlayVolumeSoundMem(180, CursorMoveKeyboard);
			PlaySoundMem(CursorMoveKeyboard, DX_PLAYTYPE_BACK);
		}
		if (movekeyX > 12) movekeyX = 0;   //右端以上で左端へ

		CURSOR_NOW = CURSOR_TYPE::NORMAL;  //現在のキーはノーマル
	}
	//← 左
	if (nowkey & PAD_INPUT_LEFT)
	{
		if (CursorControl() == true)
		{
			movekeyX--;     //タイミング調整 + 移動
			ChangeNextPlayVolumeSoundMem(180, CursorMoveKeyboard);
			PlaySoundMem(CursorMoveKeyboard, DX_PLAYTYPE_BACK);
		}
		if (movekeyX < 0) movekeyX = 12;     //左端以上で右端へ

		CURSOR_NOW = CURSOR_TYPE::NORMAL;    //現在のキーはノーマル
	}

	//↑ 上
	if (nowkey & PAD_INPUT_UP)
	{

		if (CursorControl() == true)
		{
			movekeyY--;     //タイミング調整 + 移動
			ChangeNextPlayVolumeSoundMem(180, CursorMoveKeyboard);
			PlaySoundMem(CursorMoveKeyboard, DX_PLAYTYPE_BACK);
		}
		if (movekeyY <= 0) movekeyY = 0;     //上端でストップ

		CURSOR_NOW = CURSOR_TYPE::NORMAL;         //現在のキーはノーマル
	}

	//↓ 下
	if (nowkey & PAD_INPUT_DOWN)
	{

		if (CursorControl() == true)
		{
			movekeyY++;     //タイミング調整 + 移動
			ChangeNextPlayVolumeSoundMem(180, CursorMoveKeyboard);
			PlaySoundMem(CursorMoveKeyboard, DX_PLAYTYPE_BACK);
		}

		CURSOR_NOW = CURSOR_TYPE::NORMAL;         //現在のキーはノーマル
	}

	//「×」ボタン   「a〜z」段より下 かつ 「9」キーより右側
	if (movekeyY == 4 && movekeyX >= 10)
	{
		movekeyX = 10;                       //ボタンの位置

		CURSOR_NOW = CURSOR_TYPE::CANCEL;         //現在のキーはキャンセル「×」
	}

	//「OK」ボタン   キーボード最下段より下
	if (movekeyY >= 5)
	{
		movekeyX = 4;                        //ボタンの位置
		movekeyY = 5;

		CURSOR_NOW = CURSOR_TYPE::DONE;           //現在のキーはDONE「OK」
	}
}

//カーソルの移動・ボタンの長押しを調整
bool CursorControl()
{
	int timing = 8;
	if (frame % timing == 0) return true;
	//frame = 0;

	return false;
}

//Bボタンが押された時の処理
int KeyBoard_PushB(int nowkey, char* name)
{
	//　Aボタンを押している間
	if (nowkey & PAD_INPUT_B)
	{
		//長押しでの連続入力のタイミングを調整
		if (CursorControl() == true)
		{
			// "A〜Z","a〜z","1〜9"の上で押された
			PlaySoundMem(ClickKeyboard, DX_PLAYTYPE_BACK);
			// "A〜Z","a〜z","1〜9"の上で押された
			if (CURSOR_NOW == CURSOR_TYPE::NORMAL)
			{
				pushFlag = true;        //押されているよ

				++input_Pos;            //入力位置を一つ右に

				//上限は10文字   （配列の0〜9）
				if (input_Pos > 9) input_Pos = 9;

				//文字配列に入力
				InputName[input_Pos] = AllStr[movekeyY][movekeyX];

			}
			else if (CURSOR_NOW == CURSOR_TYPE::CANCEL)                  //「×」キーの上で押された　一文字削除
			{
				pushFlag = true;        //押されているよ

				if (input_Pos >= 0)
				{
					//一文字でも入力されていれば一文字消す
					if (InputName[input_Pos] != 0) InputName[input_Pos] = 0; //0 は何も入力されていない状態

					input_Pos--;            //入力位置を一つ左に

					//入力位置は最低-1まで
					if (input_Pos < -1) input_Pos = -1;
				}

			}
			else if (CURSOR_NOW == CURSOR_TYPE::DONE)                  //「OK」キーの上で押された　確定
			{
				if (input_Pos >= 0)
				{
					//一文字も入力されていない場合は確定できない
					if (InputName[input_Pos] != 0)
					{
						//一文字でも入力アリ

						InputName[input_Pos + 1] = '\0';       //最後の文字の一つ右に'\0'

						//ランキングに入力内容をセット
						strcpy_s(name, 11, InputName);

						DeleteFontToHandle(key_font);
						return 1;   //終了
					}
					
				}
			}
		}
	}
	return 0;
}

//入力情報表示
void DrawInputInfo()
{
	if (InputName[0] == 0)
	{
		//SetDrawBlendMode

		//SetFontSize(20);                                     ↓　文字化け
		DrawStringToHandle(200 + CENTER_X, 125 + CENTER_Y, "Please Your Name", 0xffffff, key_font);
	}

	for (int i = 0; InputName[i] != '\0'; i++)
	{
		//SetFontSize(30);
		DrawFormatStringToHandle((220 + 20 * i) + CENTER_X, 120 + CENTER_Y, 0xffffff, key_font, " %c", InputName[i]);
	}
}