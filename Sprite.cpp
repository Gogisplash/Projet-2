#include "framework.h"

Sprite::Sprite()
{
	
}

Sprite::~Sprite()
{
}

void Sprite::SetTexture(const sf::Texture& texture)
{
	m_hitBox.setTexture(&texture);
}

void Sprite::SetSize(sf::Texture& texture)
{
	sf::Vector2f size_text = sf::Vector2f(texture.getSize());
	m_hitBox.setSize(size_text);
}

void Sprite::SetSize(sf::Vector2f size)
{
	m_hitBox.setSize(size);
}

void Sprite::SetPosition(float x, float y)
{
	m_hitBox.setPosition(x, y);
}

void Sprite::SetRotation(float angle)
{
	m_hitBox.setRotation(angle);
}

void Sprite::SetScale(sf::Vector2f scale)
{
	m_hitBox.setScale(scale);
}

void Sprite::SetTextureRect(sf::IntRect rect)
{
	m_hitBox.setTextureRect(rect);
}

void Sprite::SetOrigin(sf::Texture& texture)
{
	m_hitBox.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f);
}


void Sprite::Rotate(float angle)
{
	m_hitBox.rotate(angle);
}

void Sprite::Move(sf::Vector2f velocity)
{
	m_hitBox.move(velocity);
	
}


