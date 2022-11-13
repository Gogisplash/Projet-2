#include "framework.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init()
{
	m_font.loadFromFile("C:\\Windows\\Fonts\\verdana.ttf");
}

void Game::Uninit()
{
	m_manager.Clear();
}

void Game::Start()
{
	m_tileset.Init();
	m_player.Init();

	// Paramètres de la musique dans Game

	GetApp()->m_musicMenu.stop();
	GetApp()->m_musicGame.play();
	GetApp()->m_musicGame.setVolume(10.f);
	GetApp()->m_musicGame.setLoop(true);

	// Paramètres FPS

	m_txtFps.setFont(m_font);
	m_txtFps.setCharacterSize(10);
	m_txtFps.setStyle(sf::Text::Bold);
	m_txtFps.setFillColor(sf::Color::Black);
	m_txtFps.setPosition(500.0f, 500.0f);

}

void Game::Fps()
{

	float time = GetApp()->GetTime();
	m_frameCount++;
	if (time - m_timeLastFrame > 0.5f) {
		m_fps = m_frameCount / (time - m_timeLastFrame);
		m_timeLastFrame = time;
		m_frameCount = 0;
		m_txtFps.setString("FPS : " + std::to_string(m_fps));
	}
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

	// Fps
	Fps();
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

	// Entities
	m_manager.OnRender(rt);

	rt.draw(m_txtFps);

}