#include <iostream>
#include "mainMenu.h"
#include "pongGame.h"
#include "pongManager.h"
#include "utilityKey.h"

mainMenu mainMenuState;

mainMenu::mainMenu()
{
	this->textPress = "Press [Space] to Play";
}

mainMenu::~mainMenu()
{
}

void mainMenu::initialize()
{
	//std::cout << "main Menu initialize" << std::endl;
	AEGfxGetPrintSize(pongManager::pFont,this->textPress,1.f,&(this->widthText),&(this->heightText));
}

void mainMenu::update()
{
	if (isStart_PongGame()) {
		pongManager::changeGameState_PongManager(&pongGameState);
		exit();
	}
}

void mainMenu::print()
{
	AEGfxSetBackgroundColor(0.f, 0.f, 0.f);
	
	AEGfxPrint(pongManager::pFont, this->textPress, -(this->widthText) / 2.f, -(this->heightText) / 2.f, 1, 1, 1, 1, 1);
}

void mainMenu::exit()
{

}

