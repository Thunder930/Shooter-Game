#pragma once
#include "Renderable.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
class Bullet : public Renderable
{
public:
	Bullet(float xPos, float yPos, float velocity);
	void Update(double deltaTime);
	void Render() const override;
private:
	float velocity;
	float xPos;
	float yPos;
};