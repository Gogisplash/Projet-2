#include "framework.h"

Entity::Entity()
{
	m_player = false;
	m_x = 0.0f;
	m_y = 0.0f;
	m_radius = 0.0f;
	m_radiusSq = 0.0f;
	m_sprite = NULL;
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
	rt.draw(*m_sprite);
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
	m_sprite->setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f);
	m_radius = min(texture.getSize().x, texture.getSize().y) / 2.0f;
	m_radiusSq = m_radius * m_radius;
}
