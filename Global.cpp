#include "framework.h"

extern App* g_pApp;

App* GetApp()
{
	return g_pApp;
}

Controller* GetController()
{
	return g_pApp->GetController();
}

Game* GetGame()
{
	return g_pApp->GetGame();
}
//
Entity_manager* GetManager()
{
	return g_pApp->GetManager();
}

Player* GetPlayer()
{
	return g_pApp->GetGame()->GetPlayer();
}


TileMap* GetTileMap()
{
	return g_pApp->GetGame()->GetTileMap();
}
