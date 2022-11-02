#pragma once

class Camera :
    public State
{
    Camera();
    virtual ~Camera();

    virtual void OnEnter(int oldState);
    virtual void OnExecute();
    virtual void OnExit(int newState);
    
};

