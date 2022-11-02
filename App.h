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

	bool UpdateTime();
	void Update();
	void Render();

	Controller* GetController() { return &m_controller; }
	Game* GetGame() { return &m_game; }
	//EntityManager* GetManager() { return m_game.GetManager(); }

protected:
	HINSTANCE m_hInstance;
	DWORD m_sysTime;

	RenderWindow m_window;
	RenderTexture m_rt;
	Sprite m_sprite;

	float m_time;
	float m_elapsedTime;

	Controller m_controller;
	Game m_game;
	Phase* m_pPhase;

public:
	Texture m_texBackground;
};

