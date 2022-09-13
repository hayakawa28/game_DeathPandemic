#include "common.h"

bool CircleCollision1(CIRCLE c1, CIRCLE c2)//当たり判定（円）
{
	int dx1 = c1.x - c2.x;
	int dy1= c1.y - c2.y;
	int rs1 = c1.r + c2.r;
	if (dx1 * dx1 + dy1* dy1 <= rs1 * rs1)//当たればtrue違うときはfalse
	{
		return true;
	}
	return false;
}

bool CircleCollision2(CIRCLE c3, CIRCLE c4)//当たり判定（円）
{
	int dx2 = c3.x - c4.x;
	int dy2 = c3.y - c4.y;
	int rs2 = c3.r + c4.r;
	if (dx2 * dx2 + dy2 * dy2 <= rs2 * rs2)//当たればtrue違うときはfalse
	{
		return true;
	}
	return false;
}

