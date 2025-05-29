#include "pongManager.h"
#include "AGameState.h"
#include "mainMenu.h"


AGameState* pongManager::gameState;
s8 pongManager::pFont;

pongManager::pongManager()
{
	this->widthWindow = 1600;
	this->heightWindow = 900;

	this->textTitle = "PongGame";
}

pongManager::~pongManager()
{

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

	pongManager::pFont = AEGfxCreateFont("Assets/liberation-mono.ttf", 72.f);

	AESysSetWindowTitle(this->textTitle);

	AESysReset();

}

void pongManager::changeGameState_PongManager(AGameState* newGameState)
{
	pongManager::gameState = newGameState;
	pongManager::gameState->initialize();
}

void pongManager::update_PongManager()
{
	
	while (1) {
		pongManager::gameState->update();
		pongManager::gameState->print();
	}
	if () {
		return;
	}
}
