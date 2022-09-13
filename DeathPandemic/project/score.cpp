#include "score.h"
#include <DxLib.h>
#include "app.h"


namespace {
	int score;
};

void ScoreInit()
{
	score = 0;
}

void ScoreDraw()
{
	DrawFormatString(650, 10, GetColor(0,0,0), "SCORE: %7d", score);
	if (score == 100000)
	{
		ChangeScene(PLAY2_SCENE);
	}

}

void ScoreAdd(int val)
{
	score += val;
}

