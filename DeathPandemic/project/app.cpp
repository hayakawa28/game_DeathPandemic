#include "app.h"
#include "Back.h"
#include "titleScene.h"
#include "playScene.h"
#include "Operate.h"
#include"Clear.h"
#include"Gameover.h"

namespace {
	SCENE_ID currentScene;
	SCENE_ID nextScene;
	int title_bgm;
};
bool isGameEnd = false;
void AppInit()
{
	currentScene = TITLE_SCENE;//�Q�[���̓^�C�g������X�^�[�g���Ă���
	nextScene = currentScene;//���̂��߂�͂����Ƃ邾��
	switch (currentScene) {
	case TITLE_SCENE:
		TitleSceneInit();
		break;
	case PLAY_SCENE:
		PlaySceneInit();
		break;
	case OPERATE_SCENE:
		OperateInit();
		break;
	}
	//title_bgm = LoadSoundMem("data\\sound\\sousa.wav");
}

void AppUpdate()
{
	if (nextScene != currentScene) {//���V�[�����������
		switch (currentScene) {
		case TITLE_SCENE://���g���Ă���f�[�^����
			TitleSceneRelease();
			break;
		case PLAY_SCENE:
			PlaySceneRelease();
			break;
		case OPERATE_SCENE:
			OperateRelease();
			break;
		}
		currentScene = nextScene;
		switch (currentScene) {
		case TITLE_SCENE://���̓ǂݍ���
			TitleSceneInit();
			break;
		case PLAY_SCENE:
			PlaySceneInit();
			break;
		case OPERATE_SCENE:
			OperateInit();
			break;
		case PLAY2_SCENE:
			ClearInit();
			break;
		case PLAY3_SCENE:
			GameoverInit();
			break;
		}
	}
	switch (currentScene) {
	case TITLE_SCENE:
		TitleSceneUpdate();//���̃A�b�v�f�[�g
		break;
	case PLAY_SCENE:
		PlaySceneUpdate();
		break;
	case OPERATE_SCENE:
		OperateUpdate();
		break;
	case PLAY2_SCENE:
		ClearUpdate();
		break;
	case PLAY3_SCENE:
		GameoverUpdate();
		break;
	}
}

void AppDraw()
{
	switch (currentScene) {
	case TITLE_SCENE:
		TitleSceneDraw();//���̕`��
		break;
	case PLAY_SCENE:
		PlaySceneDraw();
		break;
	case OPERATE_SCENE:
		OperateDraw();
		break;
	case PLAY2_SCENE:
		ClearDraw();
		break;
	case PLAY3_SCENE:
		GameoverDraw();
		break;
	}
}

void AppRelease()
{
	switch (currentScene) {
	case TITLE_SCENE:
		TitleSceneRelease();
		break;
	case PLAY_SCENE:
		PlaySceneRelease();
		break;
	case OPERATE_SCENE:
		OperateRelease();
		break;
	}
}

void ChangeScene(SCENE_ID scene)
{
	//PlaySoundMem(title_bgm, DX_PLAYTYPE_BACK);
	nextScene = scene;
}
