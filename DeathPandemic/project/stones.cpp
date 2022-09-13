#include "stones.h"
#include <DxLib.h>
#include <assert.h>
#include "common.h"
#include "config.h"
#include "enemies.h"
#include "score.h"
#include"Boss.h"

namespace {
	struct STONE {
		bool active;
		POSITION pos;
		int SP = 20;
	};
	static const int STONE_NUM = 1110;
	STONE stones[STONE_NUM];
	int hImage = -1;
	int hSound = -1;
};

void StonesInit()
{
	hImage = LoadGraph("data\\texture\\jikishot.png");
	assert(hImage>0);
	hSound = LoadSoundMem("data\\sound\\se_maoudamashii_element_fire06.mp3");
	assert(hSound>0);
	for (int i=0; i<STONE_NUM; i++) {
		stones[i].active = false;
	}
}

void StonesRelease()
{
	if (hImage > 0) {
		DeleteGraph(hImage);
		hImage = -1;
	}
	if (hSound > 0) {
		DeleteSoundMem(hSound);
		hSound = -1;
	}
}

void StonesUpdate()
{
	for (int i = 0; i < STONE_NUM; i++) {
		if (stones[i].active) {
			stones[i].pos.x += stones[i].SP;
			if (stones[i].SP > 5)
			{
				stones[i].SP -= 0.5;
			}
			if (stones[i].pos.x > SCREEN_WIDTH) {
				stones[i].active = false;
				stones[i].SP = 20;
			}
			CIRCLE c1;
			//CIRCLE c2;
			c1.x = (int)stones[i].pos.x+10;
			c1.y = (int)stones[i].pos.y+10;
			c1.r = 10;
		//	c2.x = (int)stones[i].pos.x + 10;
		//	c2.y = (int)stones[i].pos.y + 10;
		//	c2.r = 10;
			if (EnemyCollideStone1(c1)) {
				stones[i].active = false;
				stones[i].SP = 20;
				PlaySoundMem(hSound, DX_PLAYTYPE_BACK);
				ScoreAdd(1000);//点数
				
//if(BossCollideStone2(c2))
				//{
				//	stones[i].active = false;
				//	PlaySoundMem(hSound, DX_PLAYTYPE_BACK);
				//	ScoreAdd(9000);//点数
				//}
				//ScoreAdd(1000);//点数

				//if(BossCollideStone2(c2))
				//{
				//	stones[i].active = false;
				//	PlaySoundMem(hSound, DX_PLAYTYPE_BACK);
				//	ScoreAdd(9000);//点数
				//}		
			}
		}
	}
}

void StonesDraw()
{
	for (int i = 0; i < STONE_NUM; i++) {
		if (stones[i].active) {
			DrawGraph((int)stones[i].pos.x, (int)stones[i].pos.y,
				hImage, TRUE);
		}
	}
}

void CreateStone(POSITION _pos)
{
	for (int i=0; i<STONE_NUM; i++) {
		if (stones[i].active)
			continue;
		stones[i].pos = _pos;
		stones[i].active = true;
		return;
	}
}
