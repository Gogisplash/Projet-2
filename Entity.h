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

	void SetPlayer() { m_player = true; }

	void SetTexture(sf::Texture& texture);

protected:

	Sprite* m_sprite;

	bool m_player;
	float m_x;
	float m_y;
	float m_radius;
	float m_radiusSq;
};

