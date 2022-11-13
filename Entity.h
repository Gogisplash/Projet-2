#pragma once

class Entity : public State, public Physics
{
public:
	Entity();
	virtual ~Entity();


	virtual void OnEnter(int oldState);
	virtual void OnExecute();
	virtual void OnExit(int newState);
	virtual void OnUpdate();
	virtual void OnRender(sf::RenderTexture& rt);

	void SetPosition(float x, float y);
	void AddX(float x);
	void AddY(float y);
	void SetVelocityY(float y);
	void Move(float dir_x, float dir_y);
	void Deceleration();

	sf::FloatRect GetGlobalHitbox();
	
	void UpdateCollision();

	sf::Vector2f GetVelocity() { return velocity; };
	float GetX() { return m_x; }
	float GetY() { return m_y; }

	void SetPlayer() { m_player = true; }

	void SetTexture(sf::Texture& texture);
	Sprite* GetSprite() { return m_sprite; }

protected:

	Sprite* m_sprite;
	sf::FloatRect m_hitbox;

	bool m_player;
	float m_x;
	float m_y;
	float m_radius;
	float m_radiusSq;
};

