#pragma once 
#include <vector>

struct Dimensions {
	float xPos = 0.0f;
	float yPos = 0.0f;
	float width = 0.0f;
	float height = 0.0f;
};

class Collidable
{
public:
	Dimensions GetDimensions() const;
	bool IsColliding(Dimensions hitbox) const;
	virtual void Collide() = 0;
	virtual void CollisionUpdate() = 0;

protected:
	Dimensions dimensions;
	bool CollisionIsOn = true;
	std::vector<Collidable*>* collidables = nullptr;
};