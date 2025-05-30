#include <iostream>
#include "AEEngine.h"
#include "pongGame.h"
#include "mainMenu.h"
#include "pongManager.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	pongManager pongManager;
	pongManager.init_PongManager(hInstance, nCmdShow);
	
	pongManager::changeGameState_PongManager(&mainMenuState);
	pongManager.update_PongManager();

	// free the system
	AESysExit();
}