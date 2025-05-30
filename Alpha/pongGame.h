#pragma once
#include "AGameState.h"
#include "pongManager.h"

class pongGame : public AGameState
{
public:
	pongGame();
	~pongGame();

	void initialize() override;
	void update() override;
	void print() override;
	void exit() override;

	void convert_TimetoText(f64 playTime);

	void print_Time();

	f64 playTime;

	f32 widthTextTime, heightTextTime;
	char textPlayTime[10];

};