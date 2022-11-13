#include "framework.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init()
{
	
}

void Game::Uninit()
{
	
}

void Game::Start()
{

	m_tileset.Init(*(GetApp()->GetRenderTexture()));
	m_player.Init();
	m_rec = sf::RectangleShape(sf::Vector2f(50.f, 50.f));
	m_rec.setPosition(500.f, 500.f);
	m_rec.setFillColor(sf::Color::Color(54, 255, 255, 255));
	GetManager()->NotifyNewPlatform(&m_rec);
	


}

void Game::OnEnter(int oldState)
{
	{
		switch (m_state)
		{
		case STATE_GAME_START:
			Start();
			break;
		case STATE_GAME_PLAY:
			break;
		}
	}
}


void Game::OnExecute()
{
	switch (m_state)
	{
	case STATE_GAME_START:
		ToState(STATE_GAME_PLAY);
		break;
	case STATE_GAME_PLAY:
		//ExecutePlay();
		break;
	}
	
}

void Game::OnExit(int newState)
{
}

void Game::OnUpdate() 
{
	// Player
	m_player.OnUpdate();


	// Entities
	m_manager.OnUpdate();

	// Map
	m_tileset.OnUpdate();

}

void Game::OnRender(sf::RenderTexture& rt)
{
	// Background
	rt.draw(*m_sprite.GetSprite());


	// Map
	m_tileset.OnRender(rt);

	// Entities
	m_manager.OnRender(rt);

}