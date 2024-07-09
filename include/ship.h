#pragma once
#include "bullet.h"
#include "defines.h"
#include <vector>
class Ship
{
public:
	virtual void Move(bool moveUp, double deltaTime) = 0;
	virtual void Fire(std::vector<Renderable*> &renderables) = 0;
protected:
	float xPos;
	float yPos;
	double bulletCooldown;
};