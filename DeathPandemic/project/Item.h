#pragma once
#include "common.h"

void ItemInit();
void ItemUpdate();
void ItemDraw();
void ItemRelease();

// �΂𐶐����܂��B
// _pos�̈ʒu�Ɉʒu�𐶐����āA�E�ɔ��ł����܂�
// �z�񂪂����ς��Ȃ�A��������܂���
void CreateItem(POSITION _pos);
