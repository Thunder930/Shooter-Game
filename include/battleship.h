#pragma once
#include "ship.h"
#include "bullet.h"
#include "defines.h"
#include <vector>
class Battleship : public Ship
{
public:
	Battleship(float xPos, float yPos, bool isEnemy);
	void Move(bool moveUp, double deltaTime) override;
	void Render() const override;
	void Update(double deltaTime, std::vector<Renderable*>& renderables) override;
	void Fire(std::vector<Renderable*>& renderables) override;
};