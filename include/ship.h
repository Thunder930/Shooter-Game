class Ship
{
public:
	Ship(float xPos, float yPos);
	void Move(bool moveUp, double deltaTime);
	void Render();
private:
	float xPos;
	float yPos;
};