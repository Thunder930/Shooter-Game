#include "ship.h"

Ship::Ship(float xPos, float yPos) {
	this->xPos = xPos;
	this->yPos = yPos;
	this->timeSinceLastBullet = 0;
}

void Ship::Move(bool moveUp, double deltaTime) {
	moveUp ? yPos += deltaTime : yPos -= deltaTime;
}

void Ship::Update(double deltaTime, std::vector<Renderable*>& renderables) {
	timeSinceLastBullet += deltaTime;
}

void Ship::Render() const {
	glBegin(GL_TRIANGLES);

	glVertex2f(xPos - 0.1f, yPos + 0.2f);
	glVertex2f(xPos - 0.1f, yPos - 0.2f);
	glVertex2f(xPos + 0.1f, yPos);

	glEnd();
}

void Ship::Fire(std::vector<Renderable*> &renderables) {
	if (timeSinceLastBullet > 0.5) {
		renderables.push_back(new Bullet(xPos, yPos, 5));
		timeSinceLastBullet = 0;
	}
}