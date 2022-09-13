#pragma once
#include "common.h"

void BossInit();
void BossUpdate();
void BossDraw();
void BossRelease();

// “G‚ÆÎ‚Ì“–‚½‚è”»’è‚ğ‚·‚é
// “G‚Ì‰~‚ğó‚¯æ‚èA“–‚½‚Á‚Ä‚¢‚ê‚Î“G‚ğ€–S‚³‚¹‚é
// “–‚½‚Á‚Ä‚¢‚ê‚Îtrue‚ğ•Ô‚·
bool BossCollideStone2(CIRCLE stone2);