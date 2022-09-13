#include "Clear.h"


#include<stdio.h>
#include <DxLib.h>
#include "config.h"
#include"Back.h"
#include "titleScene.h"
#include "playScene.h"
#include "app.h"


namespace
{
	int clear[2] = { -1,-1 };
	int drawNum2 = 0;
	int clearx = 800;
	int cleary = 600;
	int clearwidth;
	struct POSITION* pos;
	int Clear_S;
	int Clear_left;
	int Clear_right;
	int Clear_enter;
	bool PressRightBefore = false;
	bool PressRightNow = false;
	bool PressLeftBefore = false;
	bool PressLeftNow = false;
}

void ClearInit()
{

	Clear_S = LoadSoundMem("data\\sound\\modoru.wav");
	Clear_left = LoadSoundMem("data\\sound\\sousa.wav");
	Clear_right = LoadSoundMem("data\\sound\\sousa.wav");
	Clear_enter = LoadSoundMem("data\\sound\\kettei.wav");
	if (clear[0] < 0) {
		clear[0] = LoadGraph("data\\texture\\gameclear1.png");
		if (clear[1] < 0)
		{
			clear[1] = LoadGraph("data\\texture\\gameclear2.png");
		}
	}
	PlaySoundMem(Clear_S, DX_PLAYTYPE_BACK);
}

void ClearUpdate()
{
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		PressLeftNow = true;
		if (PressLeftBefore == false)
		{
			drawNum2 = 0;
			PlaySoundMem(Clear_left, DX_PLAYTYPE_BACK);
		}
	}
	if (!CheckHitKey(KEY_INPUT_LEFT))
	{
		PressLeftNow = false;
	}

	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		PressRightNow = true;
		if (PressRightBefore == false)
		{
			drawNum2 = 1;
			PlaySoundMem(Clear_right, DX_PLAYTYPE_BACK);
		}
	}
	
	if (!CheckHitKey(KEY_INPUT_RIGHT))
	{
		PressRightNow = false;
	}

	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		PlaySoundMem(Clear_enter, DX_PLAYTYPE_BACK);
		if (drawNum2 == 0)
		{
			ChangeScene(TITLE_SCENE);
		}
		else
		{
			isGameEnd = true;
		}
	}
	PressLeftBefore = PressLeftNow;
	PressRightBefore = PressRightNow;

}



void ClearDraw()
{
	clearx = 0;
	cleary = 0;
	clearwidth = 800;
	DrawGraph(clearx, cleary, clear[drawNum2], TRUE);
}
