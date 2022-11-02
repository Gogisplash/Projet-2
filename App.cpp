#include "framework.h"

App::App()
{
	m_pPhase = NULL;
}

App::~App()
{
}

void App::Init(HINSTANCE hInstance)
{
	// App
	m_hInstance = hInstance;

	// Time
	m_sysTime = timeGetTime();
	m_elapsedTime = 0.0f;
	m_time = 0.0f;

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

bool App::UpdateTime()
{
	// System time
	DWORD newSysTime = timeGetTime();
	DWORD elapsedSysTime = newSysTime - m_sysTime;
	if (elapsedSysTime < 5) // 200 fps max
		return false;
	m_sysTime = newSysTime;
	if (elapsedSysTime > 40) // 25 fps min
		elapsedSysTime = 40;

	// App time
	m_elapsedTime = elapsedSysTime / 1000.0f;
	m_time += m_elapsedTime;
	return true;
}

void App::Update()
{
	// Controller
	m_controller.OnUpdate();

	// Phase (state update)
	m_pPhase->OnExecute();

	// Phase (main update)
	m_pPhase->OnUpdate();

	//Fps
	//if (m_time - m_lastUpdate > 1)
	//{
	//	/*m_lastUpdate = 0.0f;*/
	//	m_fps = m_countFrame;
	//	m_countFrame = 0.0f;
	//	m_lastUpdate = m_time;
	//}
	//m_countFrame += 1;
}

void App::Render()
{
	// Clear
	m_rt.clear();

	// Draw
	m_pPhase->OnRender(m_rt);

	// Window
	m_window.draw(m_sprite);
	m_window.display();
}
