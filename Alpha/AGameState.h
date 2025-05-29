#pragma once

class AGameState
{
public:
	virtual void initialize() = 0;
	virtual void update() = 0;
	virtual void print() = 0;
	virtual void exit() = 0;
	virtual ~AGameState() {};
};

