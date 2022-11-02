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
	
	bool HasWindow();
	void Render();

	// Création des classes de Texture avec SFML

	sf::Texture m_texGround;
	sf::Texture m_texPlayer;

protected:
	HINSTANCE m_hInstance;
	RenderWindow m_window;
	RenderTexture m_rt;
	Sprite m_sprite;

	Game m_game;

	Phase* m_pPhase;
};

