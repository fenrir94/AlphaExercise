#pragma once

class AGameState
{
public:
	virtual void init() = 0;
	virtual void update() = 0;
	~AGameState() {};
};

