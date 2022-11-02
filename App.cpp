#include "framework.h"

App::App()
{
	
	m_lastUpdate = 0.0f;
	m_pPhase = NULL;
}

App::~App()
{
}

// Chargement de la police si elle est bien chargée
void App::LoadFont()
{
	// Chargement Font
	if (font.loadFromFile("ressource/Front/poorFront.ttf") == false)
	{
		// Check que la police est chargée
		cout << "Erreur chargement font !" << endl;
	}
	// Création d'un texte
	sf::Text m_txt;
}

void App::SetText(sf::Text& txt, String str)
{
	// Indication de la bonne police
	txt.setFont(font);
	// chaine de string
	txt.setString(str);
	// On indique la taille
	txt.setCharacterSize(26);
	// On donne la couleur
	txt.setFillColor(sf::Color::Cyan);
	// Modif du style
	txt.setStyle(Text::Bold | Text::Underlined);
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
	//Activation du vsync
	m_window.setVerticalSyncEnabled(true);
	// On règle toutes les propriétés
	//SetText(txt, "Mon texte !"); Ecrire un texte

	m_rt.create(WNDSIZE_W, WNDSIZE_H);
	m_sprite.setTexture(m_rt.getTexture());

	LoadTextures();


	ToPhase(Phase::GAME);
}


void App::Uninit()
{
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
	LoadTextureFromResource(m_texPlayer, IDB_PLAYER_IDLE);
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
	//--------------
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
	m_pPhase->OnRender(m_rt);

	// Window
	//m_window.draw(m_sprite);

	//m_window.clear(Color::Red);
	m_window.draw(m_sprite);
	m_window.display();


}

void App::Update()
{
	// Controller
	m_controller.OnUpdate();

	// Phase (state update)
	m_pPhase->OnExecute();

	// Phase (main update)
	m_pPhase->OnUpdate();
}