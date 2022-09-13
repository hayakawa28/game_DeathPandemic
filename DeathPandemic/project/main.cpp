#include <DxLib.h>
#include "app.h"
#include "config.h"
#include "timelimit.h"

#define CoGVersion (2.0)

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);
	SetOutApplicationLogValidFlag(FALSE); // ���O���o���Ȃ�
	SetDrawScreen(DX_SCREEN_BACK);

	SetMainWindowText(WINDOW_NAME);
	SetWindowSizeExtendRate(WINDOW_EXTEND);
	ChangeWindowMode(WINDOW_MODE); // Window���[�h�̏ꍇ

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	SetAlwaysRunFlag(TRUE);
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
	AppInit();//������
	

	bool beforePress = false;
	bool nowPress = false;


		clsDx();

		//beforePress = nowPress;
		//nowPress = false;

		//if (GetMouseInput() & MOUSE_INPUT_1) {
		//	nowPress = true;
		//}
		//else {
		//	nowPress = false;
		//}
		//if (nowPress == true && beforePress == false) {
		//	printfDx("��������");
		//}

		while (!isGameEnd)
		{
			AppUpdate();//�X�V����
			ClearDrawScreen();
			AppDraw();//�`�揈��
			if (ProcessMessage() == -1 || CheckHitKey(KEY_INPUT_ESCAPE) != 0)
				break;
			ScreenFlip();
		}
	

	AppRelease();//����Ȃ��f�[�^�����������珜��
	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
} 