#include "bullet.h"
#include "defines.h"

Bullet::Bullet(float xPos, float yPos, float velocity) {
	this->dimensions.xPos = xPos;
	this->dimensions.yPos = yPos;
	this->dimensions.width = BULLET_HALF_WIDTH;
	this->dimensions.height = BULLET_HALF_HEIGHT;
	this->CollisionIsOn = true;
	this->velocity = velocity;
}

void Bullet::Update(double deltaTime, std::vector<Renderable*>& renderables) {
	dimensions.xPos += velocity * deltaTime;
	if (dimensions.xPos > 1.0f) {
		auto thisBullet = std::find(renderables.begin(), renderables.end(), this);
		renderables.erase(thisBullet);
		renderables.shrink_to_fit();
	}
}

void Bullet::Update(std::vector<Collidable*>& collidables) {
	if (dimensions.xPos > 1.0f) {
		auto thisBullet = std::find(collidables.begin(), collidables.end(), this);
		collidables.erase(thisBullet);
		collidables.shrink_to_fit();
	}
}

void Bullet::Render() const {
	glBegin(GL_TRIANGLES);

	glVertex2f(dimensions.xPos - dimensions.height, dimensions.yPos - dimensions.width);
	glVertex2f(dimensions.xPos + dimensions.height, dimensions.yPos - dimensions.width);
	glVertex2f(dimensions.xPos - dimensions.height, dimensions.yPos + dimensions.width);

	glVertex2f(dimensions.xPos + dimensions.height, dimensions.yPos + dimensions.width);
	glVertex2f(dimensions.xPos - dimensions.height, dimensions.yPos + dimensions.width);
	glVertex2f(dimensions.xPos + dimensions.height, dimensions.yPos - dimensions.width);

	glEnd();
}

void Bullet::Collide() const {
	printf("Bullet Hit");
}