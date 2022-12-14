#pragma once
#include "common.h"

void BossInit();
void BossUpdate();
void BossDraw();
void BossRelease();

// 敵と石の当たり判定をする
// 敵の円を受け取り、当たっていれば敵を死亡させる
// 当たっていればtrueを返す
bool BossCollideStone2(CIRCLE stone2);