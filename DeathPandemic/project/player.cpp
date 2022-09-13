#include "player.h"
#include <DxLib.h>
#include <assert.h>
#include "common.h"
#include "stones.h"
#include "config.h"
#include "enemies.h"
#include"app.h"
#include "Item.h"
#include<math.h>
namespace
{
	int hImage = -1;
	int hSound = -1;
	POSITION pos;
	bool spacePushed = true;
	int throwCounter = 0;
	int muteki_time[5][2] = { 0 };
	int left_s;
	int right_s;
	int up_s;
	int down_s;
	int collide_s;
	int item_s;
	int Play_bgm =1;
};
int act;
int cellX;
int cellY;
bool nowdivi = false;
bool  beforedivi = false;
int LifeMain;
bool beforePress = false;
bool nowPress = false;
bool BeforeCollide = false;
bool NowCollide = false;
int typ, next;
int hitID[100];
int hit_num = 0;
bool onlyOnce = true;
int cat;
int ui;
int uix = 0;
int uiy = 0;
int lpui = 0;
int lpuix = 0;
int lpuiy = 0;
struct MAIN {
	bool active;//描画するか否か
	POSITION pos;//敵の位置
	int animCounter;//アニメーションのためのカウント
	int deadCounter;//死亡判定用カウント
	int Life;
};
MAIN players[5][2];

bool PlayerCollideItem(CIRCLE item) {
	for (int x = 0; x < 2; x++)
	{
		for (int y = 0;  y < 5; y++) {
			if (players[y][x].active && players[y][x].deadCounter == 0) {
				CIRCLE my;
				my.x = players[y][x].pos.x;
				my.y = players[y][x].pos.y;
				my.r = 32;
				if (CircleCollision1(my, item)) {
					if (LifeMain < 10)
					{
						PlaySoundMem(item_s, DX_PLAYTYPE_BACK);
						LifeMain = LifeMain + 1;
					}
					return true;
				}
			}
		}
	}
	
	return false;
}
void PlayerInit()
{
	ui = LoadGraph("data\\texture\\ui.png");
	lpui = LoadGraph("data\\texture\\uilp.png");
	LifeMain = 16;
	hImage = LoadGraph("data\\texture\\jiki.png");
	assert(hImage > 0);
	hSound = LoadSoundMem("data\\sound\\throw.wav");
	assert(hSound > 0);
	 cat = GetRand(50);
	for (int x = 0; x < 2; x++)
	{
		for (int y = 0;  y < 5; y++)
		{
			players[y][x].active = false;
		}
	}
	players[0][0].pos.x = 100;
	players[0][0].pos.y = 100;
	players[0][0].Life = 20;
	players[0][0].active = true;
	spacePushed = true;
	throwCounter = 0;
	cellX = 0;
	cellY = 0;
	left_s = LoadSoundMem("data\\sound\\se_maoudamashii_se_sound24.mp3");
	right_s = LoadSoundMem("data\\sound\\se_maoudamashii_se_sound24.mp3");
	up_s = LoadSoundMem("data\\sound\\se_maoudamashii_se_sound24.mp3");
	down_s = LoadSoundMem("data\\sound\\se_maoudamashii_se_sound24.mp3");
	collide_s = LoadSoundMem("data\\sound\\se_maoudamashii_onepoint30.mp3");
	item_s = LoadSoundMem("data\\sound\\modoru.wav");
	Play_bgm = LoadSoundMem("data\\sound\\延命戦～Bio Trojan_ループ.wav");
	SetLoopPosSoundMem(8000, Play_bgm);
	assert(Play_bgm > 0);
	if (LifeMain > 1)
	{
		PlaySoundMem(Play_bgm, DX_PLAYTYPE_LOOP);
	}
	
}

void PlayerRelease()
{
	if (hImage > 0) {
		DeleteGraph(hImage);
		hImage = -1;
	}
	if (hSound > 0) {
		DeleteSoundMem(hSound);
		hSound = -1;
	}
	if (Play_bgm > 0)
	{
		DeleteSoundMem(Play_bgm);
	}
}

void PlayerUpdate()
{
	//ヒット後の無敵時間をデクリメント
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 3; y++) {
			if (muteki_time[y][x] > 0)
				muteki_time[y][x] -= 1;
		}
	}

	if (CheckHitKey(KEY_INPUT_W)|| CheckHitKey(KEY_INPUT_UP))
	{
		//PlaySoundMem(up_s, DX_PLAYTYPE_BACK);
		players[0][0].pos.y -= 6;
		if (players[0][0].pos.y < 64)
			players[0][0].pos.y = 64;
	}
	if (CheckHitKey(KEY_INPUT_S) || CheckHitKey(KEY_INPUT_DOWN))
	{
		//PlaySoundMem(down_s, DX_PLAYTYPE_BACK);
		players[0][0].pos.y += 6;
		if (players[0][0].pos.y > SCREEN_HEIGHT - 64)
			players[0][0].pos.y = SCREEN_HEIGHT - 64;
	}
	if (CheckHitKey(KEY_INPUT_A) || CheckHitKey(KEY_INPUT_LEFT))
	{
		//PlaySoundMem(left_s, DX_PLAYTYPE_BACK);
		players[0][0].pos.x -= 6;
		if (players[0][0].pos.x < 0)
			players[0][0].pos.x = 0;
	}
	if (CheckHitKey(KEY_INPUT_D) || CheckHitKey(KEY_INPUT_RIGHT))
	{
		//PlaySoundMem(right_s, DX_PLAYTYPE_BACK);
		players[0][0].pos.x += 6;
		if (players[0][0].pos.x > SCREEN_WIDTH - 64)
			players[0][0].pos.x = SCREEN_WIDTH - 64;
	}

	bool push = CheckHitKey(KEY_INPUT_SPACE);
	if (push && !spacePushed)
	{
		if (throwCounter == 0)
		{
			for (int x = 0; x < 2; x++)
			{
				for (int y = 0;  y < 5; y++)
				{
					if (players[y][x].active == true)
					{
						POSITION p_i;
						p_i.x = players[y][x].pos.x + 28;
						p_i.y = players[y][x].pos.y + 12;

						CreateStone(p_i);
					}
				}
			}
			PlaySoundMem(hSound, DX_PLAYTYPE_BACK);
			throwCounter = 10;//shot間隔
		}
	}
	if (throwCounter > 0)
		throwCounter--;
	spacePushed = push;

	beforedivi = nowdivi;
	nowdivi = false;
	if (CheckHitKey(KEY_INPUT_G) == 0)
	{
		nowdivi = false;
		onlyOnce = true;
	}
	else
	{
		nowdivi = true;
	}
	if (nowdivi == true && beforedivi == false)
	{
		for (int x = 0; x < 2; x++)
		{
			for (int y = 0;  y < 5; y++)
			{
				if (players[y][x].active == false && LifeMain > 1 && onlyOnce == true)// && players[5][2].active != true
				{
					players[y][x].active = true;
					onlyOnce = false;
					break;
				}
			}
		}
	}
	
	for (int x = 0; x < 2; x++)
	{
		for (int y = 0;  y < 5; y++)
		{
			if (players[y][x].active)
			{

				//players[y][x].pos.y = players[0][0].pos.y + (50 * y);//ウイルスの出現座標　旧
				//players[y][x].pos.x = players[0][0].pos.x - (50 * x);
				int uirusuY = ceil(y / 2) * (1 + ((y % 2) * -2));//ceilでy割る２の答えを小数点切り上げをしている　　　　　そこにーをかけたりかけなかったりしてうまいことしてる
				players[y][x].pos.y = players[0][0].pos.y + (50 * uirusuY);//ウイルスの出現座標
				players[y][x].pos.x = players[0][0].pos.x - (50 *x);
			}
		}
	}

	beforePress = nowPress;
	nowPress = false;
	if (CheckHitKey(KEY_INPUT_G) == 0)
	{
		nowPress = false;
	}
	else
	{
		nowPress = true;
	}

	if (nowPress == true && beforePress == false && LifeMain > 1)
	{
		LifeMain = LifeMain - 2;
		act++;
		if (act > 3)
		{
			act = 0;
		}
		if (LifeMain <= 0)
		{
			LifeMain = 1;
		}
	}
	for (int x = 0; x < 2; x++)
	{
		for (int y = 0;  y < 5; y++)
		{
			if (LifeMain <= 0)
			{
				players[y][x].active = false;
			}
		}
	}		
	if (LifeMain < 1)
	{
		ChangeScene(PLAY3_SCENE);
	}
	
}

void PlayerDraw()
{
	DrawGraph(uix, uiy, ui, TRUE);
	if (LifeMain >= 1)
	{
		DrawBox(100, 60, LifeMain * 30 + 100, 15,
			GetColor(100, 255, 0), TRUE);
	}
	DrawGraph(lpuix, lpuiy, lpui, TRUE);
	int cellX = 0;
	int cellY = 0;
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		cellY = 1 * 64;
		cellX = 2 * 64;
	}

	for (int x = 0; x < 2; x++)
	{
		for (int y = 0;  y < 5; y++)
		{
			if (players[y][x].active == true&& (muteki_time[y][x] % 4 < 2)) //無敵中点滅するのは　&&右のやつ
			{
				DrawRectGraph(players[y][x].pos.x, players[y][x].pos.y,
					cellX, cellY, 64, 64, hImage, TRUE);
			}
		}
	}
}

bool PlayerCollideEnemy(CIRCLE enemy, int enemy_id)
{
	for (int x = 0; x < 2; x++) {
		for (int y = 0;  y < 5; y++)
		{
			//★ヒット中なら当たり判定をとらない
			if (muteki_time[y][x] > 0)continue;

			if (players[y][x].active && players[y][x].deadCounter == 0) {
				CIRCLE my;
				my.x = (int)players[y][x].pos.x + 10;
				my.y = (int)players[y][x].pos.y + 10;
				my.r = 10;
				//プレイヤーのdamage処理
				if (CircleCollision1(my, enemy))
				{
					//★衝突したら無敵時間100フレーム
					LifeMain--;
					muteki_time[y][x] = 100;
					return true;
				}
			}
		}
	}
	return false;
}


