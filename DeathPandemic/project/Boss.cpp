#include<DxLib.h>
#include <assert.h>
#include "common.h"
#include "config.h"
#include"Boss.h"

namespace//名前空間＿この中で書かれた名前は、外から呼ぶとき先頭に名前空間の修飾をつける(例　a::　)別のところで同じ名前を宣言してしまう感じのために
{
	struct ENEMY
	{
		bool active;//描画するか否か
		POSITION pos;//敵の位置
		int deadCounter;//死亡判定用カウント
		double ysp = -1;
		double ysp_sp = 0.01;
		int ysp_f = 0;
		int hp = 50;

	};
	int frameCounter = 0;
	int BOSSLIFE = 100;
	static const int BOSS_NUM = 5;//constは変わらない変数
	ENEMY boss[BOSS_NUM];//敵の数は5で固定
	int spawnCounter = 60;
	int Boss[5] = { -1, -1, -1, -1, -1 };
};



void BossInit()
{
	Boss[2] = LoadGraph("data\\texture\\bossbody_2.png");
	assert(Boss[2] > 0);
	Boss[3] = LoadGraph("data\\texture\\bosslarm_2.png");
	assert(Boss[3] > 0);
	Boss[4] = LoadGraph("data\\texture\\bossrarm_2.png");
	assert(Boss[4] > 0);
	Boss[1] = LoadGraph("data\\texture\\bossleg_2.png");
	assert(Boss[1] > 0);
	Boss[0] = LoadGraph("data\\texture\\bossfirst_2.png");
	assert(Boss[0] > 0);

	for (int i = 0; i < BOSS_NUM; i++)
	{
		boss[i].active = false;
	}
	spawnCounter = 60;
}


void BossUpdate()
{
	frameCounter++;
	// 敵を生成する
	if (--spawnCounter <= 0) {
		for (int i = 0; i < BOSS_NUM; i++) {
			if (!boss[i].active) {
				boss[i].pos.x = SCREEN_WIDTH - 742;
				boss[i].pos.y = 30;
				boss[i].active = true;
				
				boss[i].deadCounter = 0;
				break;
			}
		}
		spawnCounter = 30;
	}
	
	// 敵を行動する
	for (int i = 0; i < BOSS_NUM; i++) {
		if (!boss[i].active)
			continue;
		if (boss[i].deadCounter == 0) { // 生きている
			if (boss[i].ysp > 1) {
				boss[i].ysp_f = 1;
			}
			if (boss[i].ysp < -1) {
				boss[i].ysp_f = 0;
			}
			if (boss[i].ysp_f == 0) {
					boss[i].ysp += boss[i].ysp_sp; 
			}
			if (boss[i].ysp_f == 1) {
					boss[i].ysp -= boss[i].ysp_sp;
			}
			boss[i].pos.y += boss[i].ysp;
			if (boss[i].pos.x < -591.0)//画面外まで行くとfalse
				boss[i].active = false;

		}
		else { // 死んでいる
			if (++boss[i].deadCounter > 60)
				boss[i].active = false;
		}
	}
	if (frameCounter > 200)
	{
		boss[0].active = false;
	}
}


void BossDraw()
{
	if (CheckHitKey(KEY_INPUT_K))
	{
		BOSSLIFE = BOSSLIFE - 1;     //ここでボスライフの管理とりあえずしてます
	}
	/*DrawBox(300, 500, BOSSLIFE * 7+5, 510,
			GetColor(0, 255, 255), TRUE);*/

	//for (int i = 0; i < BOSS_NUM; i++)
	//{
	//	if (boss[i].active) 
	//	{
	//		DrawGraph(boss[i].pos.x, boss[i].pos.y,
	//			 Boss[i], TRUE);//patが増えればｙにずれてびょうが
	//	}
	//}

	
}
void BossRelease()
{
	if (Boss[0] > 0) 
	{
		DeleteGraph(Boss[0]);
		Boss[0] = -1;
	}
}

bool BossCollideStone2(CIRCLE stone2)
{
		for (int i = 0; i < BOSS_NUM; i++)
		{
		if (boss[i].active && boss[i].deadCounter == 0)
		{
			CIRCLE my2;
			my2.x = (int)boss[i].pos.x+32;
			my2.y = (int)boss[i].pos.y+32;
			my2.r = 20;
			if (CircleCollision2(my2, stone2)) {
				boss[i].deadCounter=1;
				return true;
			}
		}
	}
	return false;
}
