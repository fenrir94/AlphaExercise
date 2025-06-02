#pragma once
#include "AGameState.h"
#include "mainMenu.h"
#pragma once
#include "pongGame.h"

class pongManager
{
public:
	pongManager();
	~pongManager();

	void init_PongManager(HINSTANCE hInstance, int nCmdShow);
	void update_PongManager();

private:
	s32 widthWindow;
	s32 heightWindow;

	const char* textTitle;

public:
	bool isGameRunning;
	static AGameState* gameState;
	static s8 pFont;

	static void changeGameState_PongManager(AGameState* newGameState);
};
