#include "Collidable.h"

Dimensions Collidable::GetDimensions() const {
	return dimensions;
}

bool Collidable::IsColliding(Dimensions hitbox) const {
	if (!CollisionIsOn) {
		return false;
	}
	if (dimensions.yPos + dimensions.height > hitbox.yPos - hitbox.height &&
		dimensions.yPos - dimensions.height < hitbox.yPos + hitbox.height &&
		dimensions.xPos + dimensions.width > hitbox.xPos - hitbox.width &&
		dimensions.xPos - dimensions.width < hitbox.xPos + hitbox.width) {
		return true;
	}
	return false;
}