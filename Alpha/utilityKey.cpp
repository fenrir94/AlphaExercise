#include "AEEngine.h"
#include "utilityKey.h"

bool isStart_PongGame()
{
	return AEInputCheckTriggered(AEVK_SPACE);
}

bool isRestart_PongGame()
{
    return AEInputCheckTriggered(AEVK_R);
}
