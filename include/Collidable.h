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
	virtual void Collide() const = 0;
	virtual void Update(std::vector<Collidable*>& collidables) = 0;

protected:
	Dimensions dimensions;
	bool CollisionIsOn = true;
};