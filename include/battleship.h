#pragma once
#include "ship.h"
#include "bullet.h"
#include "defines.h"
#include <vector>
class Battleship : public Ship
{
public:
	Battleship(float xPos, float yPos, bool isEnemy, std::vector<Renderable*>& renderables);
	void Move(bool moveUp, double deltaTime) override;
	void Render() const override;
	void Update(double deltaTime) override;
	void Update(std::vector<Collidable*>& collidables) override;
	void Fire(std::vector<Collidable*>& collidables) override;
};