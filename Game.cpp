#include "framework.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init()
{
	// Initialisation des sprites

	m_sprite.setTexture(GetApp()->m_texBack);
}

void Game::Uninit()
{

}

void Game::Start()
{

}

void Game::UpdateUI()
{
}

void Game::Score(int score)
{

}

void Game::ExecutePlay()
{

}

void Game::OnEnter(int oldState)
{
}

void Game::LoadLevel() // Chargement du patern du niveau
{

}

void Game::OnExecute()
{

}

void Game::OnExit(int newState)
{
}

void Game::OnUpdate() // Mise à jour du patern
{
}

void Game::OnRender(sf::RenderTexture& rt)
{
	// Background
	rt.draw(m_sprite);

}