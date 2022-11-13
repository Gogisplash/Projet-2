#pragma once
class App
{
public:
	App();
	virtual ~App();

	void Init(HINSTANCE hInstance);
	void Uninit();

	void LoadFont();

	void SetText(sf::Text& txt, sf::String str);

	BYTE* GetResource(const char* resType, int id, int& size);
	void LoadTextures();
	bool LoadTextureFromResource(sf::Texture& texture, int id);
	void InitTexture();

	void LoadSound();
	bool LoadSoundFromResource(sf::SoundBuffer& sound, int id);

	void LoadMusics();
	bool LoadMusicFromResource(sf::Music& music, int id);

	Game* GetGame() { return &m_game; }
	Controller* GetController() { return &m_controller; }
	Entity_manager* GetManager() { return m_game.GetManager(); }
	TileMap* GetTileMap() { return &m_tileset; }
	sf::RenderTexture* GetRenderTexture() { return &m_rt; }

	bool HasWindow();

	bool UpdateTime();
	float GetTime() { return m_time; }
	float GetElapsedTime() { return m_elapsedTime; }


	void ToPhase(int phase);

	void Render();
	void Update();


	void Quit() { m_running = false; } // Option quitter de l'�cran

	bool m_running;


	// Cr�ation des classes de Texture avec SFML

	sf::Texture m_texBgLevel1;
	sf::Texture m_texMenu;
	sf::Texture m_texSettings;
	sf::Texture m_texCredits;
	sf::Texture m_texBack;
	sf::Texture m_texGround;
	sf::Texture m_texPlayerIdle;
	sf::Texture m_texPlayerRun;
	sf::Texture m_texTileSet;

	sf::RenderWindow* GetWindow() { return &m_window; };
	
	vector<Sprite> m_animRun;

	sf::Font font;
	sf::Text m_text;
	sf::View view;
	string m_txt;

	// Cr�ation des musiques via SFML

	sf::Music m_musicMenu;			// Musique du menu
	sf::Music m_musicGame;			// Musique du game
	sf::Music m_musicCredits;		// Musique du credit

	// Cr�ation des sons et buffer via SFML 

	sf::SoundBuffer bufferDMenu;  // Buffer son d�placement menu

	sf::Sound m_soundDMenu;         // Son d�placement �l�ment menu

protected:
	HINSTANCE m_hInstance;
	DWORD m_sysTime;

	float m_time;
	float m_elapsedTime;
	float m_lastUpdate;

	sf::RenderWindow m_window;
	sf::RenderTexture m_rt;

	Sprite m_sprite;
	Controller m_controller;
	Game m_game;
	Menu m_menu;
	TileMap m_tileset;

	Phase* m_pPhase;
};

