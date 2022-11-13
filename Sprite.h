#pragma once
class Sprite
{
public:
	Sprite();
	virtual ~Sprite();

	void SetTexture(const sf::Texture& texture);
	void SetTextureEntity(sf::Texture& texture);
	void SetPosition(float x, float y);
	void SetRotation(float angle);
	void SetScale(float x, float y);
	void SetTextureRect(sf::IntRect rect);
	void SetOrigin(sf::Texture& texture);
	void Rotate(float angle);
	void Move(sf::Vector2f velocity);

	sf::Vector2f GetPosition() { return m_sprite.getPosition(); }
	
	sf::Sprite* GetSprite() { return &m_sprite; }
	sf::RectangleShape* GetHitbox() { return &m_hitBox; }

protected:
	
	sf::RectangleShape m_hitBox;
	sf::Sprite m_sprite;

	
};

