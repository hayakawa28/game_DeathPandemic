#pragma once
// プレイヤーに関することを操作するクラス
#include "common.h"
void PlayerCollide();
void PlayerInit();
void PlayerUpdate();
void PlayerDraw();
void PlayerRelease();

bool PlayerCollideEnemy(CIRCLE Player, int enemy_id);
//bool PlayerCollideItem(CIRCLE item,int item_id);
bool PlayerCollideItem(CIRCLE item);