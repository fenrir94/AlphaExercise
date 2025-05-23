#include <iostream>
#include "AEEngine.h"
#include "pongGame.h"

void pongGame::checkGamePlay()
{
    if (AEInputCheckTriggered(AEVK_SPACE)) {
        pongGame::gamePlay = true;
    }
}

void pongGame::init_PongGame()
{
    std::cout << "Player1: "<< 0 << std::endl;
    std::cout << "Player2: "<< 0 << std::endl;
    std::cout << "Pong Game Start" << std::endl;
}

void pongGame::update_PongGame()
{
    while (pongGame::gamePlay) {
        AESysFrameStart();
        std::cout << "Pong Game Running" << std::endl;
        AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);

        if (AEInputCheckTriggered(AEVK_ESCAPE))
        {
            pongGame::gamePlay = false;
            break;
        }

        AESysFrameEnd();
    }
    if (!pongGame::gamePlay) {
        pongGame::exit_PongGame();
    }
    
}

void pongGame::exit_PongGame()
{

}
