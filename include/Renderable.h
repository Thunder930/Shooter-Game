#pragma once
#include <vector>
class Renderable
{
public:
	virtual void Render() const = 0;
	virtual void RenderUpdate(double deltaTime) = 0;
protected:
	std::vector<Renderable*> *renderables = nullptr;
};

