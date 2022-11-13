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
	
}

void Entity::OnRender(sf::RenderTexture& rt)
{
	if (m_sprite != NULL)
	{
		m_sprite->SetPosition(m_x, m_y);
	
		rt.draw(*m_sprite->GetHitbox());
		
	}
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
	velocity.y += dir_y * GetApp()->GetElapsedTime();

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
	return GetSprite()->GetHitbox()->getGlobalBounds();
	
}


void Entity::SetTexture(sf::Texture& texture)
{
	/*sf::Vector2f a = sf::Vector2f(texture.getSize());
	m_hitbox = new sf::RectangleShape(a);*/
	
	if (m_sprite != NULL)
	{
		m_sprite = NULL;
		delete m_sprite;
	}
	/*m_hitbox->setTexture(&texture);
	m_hitbox->setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f);*/
	m_sprite = new Sprite;
	m_sprite->SetTexture(texture);
	m_sprite->SetOrigin(texture);
	
	//m_radius = min(texture.getSize().x, texture.getSize().y) / 2.0f;
	//m_radiusSq = m_radius * m_radius;
}

void Entity::TestCollision(sf::RectangleShape* plateform)
{
	sf::Vector2f entityPosition = GetSprite()->GetPosition();
	sf::Vector2f plateformPosition = plateform->getPosition();

	sf::Vector2f entityHalfSize = GetSprite()->GetHalfSize();
	sf::Vector2f plateformHalfSize = plateform->getSize() / 2.0f;
	float deltaX = plateformPosition.x - entityPosition.x;
	float deltaY = plateformPosition.y - entityPosition.y;
	float intersectX = abs(deltaX) - (entityHalfSize.x + plateformHalfSize.x);
	float intersectY = abs(deltaY) - (entityHalfSize.y + plateformHalfSize.y);

	if (intersectX < 0.f && intersectY < 0.f)
	{
		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f)
			{
				Move(intersectX, 0.0f);
				//plateform->move(-intersectX, 0.0f);
			}
			else
			{
				Move(-intersectX, 0.0f);
				//plateform->move(intersectX, 0.0f);
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				ResetVelocityY();
				//Move(0.0f,intersectY);
				//plateform->move(0.0f,-intersectY);
			}
			else
			{
				ResetVelocityY();
				//Move(0.0f,-intersectY);
				//plateform->move(0.0f, intersectY);
			}
		}
	}
	
}




