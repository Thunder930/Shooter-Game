#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Renderable.h"
#include <vector>
#include "battleship.h"

void InitGraphics(GLFWwindow*& window);
void Load();
void Render(double deltaTime);
void Collide();
void Update(GLFWwindow*& window, double deltaTime);
void UnLoad();
void ProcessInput(GLFWwindow* window, double deltaTime);
void resizeCallback(GLFWwindow* window, int width, int height);

std::vector<Renderable*> renderables;
std::vector<Collidable*> collidables;