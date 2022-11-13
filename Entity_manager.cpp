#include "framework.h"

Entity_manager::Entity_manager()
{
}

Entity_manager::~Entity_manager()
{
}

void Entity_manager::Clear()
{
	ArrangeEntities();
	m_bornEntities.clear();
	m_killedEntities.clear();
	m_plateform.clear();
	for (set<Entity*>::iterator it = m_entities.begin(); it != m_entities.end(); ++it)
		delete* it;
	m_entities.clear();

}

void Entity_manager::Start()
{
	Clear();
}

void Entity_manager::NotifyBornEntity(Entity* pEntity)
{
	if (pEntity)
		m_bornEntities.push_back(pEntity);
}

void Entity_manager::NotifyKilledEntity(Entity* pEntity)
{
	if (pEntity)
		m_killedEntities.push_back(pEntity);
}


void Entity_manager::ArrangeEntities()
{
	// Born entities
	for (vector<Entity*>::iterator it = m_bornEntities.begin(); it != m_bornEntities.end(); ++it)
		m_entities.insert(*it);
	m_bornEntities.clear();

	// Killed entities
	for (vector<Entity*>::iterator it = m_killedEntities.begin(); it != m_killedEntities.end(); ++it)
	{
		m_entities.erase(*it);
		delete* it;
	}
	m_killedEntities.clear();
}

void Entity_manager::NotifyNewPlatform(sf::RectangleShape* pPlateform)
{
	if (pPlateform)
		m_plateform.push_back(pPlateform);
}

bool Entity_manager::TestCollision(Entity* pEntity)
{
	
	for (auto it = m_plateform.begin(); it != m_plateform.end(); ++it)
	{
		bool colider = pEntity->GetGlobalHitbox().intersects((*it)->getGlobalBounds());
  		if(colider)
		{
  			return true;
		}
		
	}
	return false;
}

//Entity* Entity_manager::TestCollision(Entity* pEntity)
//{
//	for (set<Entity*>::iterator it = m_entities.begin(); it != m_entities.end(); ++it)
//	{
//		if ((pEntity)->TestCollision(*it))
//			return *it;
//	}
//	return NULL;
//}

void Entity_manager::OnUpdate()
{
	// States
	for (set<Entity*>::iterator it = m_entities.begin(); it != m_entities.end(); ++it)
	{
		(*it)->OnExecute();
	}

	// Entities
	for (set<Entity*>::iterator it = m_entities.begin(); it != m_entities.end(); ++it)
	{
		(*it)->OnUpdate();
	}
	ArrangeEntities();
}

void Entity_manager::OnRender(sf::RenderTexture& rt)
{
	// Entities
	for (set<Entity*>::iterator it = m_entities.begin(); it != m_entities.end(); ++it)
	{
		(*it)->OnRender(rt);
	}
}
