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
	bool m_alive;
	int m_health;
	bool m_player;
	sf::Sprite* m_sprite;
	int m_type;
	float m_x;
	float m_y;
	float m_dy;
	float m_angle;
	float m_angleRot;
	float m_radius;
	float m_radiusSq;
	float m_screenLimitX;
	float m_screenLimitY;
	int m_row;
	int m_column;
};

