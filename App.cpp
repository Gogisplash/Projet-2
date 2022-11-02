#include "framework.h"

App::App()
{
	//m_pPhase = NULL;
	m_lastUpdate = 0.0f;
	m_countFrame = 0.0f;
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
	//sf::View view = m_window.getDefaultView();
	//view.setSize(WNDSIZE_F, -WNDSIZE_F);
	//m_window.setView(view);

	//// Render Target
	//m_rt.create(WNDSIZE_U, WNDSIZE_U);
	//m_sprite.setTexture(m_rt.getTexture());

	// Textures
	//LoadTextures();

	// Level
	//LoadLevel();

	//Sound
	//LoadSound();

	// Phases
	/*m_menu.Init();
	m_game.Init();
	m_score.Init();
	ToPhase(Phase::MENU);*/
}

void App::Uninit()
{
	//m_menu.Uninit();
	//m_game.Uninit();
}

BYTE* App::GetResource(const char* resType, int id, int& size)
{
	BYTE* data = NULL;
	HRSRC hs = FindResourceA(m_hInstance, MAKEINTRESOURCEA(id), resType);
	if (hs)
	{
		HGLOBAL hgBuf = LoadResource(m_hInstance, hs);
		if (hgBuf)
		{
			LPBYTE adBuf = (LPBYTE)LockResource(hgBuf);
			if (adBuf)
			{
				size = SizeofResource(m_hInstance, hs);
				data = new BYTE[size];
				memcpy(data, adBuf, size);
				UnlockResource(hgBuf);
			}
			FreeResource(hgBuf);
		}
	}
	return data;
}

void App::LoadTextures()
{
	LoadTextureFromResource(m_texBack, IDB_TEXTURE_BACK);
}

bool App::LoadTextureFromResource(sf::Texture& texture, int id)
{
	int size;
	BYTE* data = GetResource("PNG", id, size);
	if (data == NULL)
		return false;
	bool result = texture.loadFromMemory(data, size);
	delete[] data;
	return result;
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

void App::ToPhase(int phase, bool victory)
{
	/*switch (phase)
	{
	case Phase::MENU:
		m_pPhase = &m_menu;
		break;
		case Phase::GAME:
			m_pPhase = &m_game;
			m_pPhase->ToState(STATE_GAME_START);
			break;
		}
	}*/
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
	//m_controller.OnUpdate();

	// Phase (state update)
	//m_pPhase->OnExecute();

	// Phase (main update)
	//m_pPhase->OnUpdate();

	//Fps
	if (m_time - m_lastUpdate > 1)
	{
		/*m_lastUpdate = 0.0f;*/
		m_fps = m_countFrame;
		m_countFrame = 0.0f;
		m_lastUpdate = m_time;
	}
	m_countFrame += 1;
}

void App::Render()
{
	// Clear
	m_rt.clear();

	// Draw
	//m_pPhase->OnRender(m_rt);

	// Window
	m_window.draw(m_sprite);
	m_window.display();
}