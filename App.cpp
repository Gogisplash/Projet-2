#include "framework.h"

App::App()
{
	
}

App::~App()
{
}

void App::Init(HINSTANCE hInstance)
{
	// App
	m_hInstance = hInstance;

	// Window
	m_window.create(VideoMode(WNDSIZE_W, WNDSIZE_H), "Titre", sf::Style::Close);

	// Activation du vsync
	m_window.setVerticalSyncEnabled(true);

	
}

void App::Uninit()
{
	//m_menu.Uninit();
	//m_game.Uninit();
}

bool App::HasWindow()
{
	if (m_window.isOpen() == false)
		return false;

	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
			return false;
		}
	}

	return true;
}

