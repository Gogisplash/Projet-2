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
  
   

    virtual void OnEnter(int oldState);
    virtual void OnExecute();
    virtual void OnExit(int newState);
    virtual void OnUpdate();
    virtual void OnRender(sf::RenderTexture& rt);

protected:
   /* Sprite m_sprite;
    EntityManager m_manager;
    Player m_player;*/
};

