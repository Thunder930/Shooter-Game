#pragma once
#include "bullet.h"
#include "defines.h"
#include "Collidable.h"
#include <vector>
class Ship: public Renderable, public Collidable
{
public:
	virtual void Move(bool moveUp, double deltaTime) = 0;
	virtual void Fire(std::vector<Renderable*> &renderables) = 0;
	void Collide() const override;
protected:
	double bulletCooldown;
	bool isEnemy;
};