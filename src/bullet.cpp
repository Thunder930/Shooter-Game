#include "bullet.h"
#include "defines.h"

Bullet::Bullet(float xPos, float yPos, float velocity) {
	this->xPos = xPos;
	this->yPos = yPos;
	this->velocity = velocity;
}

void Bullet::Update(double deltaTime, std::vector<Renderable*>& renderables) {
	xPos += velocity * deltaTime;
	if (xPos > 1.0f) {
		auto thisBullet = std::find(renderables.begin(), renderables.end(), this);
		renderables.erase(thisBullet);
		renderables.shrink_to_fit();
	}
}

void Bullet::Render() const {
	glBegin(GL_TRIANGLES);

	glVertex2f(xPos - BULLET_HALF_HEIGHT, yPos - BULLET_HALF_WIDTH);
	glVertex2f(xPos + BULLET_HALF_HEIGHT, yPos - BULLET_HALF_WIDTH);
	glVertex2f(xPos - BULLET_HALF_HEIGHT, yPos + BULLET_HALF_WIDTH);

	glVertex2f(xPos + BULLET_HALF_HEIGHT, yPos + BULLET_HALF_WIDTH);
	glVertex2f(xPos - BULLET_HALF_HEIGHT, yPos + BULLET_HALF_WIDTH);
	glVertex2f(xPos + BULLET_HALF_HEIGHT, yPos - BULLET_HALF_WIDTH);

	glEnd();
}