#pragma once
class App
{
public:
	App();
	virtual ~App();

	void Init(HINSTANCE hInstance);
	void Uninit();

	void LoadFont();

	void SetText(sf::Text& txt, String str);

	BYTE* GetResource(const char* resType, int id, int& size);
	void LoadTextures();
	bool LoadTextureFromResource(sf::Texture& texture, int id);

	Game* GetGame() { return &m_game; }
	Controller* GetController() { return &m_controller; }
	Entity_manager* GetManager() { return m_game.GetManager(); }

	bool HasWindow();

	bool UpdateTime();
	float GetTime() { return m_time; }
	float GetElapsedTime() { return m_elapsedTime; }


	void ToPhase(int phase);

	void Render();
	void Update();


	void Quit() { m_running = false; } // Option quitter de l'écran

	bool m_running;


	// Création des classes de Texture avec SFML

	sf::Texture m_texMenu;
	sf::Texture m_texBack;
	sf::Font font;
	Texture m_texGround;
	Texture m_texPlayer;
	Text m_text;
	string m_txt;

protected:
	HINSTANCE m_hInstance;
	DWORD m_sysTime;

	float m_time;
	float m_elapsedTime;
	float m_lastUpdate;

	RenderWindow m_window;
	RenderTexture m_rt;
	Sprite m_sprite;

	Controller m_controller;
	Game m_game;
	Menu m_menu;

	Phase* m_pPhase;
};

