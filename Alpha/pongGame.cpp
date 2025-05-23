#include "AEEngine.h"
#include "pongGame.h"

void pongGame::checkGamePlay()
{
    if (AEInputCheckTriggered(AEVK_SPACE)) {
        gamePlay = true;
    }
}
