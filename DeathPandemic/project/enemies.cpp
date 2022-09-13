#include "enemies.h"
#include <DxLib.h>
#include <assert.h>
#include "common.h"
#include "config.h"
#include "player.h"
#include "Item.h"
#include <time.h>

namespace {//名前空間＿この中で書かれた名前は、外から呼ぶとき先頭に名前空間の修飾をつける(例　a::　)別のところで同じ名前を宣言してしまう感じのために
	struct ENEMY {
		bool active;//描画するか否か
		POSITION pos;//敵の位置
		int animCounter;//アニメーションのためのカウント
		int deadCounter;//死亡判定用カウント
		int ID;
	};
	static const int ENEMY_NUM = 10000;//constは変わらない変数
	ENEMY enemies[ENEMY_NUM];//敵の数は２０で固定
	ENEMY item[ENEMY_NUM];
	int spawnCounter = 6;
	int hImage = -1;
	int iImage = -1;
	int ENEMY_ID = 0;
	const int MAXHAGE = 8;
	int gf[MAXHAGE];
	int gfanicount = 0;
};

int getdieX, getdieY, diecounter;
void EnemiesInit()
{
	hImage = LoadGraph("data\\texture\\enemy2.png");
	iImage = LoadGraph("data\\texture\\itemmotienemy_ahonoyatu2.png");
	assert(hImage > 0);

	for (int i = 0; i < ENEMY_NUM; i++)
	{
		enemies[i].active = false;
		item[i].active = false;
	}
	spawnCounter = 6;
	LoadDivGraph("data\\texture\\Eeyann.png", 8, 8, 1, 80, 80, gf);
}

void EnemiesUpdate()
{
	// 敵を生成する
	if (--spawnCounter <= 0) {
		for (int i = 0; i < ENEMY_NUM; i++) {
			if (!enemies[i].active) {
				enemies[i].pos.x = SCREEN_WIDTH;
				enemies[i].pos.y = GetRand(SCREEN_HEIGHT - 64);
				enemies[i].active = true;
				enemies[i].ID = ENEMY_ID;
				ENEMY_ID++;
				enemies[i].animCounter = 0;
				enemies[i].deadCounter = 0;
				break;
			}
		}
		spawnCounter = 6;
	}

	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (enemies[i].active)
		{
			//プレイヤーの衝突判定＆ダメージ
			CIRCLE cl;
			cl.x = enemies[i].pos.x + 32;
			cl.y = enemies[i].pos.y + 32;
			cl.r = 32;
			PlayerCollideEnemy(cl, enemies[i].ID);
		}
	}

	// 敵を行動する
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (!enemies[i].active)
			continue;
		if (enemies[i].deadCounter == 0 && i % 7 == 0) { // 生きている
			enemies[i].pos.x -= 7.0;//速さ変更
			if (enemies[i].pos.x < -64.0)//画面外まで行くとfalse
				enemies[i].active = false;
			enemies[i].animCounter++;
		}
		else if (enemies[i].deadCounter == 0 && i % 7 == 1) { // 生きている
			enemies[i].pos.x -= 7.0;
			if (enemies[i].pos.x < -64.0)//画面外まで行くとfalse
				enemies[i].active = false;
			enemies[i].animCounter++;
		}
		else if (enemies[i].deadCounter == 0 && i % 7 == 2) { // 生きている
			enemies[i].pos.x -= 7.0;
			if (enemies[i].pos.x < -64.0)//画面外まで行くとfalse
				enemies[i].active = false;
			enemies[i].animCounter++;
		}
		else if (enemies[i].deadCounter == 0 && i % 7 == 3) { // 生きている
			enemies[i].pos.x -= 7.0;
			enemies[i].pos.y -= 1.0;
			if (enemies[i].pos.x < -64.0)//画面外まで行くとfalse
				enemies[i].active = false;
			enemies[i].animCounter++;
		}
		else if (enemies[i].deadCounter == 0 && i % 7 == 4) { // 生きている
			enemies[i].pos.x -= 7.0;
			enemies[i].pos.y += 1.0;
			if (enemies[i].pos.x < -64.0)//画面外まで行くとfalse
				enemies[i].active = false;
			enemies[i].animCounter++;
		}
		else if (enemies[i].deadCounter == 0 && i % 7 == 5) { // 生きている
			enemies[i].pos.x -= 7.0;
			enemies[i].pos.y -= 2.0;
			if (enemies[i].pos.x < -64.0)//画面外まで行くとfalse
				enemies[i].active = false;
			enemies[i].animCounter++;
		}
		else if (enemies[i].deadCounter == 0 && i % 7 == 6) { // 生きている
			enemies[i].pos.x -= 7.0;
			enemies[i].pos.y += 2.0;
			if (enemies[i].pos.x < -64.0)//画面外まで行くとfalse
				enemies[i].active = false;
			enemies[i].animCounter++;
		}
		else { // 死んでいる
			++gfanicount;
			if (++enemies[i].deadCounter > 60)
			{
				if (i % 6 == 0)
				{
					POSITION p_i;
					p_i.x = enemies[i].pos.x;
					p_i.y = enemies[i].pos.y;
					CreateItem(p_i);
				}
				enemies[i].active = false;
			}

		}
	}
}

void EnemiesDraw()
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (enemies[i].active) {
			if (i % 6 == 0)
			{
				int ipat = (enemies[i].animCounter / 8) % 4;//生きてたら０から３
				if (enemies[i].deadCounter > 0)//死んだら４
				{
					ipat = 3;
					DrawGraph((int)enemies[i].pos.x, (int)enemies[i].pos.y, gf[(enemies[i].deadCounter / 8) % 8], TRUE);
				}
				else
				{
					DrawRectGraph((int)enemies[i].pos.x, (int)enemies[i].pos.y,
						0, ipat * 64, 64, 64, iImage, TRUE, FALSE);//patが増えればｙにずれてびょうが
				}
			}

			else {
				int pat = (enemies[i].animCounter / 8) % 4;//生きてたら０から３
				if (enemies[i].deadCounter > 0)//死んだら４
				{
					pat = 3;
					DrawGraph((int)enemies[i].pos.x, (int)enemies[i].pos.y, gf[(enemies[i].deadCounter / 8) % 8], TRUE);
				}
				else {
					DrawRectGraph((int)enemies[i].pos.x, (int)enemies[i].pos.y,
						0, pat * 64, 64, 64, hImage, TRUE, FALSE);
				}//patが増えればｙにずれてびょうが
				
			}
		
	
		}

		if (enemies[i].deadCounter > 0)
		{
			DrawRectGraph(getdieX, getdieY, 0, 0, 64 * 8, hImage, TRUE, FALSE);
			DrawRectGraph(getdieX, getdieY, 0, 0, 64 * 8, iImage, TRUE, FALSE);
		}
	}
}

void EnemiesRelease()
{
	if (hImage > 0) {
		DeleteGraph(hImage);
		hImage = -1;
	}
}

bool EnemyCollideStone1(CIRCLE stone1)
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (enemies[i].active && enemies[i].deadCounter == 0) {
			CIRCLE my;
			my.x = (int)enemies[i].pos.x + 32;
			my.y = (int)enemies[i].pos.y + 32;
			my.r = 32;
			if (CircleCollision1(my, stone1)) {
				getdieX = enemies[i].pos.x;
				getdieY = enemies[i].pos.y;
				enemies[i].deadCounter = 1;
				return true;
			}
		}
	}
	return false;
}

bool EnemyCollidePlayer(CIRCLE Player)
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (enemies[i].active && enemies[i].deadCounter == 0) {
			CIRCLE my;
			my.x = (int)enemies[i].pos.x + 32;
			my.y = (int)enemies[i].pos.y + 32;
			my.r = 20;
			if (CircleCollision1(my, Player)) {
				getdieX = enemies[i].pos.x;
				getdieY = enemies[i].pos.y;

				/*enemies[i].deadCounter = 1;*/
				return true;
			}
		}
	}
	return false;
}
