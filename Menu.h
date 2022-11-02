#pragma once
#include "Phase.h"
class Menu :
    public Phase
{
public:
    Menu();
   virtual ~Menu();

   void Init();
   void Uninit();
   
   virtual int GetID() { return MENU; }

   virtual void OnEnter(int oldState);
   virtual void OnExecute();
   virtual void OnExit(int newState);
   virtual void OnUpdate();
   virtual void OnRender(sf::RenderTexture& rt);
};

