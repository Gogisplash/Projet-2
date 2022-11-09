#pragma once
class Physics
{
public:
	Physics();
	virtual ~Physics();

protected:
	sf::Vector2f velocity;
	float acceleration;
	float drag;
	float velocityMax;
};

