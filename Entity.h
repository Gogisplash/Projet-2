#pragma once

class Entity : public State
{
public:
	Entity();
	virtual ~Entity();

	virtual void OnEnter(int oldState);
	virtual void OnExecute();
	virtual void OnExit(int newState);
	virtual void OnUpdate();
	virtual void OnRender(sf::RenderTexture& rt);

protected:
	
};

