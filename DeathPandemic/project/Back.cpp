#include "Back.h"
#include <DxLib.h>
#include <assert.h>
#include "common.h"
#include "config.h"
float gh1_x = 0;
float gh1_y = 0;
float gh1_x2 = 0;
float gh1_y2 = 0;
namespace {
	struct ENEMY {
		bool active;
		POSITION pos;
		int animCounter;
		int deadCounter;
	};
	static const int ENEMY_NUM = 20;
	ENEMY enemies[ENEMY_NUM];
	int spawnCounter = 60;
	int hImage = -1;
	int aImage = -1;
};
void BackInit()
{
	hImage = LoadGraph("data\\texture\\DP_BG_kari.png");
	aImage = LoadGraph("data\\texture\\DP_BG_kari2.png");   
	assert(hImage > 0);
	for (int i = 0; i < ENEMY_NUM; i++)
		enemies[i].active = false;
	spawnCounter = 60;
}
void BackUpdate()
{
	// “G‚ð¶¬‚·‚é
	if (--spawnCounter <= 0) {
		for (int i = 0; i < ENEMY_NUM; i++) {
			if (!enemies[i].active) {
				enemies[i].pos.x = SCREEN_WIDTH;
				enemies[i].pos.y = GetRand(SCREEN_HEIGHT - 64);
				enemies[i].active = true;
				enemies[i].animCounter = 0;
				enemies[i].deadCounter = 0;
				break;
			}
		}
		spawnCounter = 30;
	}
	// “G‚ðs“®‚·‚é
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (!enemies[i].active)
			continue;
		if (enemies[i].deadCounter == 0) { // ¶‚«‚Ä‚¢‚é
			enemies[i].pos.x -= 2.0;
			if (enemies[i].pos.x < -64.0)
				enemies[i].active = false;
			enemies[i].animCounter++;
		}
		else { // Ž€‚ñ‚Å‚¢‚é
			if (++enemies[i].deadCounter > 60)
				enemies[i].active = false;
		}
	}
}
void BackDraw()
{
	const float ScrollSpeed = 3.0f;
	const float ScrollSpeed2 = 5.0f;
	int sizeX = 0;
	int sizeY = 0;
	GetGraphTextureSize(hImage, &sizeX, &sizeY);
	gh1_x -= ScrollSpeed;
	if (gh1_x <= -800)
	{
		gh1_x = 0;
	}
	for (int i = 0; i < 2; i++)
	{
		DrawGraph(gh1_x + (800 * i), gh1_y, hImage, TRUE);
	}
	gh1_x2 -= ScrollSpeed2;
	if (gh1_x2 <= -800)
	{
		gh1_x2 = 0;
	}
	for (int i = 0; i < 2; i++)
	{
		DrawGraph(gh1_x2 + (800 * i), gh1_y2, aImage, TRUE);
	}
}
/*void BackRelease()
{
	if (hImage > 0) {
		DeleteGraph(hImage);
		hImage = -1;
	}
}*/