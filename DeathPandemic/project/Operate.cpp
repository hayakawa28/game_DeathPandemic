#include "Operate.h"
#include <DxLib.h>
#include "app.h"

namespace {
	int titleback;
	int modoru;
};


void OperateInit()
{
	titleback = LoadGraph("data\\texture\\teamseisakutitle2.png");
	modoru = LoadSoundMem("data\\sound\\modoru.wav");
}

void OperateUpdate()
{
	if (CheckHitKey(KEY_INPUT_T)||CheckHitKey(KEY_INPUT_BACK))
	{
			ChangeScene(TITLE_SCENE);
			PlaySoundMem(modoru, DX_PLAYTYPE_BACK);
	}
}

void OperateDraw()
{
	DrawGraph(0, 0, titleback, TRUE);
}

void OperateRelease()
{

}