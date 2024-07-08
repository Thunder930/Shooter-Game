#pragma once
#include "ship.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>

void InitGraphics(GLFWwindow*& window);
void Load();
void Render(double deltaTime);
void Update(GLFWwindow*& window, double deltaTime);
void UnLoad();
void ProcessInput(GLFWwindow* window, double deltaTime);

std::vector<Renderable*> renderables;