#pragma once
#include "common.h"

void EnemiesInit();
void EnemiesUpdate();
void EnemiesDraw();
void EnemiesRelease();

// 敵と石の当たり判定をする
// 敵の円を受け取り、当たっていれば敵を死亡させる
// 当たっていればtrueを返す
bool EnemyCollideStone1(CIRCLE stone1);
//bool EnemyCollidePlayer(CIRCLE Player);

bool PlayerCollideEnemy(CIRCLE Player, int enemy_id);