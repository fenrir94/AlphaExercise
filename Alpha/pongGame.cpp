#include <iostream>
#include <string>
#include "AEEngine.h"
#include "pongGame.h"

void pongGame::checkGamePlay()
{
    if (AEInputCheckTriggered(AEVK_SPACE)) {
        pongGame::gamePlay = true;
    }
}

bool pongGame::restartGamePlay()
{
    if (AEInputCheckTriggered(AEVK_R)) {
        return true;
    }
    else {
        return false;
    }
}

void pongGame::init_PongGame()
{
    this->playTime = 0.0f;
    std::cout << "Player1: "<< 0 << std::endl;
    std::cout << "Player2: "<< 0 << std::endl;
    std::cout << "Pong Game Start" << std::endl;
}

void pongGame::update_PongGame()
{
    while (pongGame::gamePlay) {
        AESysFrameStart();
        f64 dt = AEFrameRateControllerGetFrameTime();
        this->playTime += dt;
        //std::cout << playTime << std::endl;
        AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);



        if (AEInputCheckTriggered(AEVK_ESCAPE))
        {
            pongGame::gamePlay = false;
            break;
        }

        if (pongGame::restartGamePlay()) {
            break;
        }


        pongGame::convertTimetoText(playTime);
        pongGame::printTime();


        AESysFrameEnd();
    }
    pongGame::exit_PongGame();
}

void pongGame::exit_PongGame()
{

}

void pongGame::convertTimetoText(f64 playTime)
{
    std::cout << this->playTime << std::endl;
    int currentTime = static_cast<int>(this->playTime);
    std::cout << currentTime << std::endl;
    int minutes = (currentTime % 3600) / 60;
    int seconds = currentTime % 60;

    std::cout << minutes << ":" << seconds << std::endl;

    // Text to print
    if (this->textPlayTime != nullptr) {
        snprintf(textPlayTime, 10, "%02d:%02d", minutes, seconds);
    }
}

void pongGame::printTime()
{
    AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);
    s8 pFont = AEGfxCreateFont("Assets/liberation-mono.ttf", 72.f);

    f32 w, h;
    AEGfxGetPrintSize(pFont, textPlayTime, 1.f, &w, &h);
    AEGfxPrint(pFont, textPlayTime, -w/2, 1.f - h, 1, 1, 1, 1, 1);
}
