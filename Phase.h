#pragma once

class Phase : public State
{
public:
	enum
	{
		NONE,
		GAME,
		MENU
	};

public:
	Phase();
	virtual ~Phase();

	virtual int GetID() = 0;

	virtual void OnUpdate() = 0;
	virtual void OnRender(sf::RenderTexture& rt) = 0;
};

