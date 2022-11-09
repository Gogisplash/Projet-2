#pragma once

class Entity_manager
{
public:
	
	Entity_manager();
	virtual ~Entity_manager();

	void Clear();
	void Start();

	void NotifyBornEntity(Entity* pEntity);
	void NotifyKilledEntity(Entity* pEntity);
	void ArrangeEntities();
	void NotifyNewPlatform(sf::RectangleShape* pPlateform);
	bool TestCollision(Entity* pEntity);
	

	void OnUpdate();
	void OnRender(sf::RenderTexture& rt);

protected:
	set<Entity*> m_entities;
	vector<Entity*> m_killedEntities;
	vector<Entity*> m_bornEntities;
	vector<sf::RectangleShape*> m_plateform;
	
};
