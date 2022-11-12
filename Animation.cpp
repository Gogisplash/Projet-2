#include "framework.h"

Animation::Animation()
{
	iFrame = 0;
	currentframe = nullptr;
}

Animation::Animation(int frameNbr, int fps)
{
	iFrame = 0;
	frameCount = frameNbr;
	time = 0;
	ms = (1000/fps)/1000.0f;
	currentframe = new sf::IntRect[frameNbr];
	Init();
}

Animation::~Animation()
{
	delete[] currentframe;
}

void Animation::Init()
{
	for (int i = 0; i < this->frameCount; i++)
	{
		currentframe[i] = sf::IntRect(i * 32, 0, 32, 32);
	}
}

void Animation::Update()
{
	time += GetApp()->GetElapsedTime();
	if (time >= ms) {
		iFrame++;
		if (iFrame >= frameCount)
		{
			iFrame = 0;
		}
		time -= ms;
	}
}