#pragma once
class pongGame
{
public:
	static bool gamePlay;

	static void checkGamePlay();

	bool restart_GamePlay();

	void init_PongGame();

	void update_PongGame();

	void exit_PongGame();

	void convert_TimetoText(f64 playTime);

	void print_Time();

public:
	f64 playTime;
	char textPlayTime[10];
};

