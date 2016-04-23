#pragma once

#include "..\Robot\Robot.h"

class Player : public Robot
{
public:
	Player();
	virtual ~Player();

	virtual void Update(float _deltaTime);
};