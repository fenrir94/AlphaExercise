#include <iostream>
#include "pongManager.h"
#include "AGameState.h"
#include "mainMenu.h"


AGameState* pongManager::gameState;
s8 pongManager::pFont;

pongManager::pongManager()
{
	this->isGameRunning = TRUE;
	this->widthWindow = 1600;
	this->heightWindow = 900;

	this->textTitle = "PongGame";
}

pongManager::~pongManager()
{
	AEGfxDestroyFont(this->pFont);
}

void pongManager::init_PongManager(HINSTANCE hInstance, int nCmdShow)
{
	AESysInit(hInstance,
		nCmdShow,
		this->widthWindow,
		this->heightWindow,
		1,
		60,
		false,
		NULL);

	AESysSetWindowTitle(this->textTitle);

	pongManager::pFont = AEGfxCreateFont("Assets/liberation-mono.ttf", 72.f);


	AESysReset();
}

void pongManager::changeGameState_PongManager(AGameState* newGameState)
{
	pongManager::gameState = newGameState;
	pongManager::gameState->initialize();
}

void pongManager::update_PongManager()
{
	
	while (isGameRunning) {
		AESysFrameStart();
		pongManager::gameState->update();
		pongManager::gameState->print();
		
		if (AEInputCheckTriggered(AEVK_ESCAPE)|| 0 == AESysDoesWindowExist()) {
			isGameRunning = FALSE;
			break;
		}
		AESysFrameEnd();
	}
	return;
}
