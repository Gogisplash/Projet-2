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
	void SetTextureRect(int pixels, int x, int y);
	void SetOrigin(sf::Texture& texture);

	sf::Sprite* GetSprite() { return &m_sprite; }

protected:

	sf::Sprite m_sprite;

};

