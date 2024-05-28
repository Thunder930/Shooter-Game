#include "ship.h"

Ship::Ship(float xPos, float yPos) {
	this->xPos = xPos;
	this->yPos = yPos;
}

void Ship::Move(bool moveUp, double deltaTime) {
	moveUp ? yPos += deltaTime : yPos -= deltaTime;
}

void Ship::Render() const {
	glBegin(GL_TRIANGLES);

	glVertex2f(xPos - 0.1f, yPos + 0.2f);
	glVertex2f(xPos - 0.1f, yPos - 0.2f);
	glVertex2f(xPos + 0.1f, yPos);

	glEnd();
}

void Ship::Fire() const {

}