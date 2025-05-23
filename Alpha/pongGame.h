#pragma once
class pongGame
{
public:
	static bool gamePlay;

	static void checkGamePlay();

	bool restartGamePlay();

	void init_PongGame();

	void update_PongGame();

	void exit_PongGame();

	void convertTimetoText(f64 playTime);

	void printTime();

public:
	f64 playTime;
	char textPlayTime[10];
};

