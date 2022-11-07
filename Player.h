#pragma once

class Player : public State
{
public:
    enum {
        IDLE = 0, 
        RUN_LEFT, 
        RUN_RIGHT, 
        JUMPING, 
        FALLING,
        CRAWLING
        };
    Player();
    virtual ~Player();

    void Init();

    void Mouvement();
    
    void UpdatePlayerAnimation();

    virtual void OnEnter(int oldState);
    virtual void OnExecute();
    virtual void OnExit(int newState);
    virtual void OnUpdate();

protected:
    Entity* m_pPlayer;
    Sprite* m_sprite;

    float m_speed;
     
    int animState;
    Animation* m_animIdle;
    Animation* m_animRun;
    
};

