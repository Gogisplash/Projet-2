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


	// Phases

	m_menu.Init();
	m_game.Init();

	// Render Target
	m_rt.create(WNDSIZE_W, WNDSIZE_H);
	m_sprite.setTexture(m_rt.getTexture());

	// Textures

	LoadTextures();

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
	LoadTextureFromResource(m_texMenu, IDB_TEXTURE_MENU);
	LoadTextureFromResource(m_texGround, IDB_TEXTURE_GROUND);

	m_sprite.setTexture(m_texMenu);
	//m_sprite.setScale(100.0f, 100.0f);
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

	Render();

	return true;
}

void App::ToPhase(int phase)
{
	switch (phase)
	{
	case Phase::MENU:
		m_pPhase = &m_menu;
		break;
	case Phase::GAME:
		m_pPhase = &m_game;
		m_pPhase->ToState(STATE_GAME_START);
		break;
	}
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

