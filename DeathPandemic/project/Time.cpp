/*#include <DxLib.h>
#include "Time.h"

namespace {
	int timei;
	int timet;
	int times;
};

void TimeInit()
{
	timei = 20;
	timet = 0;
	times = timeGetTime();
}

void timeDraw()
{
	printfDx("%d\n", timei - timet);
}

void tiemUpdate()
{
	while (timei > timet) {
		timet = (timeGetTime() - times) / 1000;
	}*/
