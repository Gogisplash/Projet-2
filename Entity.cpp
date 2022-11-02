#include "framework.h"

Entity::Entity()
{
	m_player = false;
	m_x = 0.0f;
	m_y = 0.0f;
	m_radius = 0.0f;
	m_radiusSq = 0.0f;
	m_sprite = NULL;
	GetManager()->NotifyBornEntity(this);
}

Entity::~Entity()
{
}

void Entity::OnEnter(int oldState)
{
}

void Entity::OnExecute()
{
}

void Entity::OnExit(int newState)
{
}

void Entity::OnUpdate()
{
}

void Entity::OnRender(RenderTexture& rt)
{
	m_sprite->setPosition(m_x, m_y);
	m_sprite->setRotation(180);
	rt.draw(*m_sprite);
}

void Entity::SetPosition(float x, float y)
{
	m_x = x;
	m_y = y;
}

void Entity::AddX(float x)
{
	m_x += x;
}

void Entity::AddY(float y)
{
	m_y += y;
}

void Entity::SetTexture(Texture& texture)
{
	if (m_sprite != NULL)
	{
		m_sprite = NULL;
		delete m_sprite;
	}
	m_sprite = new Sprite;
	m_sprite->setTexture(texture);
	m_sprite->setScale(2.0f, 2.0f);
	m_sprite->setTextureRect(IntRect(0, 0, 32, 32));
	m_sprite->setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f);
	m_radius = min(texture.getSize().x, texture.getSize().y) / 2.0f;
	//m_radiusSq = m_radius * m_radius;
}
void Entity::UpdateAnimation()
{
	/*int frameX = 0;
	int frameY = 0;
	for (int i; i <= 11; i + 1)
	{
		frameX += 32;
		frameY += 32;
		m_sprite->setTextureRect(IntRect(frameX, frameY, 32, 32));
	}*/
}

