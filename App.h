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

	Controller* GetController() { return &m_controller; }
	Game* GetGame() { return &m_game; }
	EntityManager* GetManager() { return m_game.GetManager(); }

	bool HasWindow();
	float GetTime() { return m_time; }
	float GetElapsedTime() { return m_elapsedTime; }

	void ToPhase(int phase, bool victory = false);

	bool UpdateTime();
	void Update();
	void Render();

protected:
	HINSTANCE m_hInstance;
	DWORD m_sysTime;
	float m_time;
	float m_elapsedTime;
	float m_countFrame;
	float m_fps;
	float m_lastUpdate;

	sf::RenderWindow m_window;
	sf::RenderTexture m_rt;
	sf::Sprite m_sprite;

	Controller m_controller;
	Menu m_menu;
	Game m_game;

	Phase* m_pPhase;
};

