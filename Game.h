#pragma once

class Game : public Phase
{
public:
    Game();
    virtual ~Game();

    virtual int GetID() { return GAME; }

    void Init();
    void Uninit();
    void Start();
  
   
    Entity_manager* GetManager() { return &m_manager; }
    Player* GetPlayer() { return &m_player; }
    TileMap* GetTileMap() { return &m_tileset; }

    virtual void OnEnter(int oldState);
    virtual void OnExecute();
    virtual void OnExit(int newState);
    virtual void OnUpdate();
    virtual void OnRender(sf::RenderTexture& rt);

protected:

    sf::RectangleShape m_rec;
    Sprite m_sprite;
    Entity_manager m_manager;
    Player m_player;
    TileMap m_tileset;
    Physics m_physics;
};

