#pragma once
#include "bullet.h"
#include "defines.h"
#include "Collidable.h"
#include <vector>
class Ship: public Renderable, public Collidable
{
public:
	~Ship();
	virtual void Move(bool moveUp, double deltaTime) = 0;
	virtual void Fire() = 0;
	void Collide() override;
protected:
	double bulletCooldown = DEFAULT_MIN_TIME_BETWEEN_SHOTS;
	bool isEnemy = false;
	int health = 1;
};