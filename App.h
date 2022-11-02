#pragma once
class App
{
public:
	App();
	virtual ~App();

	void Init(HINSTANCE hInstance);
	void Uninit();

	BYTE* GetResource(const char* resType, int id, int& size);
	void LoadTextures();
	bool LoadTextureFromResource(sf::Texture& texture, int id);

	Game* GetGame() { return &m_game; }
	Menu* GetMenu() { return &m_menu; }
	
	bool HasWindow();
	void Render();

	void ToPhase(int phase);

	void Quit() { m_running = false; } // Option quitter de l'�cran

	bool m_running;


	// Cr�ation des classes de Texture avec SFML

	sf::Texture m_texMenu;
	sf::Texture m_texGround;
	sf::Texture m_texBack;

protected:
	HINSTANCE m_hInstance;
	RenderWindow m_window;
	RenderTexture m_rt;
	Sprite m_sprite;

	Menu m_menu;
	Game m_game;

	Phase* m_pPhase;
};

