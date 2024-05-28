#include "bullet.h"

Bullet::Bullet(float xPos, float yPos, float velocity) {
	this->xPos = xPos;
	this->yPos = yPos;
	this->velocity = velocity;
}

void Bullet::Update(double deltaTime) {
	xPos += velocity * deltaTime;
}

void Bullet::Render() const {
	glBegin(GL_TRIANGLES);

	glVertex2f(xPos - 0.05f, yPos - 0.05f);
	glVertex2f(xPos + 0.05f, yPos - 0.05f);
	glVertex2f(xPos - 0.05f, yPos + 0.05f);

	glVertex2f(xPos + 0.05f, yPos + 0.05f);
	glVertex2f(xPos - 0.05f, yPos + 0.05f);
	glVertex2f(xPos + 0.05f, yPos - 0.05f);

	glEnd();
}