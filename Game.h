#pragma once

class Game :
    public Phase
{
public:
    Game();
    virtual ~Game();

    void Init();
    void Uninit();

    virtual int GetID() { return GAME; }

    //EntityManager* GetManager() { return &m_manager; }
    Player* GetPlayer() { return &m_player; }

    virtual void OnEnter(int oldState);
    virtual void OnExecute();
    virtual void OnExit(int newState);
    virtual void OnUpdate();
    virtual void OnRender(sf::RenderTexture& rt);

protected:
    //EntityManager m_manager;
    Player m_player;
};

