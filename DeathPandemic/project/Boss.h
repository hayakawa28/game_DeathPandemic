#pragma once
#include "common.h"

void BossInit();
void BossUpdate();
void BossDraw();
void BossRelease();

// �G�Ɛ΂̓����蔻�������
// �G�̉~���󂯎��A�������Ă���ΓG�����S������
// �������Ă����true��Ԃ�
bool BossCollideStone2(CIRCLE stone2);