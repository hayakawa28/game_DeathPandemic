#include <DxLib.h>
#include <time.h>
#include "timelimit.h"
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib") 
#include "app.h"

namespace {
	DWORD l; // 制限時間(秒)
	DWORD t; // 経過時間(秒)
	DWORD s;
	int Color;
};

void TimeInit()
{
	l = 180; // 制限時間(秒)
	t = 0; // 経過時間(秒)
	s = timeGetTime();
	Color = GetColor(255, 0, 0);
}

void TimeDraw()
{
	DrawFormatString(37, 35, Color, "%d\n", l - t); // 残り時間(秒)
}

void TimeUpdate()
{
	if (l - t > 0)
	{
		t = (timeGetTime() - s) / 1000;
	}

	if (l - t == 0)
	{
		ChangeScene(PLAY3_SCENE);
	}
}