#include <DxLib.h>
#include <time.h>
#include "timelimit.h"
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib") 
#include "app.h"

namespace {
	DWORD l; // §ŒÀŽžŠÔ(•b)
	DWORD t; // Œo‰ßŽžŠÔ(•b)
	DWORD s;
	int Color;
};

void TimeInit()
{
	l = 180; // §ŒÀŽžŠÔ(•b)
	t = 0; // Œo‰ßŽžŠÔ(•b)
	s = timeGetTime();
	Color = GetColor(255, 0, 0);
}

void TimeDraw()
{
	DrawFormatString(37, 35, Color, "%d\n", l - t); // Žc‚èŽžŠÔ(•b)
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