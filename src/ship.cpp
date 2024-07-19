#include "ship.h"

Ship::~Ship() {
	auto thisRenderable = std::find(renderables->begin(), renderables->end(), this);
	renderables->erase(thisRenderable);
	renderables->shrink_to_fit();
	auto thisCollidable = std::find(collidables->begin(), collidables->end(), this);
	collidables->erase(thisCollidable);
	collidables->shrink_to_fit();
}

void Ship::Collide() {
	health--;
	if (health <= 0) {
		delete(this);
	}
}