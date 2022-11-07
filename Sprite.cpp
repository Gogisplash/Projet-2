#include "framework.h"

Sprite::Sprite()
{
	
}

Sprite::~Sprite()
{
}

void Sprite::SetTexture(const sf::Texture& texture)
{

	m_sprite.setTexture(texture);
}

void Sprite::SetTextureEntity(sf::Texture& texture)
{

}

void Sprite::SetPosition(float x, float y)
{
	m_sprite.setPosition(x, y);
}

void Sprite::SetRotation(float angle)
{
	m_sprite.setRotation(angle);
}

void Sprite::SetScale(float x, float y)
{
	m_sprite.setScale(x, y);
}

void Sprite::SetTextureRect(int pixels, int x, int y)
{
	m_sprite.setTextureRect(sf::IntRect(x, y, pixels, pixels));
}

void Sprite::SetOrigin(sf::Texture& texture)
{
	m_sprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f);
}


