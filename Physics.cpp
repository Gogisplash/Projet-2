#include "framework.h"

Physics::Physics()
{
	velocityMaxY = 500.f;
	velocityMax = 400.0f;
	velocityMin = 1.0f;
	acceleration = 300.0f;
	//jump = 1500.f;
	drag = 200.f;
	gravity = 200.0f;
}

Physics::~Physics()
{
}

void Physics::Update()
{
	float elapsed = GetApp()->GetElapsedTime();

	//Gravity
	velocity.y += gravity * elapsed;

	//Limit Gravity
	if (abs(velocity.y) > velocityMaxY)
	{
		velocity.y = velocityMaxY * ((velocity.y < 0.f) ? -1.0f : 1.0f);
	}
}

void Physics::ResetVelocityY()
{
	velocity.y = 0.0f;
}
