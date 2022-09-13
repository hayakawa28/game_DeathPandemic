#pragma once
#include "common.h"

void ItemInit();
void ItemUpdate();
void ItemDraw();
void ItemRelease();

// 石を生成します。
// _posの位置に位置を生成して、右に飛んでいきます
// 配列がいっぱいなら、生成されません
void CreateItem(POSITION _pos);
