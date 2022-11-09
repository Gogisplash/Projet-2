#include "framework.h"

Physics::Physics()
{
	velocityMaxY = 50.f;
	velocityMax = 500.0f;
	velocityMin = 1.0f;
	acceleration = 200.0f;
	drag = 90.f;
	gravity = 4.0f;
}

Physics::~Physics()
{
}

void Physics::Update()
{
	float elapsed = GetApp()->GetElapsedTime();

	//Deceleration
	//velocity.x -= drag * elapsed;
	
	//Gravity
	velocity.y += gravity * elapsed;

	//Limit Gravity
	if (abs(velocity.y) > velocityMaxY)
	{
		velocity.y = velocityMaxY * ((velocity.y < 0.f) ? -1.0f : 1.0f);
	}

	//Limit deceleration
	if (abs(velocity.x) < velocityMin)
	{
		velocity.x = 0.0f;
	}
	if (abs(velocity.y) < velocityMin)
	{
		velocity.y = 0.0f;
	}
	
}

void Physics::ResetVelocity()
{
	velocity.y = 0.0f;
}
