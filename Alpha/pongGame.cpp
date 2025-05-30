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

	AESysFrameStart();
	f64 dt = AEFrameRateControllerGetFrameTime();
	this->playTime += dt;
	//std::cout << playTime << std::endl;
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);



	/*if (AEInputCheckTriggered(AEVK_ESCAPE))
	{
		pongGame::gamePlay = false;
		break;
	}

	if (pongGame::restart_GamePlay()) {
		break;
	}*/


	pongGame::convert_TimetoText(playTime);
	pongGame::print_Time();


	AESysFrameEnd();
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

void pongGame::print_Time()
{
	AEGfxGetPrintSize(pongManager::pFont, textPlayTime, 1.f, &this->widthTextTime, &this->heightTextTime);
	AEGfxPrint(pongManager::pFont, textPlayTime, -(this->widthTextTime) / 2, 1.f - (this->heightTextTime), 1, 1, 1, 1, 1);
}
