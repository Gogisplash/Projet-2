#pragma once

class Controller
{
public:
	enum
	{
		NONE,
		DOWN,
		UP,
		PUSH,
	};

	Controller();
	virtual ~Controller();

	void Reset();
	int GetKey(int key, bool press);

	int Back() { return m_back == DOWN; }
	bool Start() { return m_start == DOWN; }
	bool Up() { return m_up == DOWN; }
	bool Jump() { return m_jump == DOWN; }

	bool Down() { return m_down; }
	bool Left() { return m_left; }
	bool Right() { return m_right; }

	void OnUpdate();

protected:
	int m_attack;
	int m_start;
	int m_jump;
	int m_back;

	bool m_up;
	bool m_down;
	bool m_left;
	bool m_right;
};
