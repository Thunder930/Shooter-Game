#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

void InitGraphics(GLFWwindow*& window);
void Load();
void Render();
void Update(GLFWwindow*& window, double deltaTime);
void UnLoad();
void ProcessInput(GLFWwindow* window);