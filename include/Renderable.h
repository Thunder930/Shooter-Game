#pragma once
#include <vector>
class Renderable
{
public:
	virtual void Render() const = 0;
	virtual void Update(double deltaTime, std::vector<Renderable*>& renderables) = 0;
};

