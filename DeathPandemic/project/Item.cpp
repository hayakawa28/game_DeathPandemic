#include "Item.h"
#include <DxLib.h>
#include <assert.h>
#include "common.h"
#include "config.h"
#include "enemies.h"
#include "score.h"
#include "Boss.h"
#include "player.h"

namespace
{
	struct ITEM
	{
		bool active;
		POSITION pos;
	};
	static const int ITEM_NUM = 1110;
	ITEM item[ITEM_NUM];
	int hImage = -1;
	int hSound = -1;
	int item_s;
};

void ItemInit()
{
	hImage = LoadGraph("data\\texture\\teamseisakuitem.png");
	assert(hImage > 0);
	hSound = LoadSoundMem("data\\sound\\hit.wav");
	assert(hSound > 0);
	for (int i = 0; i < ITEM_NUM; i++) {
		item[i].active = false;
	}
}

void ItemRelease()
{
	if (hImage > 0) 
	{
		DeleteGraph(hImage);
		hImage = -1;
	}
	if (hSound > 0)
	{
		DeleteSoundMem(hSound);
		hSound = -1;
	}
}

void ItemUpdate()
{
	for (int i = 0; i < ITEM_NUM; i++)
	{
		if (item[i].active)
		{
			item[i].pos.x -= 4.0;
			if (item[i].pos.x < -20) 
			{
				item[i].active = false;
			}
			CIRCLE c1;
			//CIRCLE c2;
			c1.x = (int)item[i].pos.x;
			c1.y = (int)item[i].pos.y;
			c1.r = 10;
			//	c2.x = (int)stones[i].pos.x + 10;
			//	c2.y = (int)stones[i].pos.y + 10;
			//	c2.r = 10;
			if (PlayerCollideItem(c1))
			{
				item[i].active = false;
				PlaySoundMem(hSound, DX_PLAYTYPE_BACK);
				ScoreAdd(100000);//“_”

				//if(BossCollideStone2(c2))
				//{
				//	stones[i].active = false;
				//	PlaySoundMem(hSound, DX_PLAYTYPE_BACK);
				//	ScoreAdd(9000);//“_”
				//}
			}
		}
	}
}

void ItemDraw()
{
	for (int i = 0; i < ITEM_NUM; i++)
	{
		if (item[i].active) 
		{
			DrawGraph((int)item[i].pos.x, (int)item[i].pos.y,
				hImage, TRUE);
		}
	}
}

void CreateItem(POSITION _pos)
{
	for (int i = 0; i < ITEM_NUM; i++) 
	{
		if (item[i].active)
			continue;
		item[i].pos = _pos;
		item[i].active = true;
		return;
	}
}
