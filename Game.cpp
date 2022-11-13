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
	m_manager.Clear();
}

void Game::Start()
{

	m_tileset.Init(*(GetApp()->GetRenderTexture()));
	m_player.Init();

	// Paramètres de la musique dans Game

	GetApp()->m_musicMenu.stop();
	GetApp()->m_musicGame.play();
	GetApp()->m_musicGame.setVolume(10.f);
	GetApp()->m_musicGame.setLoop(true);

	m_rec = sf::RectangleShape(sf::Vector2f(50.f, 50.f));
	m_rec.setPosition(1200.f, 400.f);
	m_rec.setFillColor(sf::Color::Color(180, 255, 255, 255));
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
	GetApp()->GetWindow()->setView(GetApp()->GetWindow()->getDefaultView());
	rt.draw(*m_sprite.GetSprite());

	// View

	viewGame.setSize(WNDSIZE_W, -WNDSIZE_H);
	viewGame.setCenter(GetPlayer()->GetXplayer(), 450.0f);
	GetApp()->GetWindow();
	GetApp()->GetWindow()->setView(viewGame);
	GetApp()->GetWindow()->clear();

	// Map
	m_tileset.OnRender(rt);
	rt.draw(m_rec);
	// Entities
	m_manager.OnRender(rt);

}