#pragma once
#include "bullet.h"
#include "defines.h"
#include <vector>
class Ship : public Renderable
{
public:
	Ship(float xPos, float yPos);
	void Move(bool moveUp, double deltaTime);
	void Render() const override;
	void Update(double deltaTime, std::vector<Renderable*>& renderables) override;
	void Fire(std::vector<Renderable*> &renderables);
private:
	float xPos;
	float yPos;
	double timeSinceLastBullet;
};