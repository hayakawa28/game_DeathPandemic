#pragma once
// �v���C���[�Ɋւ��邱�Ƃ𑀍삷��N���X
#include "common.h"
void PlayerCollide();
void PlayerInit();
void PlayerUpdate();
void PlayerDraw();
void PlayerRelease();

bool PlayerCollideEnemy(CIRCLE Player, int enemy_id);
//bool PlayerCollideItem(CIRCLE item,int item_id);
bool PlayerCollideItem(CIRCLE item);