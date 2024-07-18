#pragma once
#include "ship.h"
#include "bullet.h"
#include "defines.h"
#include <vector>
class Battleship : public Ship
{
public:
	Battleship(float xPos, float yPos, bool isEnemy, std::vector<Renderable*>& renderables, std::vector<Collidable*>& collidables);
	void Move(bool moveUp, double deltaTime) override;
	void Render() const override;
	void RenderUpdate(double deltaTime) override;
	void CollisionUpdate() override;
	void Fire() override;
};