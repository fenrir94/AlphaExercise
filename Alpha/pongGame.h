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

public:
	double playTime;
};

