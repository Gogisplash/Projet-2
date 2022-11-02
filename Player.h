#pragma once
#include "State.h"
class Player :
    public State
{
public:
    Player();
    virtual ~Player();

    void Init();

    virtual void OnEnter(int oldState);
    virtual void OnExecute();
    virtual void OnExit(int newState);
    virtual void OnUpdate();
};

