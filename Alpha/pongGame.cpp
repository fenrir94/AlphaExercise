#include <iostream>
#include <string>
#include "AEEngine.h"
#include "pongGame.h"

pongGame pongGameState;

pongGame::pongGame()
{
	this->playTime = 0.0f;

	this->widthTextTime = 0.0f;
	this->heightTextTime = 0.0f;

	textPlayTime[0] = '0';
}

pongGame::~pongGame()
{
}

void pongGame::initialize()
{
	this->playTime = 0.0f;

	this->widthTextTime = 0.0f;
	this->heightTextTime = 0.0f;
	
}

void pongGame::update()
{
	f64 dt = AEFrameRateControllerGetFrameTime();
	this->playTime += dt;

	pongGame::convert_TimetoText(playTime);

	/*if (AEInputCheckTriggered(AEVK_ESCAPE))
	{
		pongGame::gamePlay = false;
		break;
	}

	if (pongGame::restart_GamePlay()) {
		break;
	}*/
	
}

void pongGame::print()
{
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);

	this->print_Time();
}

void pongGame::exit()
{
}

void pongGame::convert_TimetoText(f64 playTime)
{
	int currentTime = static_cast<int>(this->playTime);
	int minutes = (currentTime % 3600) / 60;
	int seconds = currentTime % 60;

	// Text to print
	if (this->textPlayTime != nullptr) {
		snprintf(textPlayTime, 10, "%02d:%02d", minutes, seconds);
	}

	AEGfxGetPrintSize(pongManager::pFont, textPlayTime, 1.f, &this->widthTextTime, &this->heightTextTime);
}

void pongGame::print_Time()
{
	AEGfxPrint(pongManager::pFont, textPlayTime, -(this->widthTextTime) / 2.f, 1.f - (this->heightTextTime), 1, 1, 1, 1, 1);
}
