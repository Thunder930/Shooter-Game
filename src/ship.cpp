#include "ship.h"

Ship::Ship(float xPos, float yPos) {
	this->xPos = xPos;
	this->yPos = yPos;
	this->bulletCooldown = 0.0;
}

void Ship::Move(bool moveUp, double deltaTime) {
	moveUp ? yPos += deltaTime : yPos -= deltaTime;
}

void Ship::Update(double deltaTime, std::vector<Renderable*>& renderables) {
	if (bulletCooldown > 0.0) {
		bulletCooldown < deltaTime ? bulletCooldown = 0.0 : bulletCooldown -= deltaTime;
	}
}

void Ship::Render() const {
	glBegin(GL_TRIANGLES);

	glVertex2f(xPos - SHIP_HALF_HEIGHT, yPos + SHIP_HALF_WIDTH);
	glVertex2f(xPos - SHIP_HALF_HEIGHT, yPos - SHIP_HALF_WIDTH);
	glVertex2f(xPos + SHIP_HALF_HEIGHT, yPos);

	glEnd();
}

void Ship::Fire(std::vector<Renderable*> &renderables) {
	if (bulletCooldown <= 0.0) {
		renderables.push_back(new Bullet(xPos, yPos, BULLET_VELOCITY));
		bulletCooldown = MIN_TIME_BETWEEN_SHOTS;
	}
}