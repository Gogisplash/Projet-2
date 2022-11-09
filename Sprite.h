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

	void Animation();
	
	sf::Sprite* GetSprite() { return &m_sprite; }

protected:

	sf::Sprite m_sprite;
	vector<Sprite> TileSet;
	float time;
	float elapsedTime;

};

