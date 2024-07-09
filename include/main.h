#pragma once
#include "player.h"
#include "enemy.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>

void InitGraphics(GLFWwindow*& window);
void Load();
void Render(double deltaTime);
void Update(GLFWwindow*& window, double deltaTime);
void UnLoad();
void ProcessInput(GLFWwindow* window, double deltaTime);
void resizeCallback(GLFWwindow* window, int width, int height);

std::vector<Renderable*> renderables;