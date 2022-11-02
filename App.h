#pragma once
class App
{
public:
	App();
	virtual ~App();

	void Init(HINSTANCE hInstance);
	void Uninit();
	
	bool HasWindow();

protected:
	HINSTANCE m_hInstance;

	RenderWindow m_window;
};

