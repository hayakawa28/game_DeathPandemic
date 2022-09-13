#include <DxLib.h>
#include "app.h"
#include "config.h"
#include "timelimit.h"

#define CoGVersion (2.0)

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);
	SetOutApplicationLogValidFlag(FALSE); // ログを出さない
	SetDrawScreen(DX_SCREEN_BACK);

	SetMainWindowText(WINDOW_NAME);
	SetWindowSizeExtendRate(WINDOW_EXTEND);
	ChangeWindowMode(WINDOW_MODE); // Windowモードの場合

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	SetAlwaysRunFlag(TRUE);
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
	AppInit();//初期化
	

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
		//	printfDx("押したぜ");
		//}

		while (!isGameEnd)
		{
			AppUpdate();//更新処理
			ClearDrawScreen();
			AppDraw();//描画処理
			if (ProcessMessage() == -1 || CheckHitKey(KEY_INPUT_ESCAPE) != 0)
				break;
			ScreenFlip();
		}
	

	AppRelease();//いらないデータをメモリから除去
	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
} 