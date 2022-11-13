#pragma once
class Physics
{
public:
	Physics();
	virtual ~Physics();

	void Update();
	void ResetVelocityY();
	void ResetVelocityX();

protected:
	sf::Vector2f velocity;
	float acceleration;
	float drag;
	float velocityMax;
	float velocityMin;
	float velocityMaxY;
	float gravity;
	float jump;
};

