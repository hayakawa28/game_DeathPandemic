#include <DxLib.h>
#include <time.h>
#include "timelimit.h"
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib") 
#include "app.h"

namespace {
	DWORD l; // ��������(�b)
	DWORD t; // �o�ߎ���(�b)
	DWORD s;
	int Color;
};

void TimeInit()
{
	l = 180; // ��������(�b)
	t = 0; // �o�ߎ���(�b)
	s = timeGetTime();
	Color = GetColor(255, 0, 0);
}

void TimeDraw()
{
	DrawFormatString(37, 35, Color, "%d\n", l - t); // �c�莞��(�b)
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