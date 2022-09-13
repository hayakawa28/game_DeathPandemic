#pragma once
//座標のための構造体
struct POSITION 
{
	double x;
	double y;
};

struct CIRCLE {//円を作る感じ
	int x, y; // 中心座標
	int r; // 半径
};

// 円と円の当たり判定を行う
// 当たっていればtrueを返す
bool CircleCollision1(CIRCLE c1, CIRCLE c2);
bool CircleCollision2(CIRCLE c3, CIRCLE c4);
