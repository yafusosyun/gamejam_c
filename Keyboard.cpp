#include"DxLib.h"
#include"keyboard.h"

#define CENTER_X 320      //��  720�@�p�ō�����L�[�{�[�h�𖳗���蒆�S�Ɏ����Ă���
#define CENTER_Y 120      //����480�@�s�v�Ȏ��� CENTER_X,Y ��0�ɂ��Ă�������

#define ALPHA_MAX 26      //�A���t�@�x�b�g����

#define OUT_WIDTH 45 + CENTER_X     //��ʍ��[�`�L�[�{�[�h�܂ł̕�
#define OUT_HEIGHT 200 + CENTER_Y    //��ʏ�[�`�L�[�{�[�h�܂ł̍���
#define SPACE 10          //�L�[�Ԃ̃X�y�[�X
#define KEY_WIDTH 40      //�m�[�}���L�[�̕�

const int CurStdX = OUT_WIDTH + SPACE + 5;    //�J�[�\����X���W�    (�u5�v�̓J�[�\���̕� �j
const int CurStdY = OUT_HEIGHT + SPACE + 5;   //�J�[�\����Y���W�

//���͕���   �i���ۂɕ\������Ă���L�[�{�[�h�Ɠ����z�u�j
const char AllStr[5][ALPHA_MAX / 2 + 1] = {
	"ABCDEFGHIJKLM",
	"NOPQRSTUVWXYZ",
	"abcdefghijklm",
	"nopqrstuvwxyz",
	"0123456789"
};
