#include "framework.h"

Entity::Entity()
{
	/*m_alive = true;
	m_health = 100;
	m_player = false;
	m_x = 0.0f;
	m_y = 0.0f;
	m_dy = 0.0f;
	m_angle = 0.0f;
	m_angleRot = 0.0f;
	m_radius = 0.0f;
	m_radiusSq = 0.0f;
	
	m_screenLimitX = 1000.0f;
	m_screenLimitY = 1000.0f;*/
	
	//m_type = ENEMY;
	//GetManager()->NotifyBornEntity(this);
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

void Entity::OnRender(sf::RenderTexture& rt)
{
}
