#include "playScene.h"
#include <DxLib.h>
#include "app.h"
#include "player.h"
#include "stones.h"
#include "enemies.h"
#include "Boss.h"
#include "score.h"
#include "Back.h"
#include "Boss.h"
#include "Item.h"
#include "timelimit.h"

void PlaySceneInit()
{
	PlayerInit();
	StonesInit();
	BossInit();
	EnemiesInit();
	BackInit();
	ScoreInit();
	ItemInit();
	TimeInit();
	int Play_bgm;
	
}

void PlaySceneUpdate()
{
	//if (CheckHitKey(KEY_INPUT_T)) {
	//	ChangeScene(TITLE_SCENE);
	//}
	PlayerUpdate();
	StonesUpdate();
	BackUpdate();
	EnemiesUpdate();
	BossUpdate();
	ItemUpdate();
	TimeUpdate();
	
}

void PlaySceneDraw()
{
	BackDraw();
	EnemiesDraw();
	BossDraw();
	PlayerDraw();
	StonesDraw();
	ScoreDraw();
	//DrawString(600, 10, "PLAY SCENE", GetColor(0, 0, 0));
	//DrawString(10, 570, "Push [T] Key To Title", GetColor(0, 0, 0));
	//DrawString(500, 550, "A,S,D,W移動", GetColor(0, 0, 0));
	//DrawString(500, 570, "G→分裂　SPASE→ショット", GetColor(0, 0, 0));
	//DrawString(20, 8, "H P", GetColor(0, 0, 0));
	ItemDraw();
	TimeDraw();
}

void PlaySceneRelease()
{
	PlayerRelease();
	StonesRelease();
	EnemiesRelease();
	BossRelease();
	ItemRelease();
}