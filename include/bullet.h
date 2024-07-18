#pragma once
#include "Renderable.h"
#include "Collidable.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
class Bullet : public Renderable, public Collidable
{
public:
	Bullet(float xPos, float yPos, float velocity, std::vector<Renderable*>& renderables);
	void Update(double deltaTime) override;
	void Update(std::vector<Collidable*>& collidables) override;
	void Render() const override;
	void Collide() const override;
private:
	float velocity;
};