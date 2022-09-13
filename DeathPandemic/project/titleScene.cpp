#include "titleScene.h"
#include <DxLib.h>
#include "app.h"

namespace {
	int title;
	int titleback;
	int cursor;
	int x = 250;
	int y = 350;
	int sousa;
	int  title_bgm;
	int kettei;

	bool PressUpBefore = false;
	bool PressUpNow = false;
	bool PressDownBefore = false;
	bool PressDownNow = false;
	bool PressEnterBefore_2 = false;
	bool PressEnterNow_2 = false;
	bool PressEnterBefore_1 = false;
	bool PressEnterNow_1 = false;
	bool Load = false;
};



//int LifeMain=10000;
//bool beforePress = false;
//bool nowPress = false;

void TitleSceneInit()
{
	if (Load == false)
	{
		title = LoadGraph("data\\texture\\title.png");
		titleback = LoadGraph("data\\texture\\titleback2.png");
		cursor = LoadGraph("data\\texture\\jikishot.png");
		sousa = LoadSoundMem("data\\sound\\sousa.wav");
		title_bgm = LoadSoundMem("data\\sound\\DeathEPandemic.wav");
		kettei = LoadSoundMem("data\\sound\\kettei.wav");
		PlaySoundMem(title_bgm, DX_PLAYTYPE_BACK);
	}
	
	Load = true;
}

void TitleSceneUpdate()
{
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		PressEnterNow_1 = true;
		if (PressEnterBefore_1 == false)
		{
			if (y == 350) 
			{
				StopSoundMem(title_bgm);
				ChangeScene(PLAY_SCENE);
				
			}
			
			PlaySoundMem(kettei, DX_PLAYTYPE_BACK);
		}
	}
	if (!CheckHitKey(KEY_INPUT_RETURN))
	{
		PressEnterNow_1 = false;
	}
	
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		PressEnterNow_2 = true;
		if (PressEnterBefore_2 == false)
		{
			if (y == 400)
			{
				ChangeScene(OPERATE_SCENE);
			}
			PlaySoundMem(kettei, DX_PLAYTYPE_BACK);
		}
	}
	if (!CheckHitKey(KEY_INPUT_RETURN))
	{
		PressEnterNow_2 = false;
	}
	PressEnterBefore_1 = PressEnterNow_1;
	PressEnterBefore_2 = PressEnterNow_2;
}

void TitleSceneDraw()
{
	int Cr = GetColor(255, 255, 255);

	DrawGraph(0, 0, titleback, TRUE);
	DrawGraph(-10, -60, title, TRUE);
	DrawGraph(x, y, cursor, TRUE);
	
	if (CheckHitKey(KEY_INPUT_UP) || CheckHitKey(KEY_INPUT_W))
	{
		PressUpNow = true;

		if (PressUpBefore == false)
		{
			if (y == 400)
			{
				y = y - 50;
				PlaySoundMem(sousa, DX_PLAYTYPE_BACK);
			}
			
		}
	}
	if (!CheckHitKey(KEY_INPUT_UP) || !CheckHitKey(KEY_INPUT_W))
	{
		PressUpNow = false;
	}

	if (CheckHitKey(KEY_INPUT_DOWN) || CheckHitKey(KEY_INPUT_S))
	{
		PressDownNow = true;

		if (PressDownBefore == false)
		{
			if (y == 350)
			{
				y = y + 50;
				PlaySoundMem(sousa, DX_PLAYTYPE_BACK);
			}
			
		}
	}
	if (!CheckHitKey(KEY_INPUT_DOWN) || !CheckHitKey(KEY_INPUT_S))
	{
		PressDownNow = false;
	}

	PressUpBefore = PressUpNow;
	PressDownBefore = PressDownNow;
}

void TitleSceneRelease()
{
	/*if (title_bgm> 0)
	{
		DeleteSoundMem(title_bgm);
	}*/
}
