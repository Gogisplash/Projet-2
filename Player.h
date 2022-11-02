#pragma once
#include "State.h"
class Player :
    public State
{
public:
    Player();
    virtual ~Player();

    virtual void OnEnter(int oldState);
    virtual void OnExecute();
    virtual void OnExit(int newState);
    virtual void OnUpdate();
    void Init();

protected:
    Entity* m_pBody;
    float m_speed;
};

