#pragma once 

struct Dimensions {
	float xPos, yPos, width, height;
};

class Collidable
{
public:
	Dimensions GetDimensions() const;
	bool IsColliding(Dimensions hitbox) const;
	virtual void Collide() const = 0;

protected:
	Dimensions dimensions;
	bool CollisionIsOn = true;
};