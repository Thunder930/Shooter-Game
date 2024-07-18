#include "battleship.h"

Battleship::Battleship(float xPos, float yPos, bool isEnemy, std::vector<Renderable*>& renderables) {
	this->dimensions.xPos = xPos;
	this->dimensions.yPos = yPos;
	this->dimensions.width = BATTLESHIP_HALF_WIDTH;
	this->dimensions.height = BATTLESHIP_HALF_HEIGHT;
	this->bulletCooldown = 0.0;
	this->CollisionIsOn = true;
	this->isEnemy = isEnemy;
	this->renderables = &renderables;
}

void Battleship::Move(bool moveUp, double deltaTime) {
	if (moveUp) {
		dimensions.yPos + dimensions.width + deltaTime > 1.0 ? dimensions.yPos = 1.0 - dimensions.width : dimensions.yPos += deltaTime;
	}
	else {
		dimensions.yPos - dimensions.width - deltaTime < -1.0 ? dimensions.yPos = -1.0 + dimensions.width : dimensions.yPos -= deltaTime;
	}
}

void Battleship::Update(double deltaTime) {
	if (bulletCooldown > 0.0) {
		bulletCooldown > deltaTime ? bulletCooldown -= deltaTime : bulletCooldown = 0.0;
	}
}

void Battleship::Update(std::vector<Collidable*>& collidables) {

}

void Battleship::Render() const {
	glBegin(GL_TRIANGLES);
	if (isEnemy) {
		glVertex2f(dimensions.xPos + dimensions.height, dimensions.yPos + dimensions.width);
		glVertex2f(dimensions.xPos + dimensions.height, dimensions.yPos - dimensions.width);
		glVertex2f(dimensions.xPos - dimensions.height, dimensions.yPos);
	}
	else {
		glVertex2f(dimensions.xPos - dimensions.height, dimensions.yPos + dimensions.width);
		glVertex2f(dimensions.xPos - dimensions.height, dimensions.yPos - dimensions.width);
		glVertex2f(dimensions.xPos + dimensions.height, dimensions.yPos);
	}

	glEnd();
}

void Battleship::Fire(std::vector<Collidable*>& collidables) {
	if (bulletCooldown <= 0.0) {
		if (isEnemy) {
			Bullet* bullet = new Bullet(dimensions.xPos, dimensions.yPos, -BULLET_VELOCITY, *renderables);
			renderables->push_back(bullet);
			collidables.push_back(bullet);
		}
		else {
			Bullet* bullet = new Bullet(dimensions.xPos, dimensions.yPos, BULLET_VELOCITY, *renderables);
			renderables->push_back(bullet);
			collidables.push_back(bullet);
		}
		bulletCooldown = MIN_TIME_BETWEEN_SHOTS;
	}
}