#pragma once
#include "Renderable.h"
#include "Collidable.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
class Bullet : public Renderable, public Collidable
{
public:
	Bullet(float xPos, float yPos, float velocity);
	void Update(double deltaTime, std::vector<Renderable*>& renderables) override;
	void Render() const override;
	void Collide() const override;
private:
	float velocity;
};