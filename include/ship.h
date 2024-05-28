#pragma once
#include "bullet.h"
class Ship : public Renderable
{
public:
	Ship(float xPos, float yPos);
	void Move(bool moveUp, double deltaTime);
	void Render() const override;
	void Fire() const;
private:
	float xPos;
	float yPos;
};