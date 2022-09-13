#include "Gameover.h"
#include<stdio.h>
#include <DxLib.h>
#include "config.h"
#include"Back.h"
#include "titleScene.h"
#include "playScene.h"
#include "app.h"
#include"player.h"


namespace
{
	int gameover[2] = { -1, -1 };
	int drawNum = 0;
	int gameoverx = 800;
	int gameovery = 600;
	int gameoverwidth;
	struct POSITION* pos;
	int Gameover_S;
	int Gameover_left;
	int Gameover_right;
	int Gameover_enter;
	bool PressLeftBefore = false;
	bool PressLeftNow = false;
	bool PressRightBefore = false;
	bool PressRightNow = false;
}
void GameoverInit()
{

	if (gameover[0] < 0)
		gameover[0] = LoadGraph("data\\texture\\gameovergamen (2).png");
	if (gameover[1] < 0)
		gameover[1] = LoadGraph("data\\texture\\gameovergamen (3).png");
	Gameover_S = LoadSoundMem("data\\sound\\modoru.wav");
	Gameover_left = LoadSoundMem("data\\sound\\sousa.wav");
	Gameover_right = LoadSoundMem("data\\sound\\sousa.wav");
	Gameover_enter = LoadSoundMem("data\\sound\\modoru.wav");
	PlaySoundMem(Gameover_S, DX_PLAYTYPE_BACK);
}
void GameoverUpdate()
{

	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		PressLeftNow = true;
		if (PressLeftBefore == false)
		{
			drawNum = 0;
			PlaySoundMem(Gameover_left, DX_PLAYTYPE_BACK);
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
			drawNum = 1;
			PlaySoundMem(Gameover_right, DX_PLAYTYPE_BACK);
		}
	}
	if (!CheckHitKey(KEY_INPUT_RIGHT))
	{
		PressRightNow = false;
	}
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		if (drawNum == 0)
		{
			ChangeScene(TITLE_SCENE);
			PlaySoundMem(Gameover_enter, DX_PLAYTYPE_BACK);
		}
		else
		{
			isGameEnd = true;
			PlaySoundMem(Gameover_enter, DX_PLAYTYPE_BACK);
		}
	}

	PressLeftBefore = PressLeftNow;
	PressRightBefore = PressRightNow;

}


void GameoverDraw()
{
	gameoverx = 0;
	gameovery = 0;
	gameoverwidth = 800;
	DrawGraph(gameoverx, gameovery, gameover[drawNum], TRUE);
}

