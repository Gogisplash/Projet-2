#pragma once
class Animation
{
public:
	Animation();
	Animation(int frameNbr, int fps);
	virtual ~Animation();

	void Init();
	void Update();
	sf::IntRect GetCurrentFrame() { return currentframe[iFrame]; }

protected:
	float time;
	int iFrame;
	int frameCount;
	float ms;

	sf::IntRect* currentframe;
};

