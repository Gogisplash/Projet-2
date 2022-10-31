#include "framework.h"

App::App()
{
	m_pPhase = NULL;
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
	m_window.create(sf::VideoMode(WNDSIZE_U, WNDSIZE_U), "Platform", sf::Style::Close);
	sf::View view = m_window.getDefaultView();
	view.setSize(WNDSIZE_F, -WNDSIZE_F);
	m_window.setView(view);

	// Render Target
	m_rt.create(WNDSIZE_U, WNDSIZE_U);
	m_sprite.setTexture(m_rt.getTexture());

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
