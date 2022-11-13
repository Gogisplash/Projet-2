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
	Update();
	UpdateCollision();
}

void Entity::OnRender(sf::RenderTexture& rt)
{
	m_sprite->SetPosition(m_x, m_y);
	
	rt.draw(*m_sprite->GetSprite());
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

void Entity::SetVelocityY(float y)
{
	velocity.y = y;
}

void Entity::Move(float dir_x, float dir_y)
{
	//Acceleration
	velocity.x += dir_x * acceleration * GetApp()->GetElapsedTime();
	velocity.y += dir_y * jump * GetApp()->GetElapsedTime();

	//Limit velocity 
	if (abs(velocity.x) > velocityMax)
	{
		velocity.x = velocityMax * ((velocity.x < 0.f) ? -1.0f : 1.0f);
	}
}

void Entity::Deceleration()
{
	float elapsed = GetApp()->GetElapsedTime();
	if (abs(velocity.x) != 0)
	{
		if (velocity.x > 0)
		{
			velocity.x -= drag * elapsed;
		}
		else {
			velocity.x += drag * elapsed;
		}
	}
}

sf::FloatRect Entity::GetGlobalHitbox()
{
	return GetSprite()->GetSprite()->getGlobalBounds();
	
}

void Entity::UpdateCollision()
{
	if (GetApp()->GetManager()->TestCollision(this))
	{
		ResetVelocityY();
		//GetSprite()->SetPosition(GetGlobalBounds().left, WNDSIZE_H - GetGlobalBounds().height);
	}
	
}

void Entity::SetTexture(sf::Texture& texture)
{
	if (m_sprite != NULL)
	{
		m_sprite = NULL;
		delete m_sprite;
	}
	m_sprite = new Sprite;
	m_sprite->SetTexture(texture);
	m_sprite->SetScale(2.0f, 2.0f);
	m_sprite->SetOrigin(texture);
	
	//m_radius = min(texture.getSize().x, texture.getSize().y) / 2.0f;
	//m_radiusSq = m_radius * m_radius;
}




