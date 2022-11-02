#pragma once
class Entity_manager
{
public:
	Entity_manager();
	virtual ~Entity_manager();

	void Clear();
	void Start();

	void OnUpdate();
	void OnRender(sf::RenderTexture& rt);
protected:
	set<Entity*> m_entities;
	vector<Entity*> m_killedEntities;
	vector<Entity*> m_bornEntities;
};

