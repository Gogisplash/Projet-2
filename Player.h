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

   

    float GetXplayer();
    float GetYplayer();

    virtual void OnEnter(int oldState);
    virtual void OnExecute();
    virtual void OnExit(int newState);
    virtual void OnUpdate();

protected:
    Entity* m_pPlayer;
    Sprite* m_sprite;


    float m_speed;
     
    sf::Vector2f m_scale_left;
    sf::Vector2f m_scale_right;

    

    int animState;
    Animation* m_animIdle;
    Animation* m_animRun;
    
    
};

