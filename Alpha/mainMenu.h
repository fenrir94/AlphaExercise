#pragma once
#include "AEEngine.h"
#include "AGameState.h"


class mainMenu : public AGameState
{
public:
	mainMenu();
	~mainMenu();
	
	void initialize() override;
	void update() override;
	void print() override;
	void exit() override;

	bool isStart_PongGame();

private:
	f32 widthText, heightText;
	const char* textPress;

};

extern mainMenu mainMenuState;