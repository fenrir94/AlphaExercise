#include <iostream>
#include "AEEngine.h"
#include "pongGame.h"

bool pongGame::gamePlay = false;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	int gGameRunning = 1;

	// Initialization of your own variables go here

	// Using custom window procedure
	AESysInit(hInstance, nCmdShow, 1600, 900, 1, 60, false, NULL);

	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);

	// Load the font here 
	s8 pFont = AEGfxCreateFont("Assets/liberation-mono.ttf", 72.f);

	// Text to print
	const char* pText = "Press [Space] to Play";

	f32 w, h;
	AEGfxGetPrintSize(pFont, pText, 1.f, &w, &h);

	// Changing the window title
	AESysSetWindowTitle("PongGame");

	// reset the system modules
	AESysReset();

	// Game Loop
	while (gGameRunning)
	{
		// Informing the system about the loop's start
		AESysFrameStart();

		// Basic way to trigger exiting the application
		// when ESCAPE is hit or when the window is closed
		if (AEInputCheckTriggered(AEVK_ESCAPE) || 0 == AESysDoesWindowExist())
			gGameRunning = 0;

		// Your own update logic goes here
		AEGfxPrint(pFont, pText, -w / 2, -h / 2, 1, 1, 1, 1, 1);






		// Your own rendering logic goes here


		// Informing the system about the loop's end
		AESysFrameEnd();

	}


	// free the system
	AESysExit();
}