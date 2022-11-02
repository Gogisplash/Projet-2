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

	
	bool HasWindow();

	void Render();
	void Update();

	// Création des classes de Texture avec SFML

	Texture m_texGround;
	Texture m_texPlayer;

protected:
	HINSTANCE m_hInstance;
	DWORD m_sysTime;
	RenderWindow m_window;
	RenderTexture m_rt;
	Sprite m_sprite;

	Controller m_controller;
	Game m_game;

	Phase* m_pPhase;
};

