#pragma once
class App
{
public:
	App();
	virtual ~App();

	void Init(HINSTANCE hInstance);
	void Uninit();
	
	bool HasWindow();

	bool UpdateTime();
	void Update();
	void Render();

protected:
	HINSTANCE m_hInstance;
	DWORD m_sysTime;

	RenderWindow m_window;
	RenderTexture m_rt;
	Sprite m_sprite;

	float m_time;
	float m_elapsedTime;

	Controller m_controller;
	Phase* m_pPhase;
};

