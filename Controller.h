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

public:
	Controller();
	virtual ~Controller();

	void Reset();
	int GetKey(int key, bool press);

	bool Back() { return m_attack == DOWN; }
	bool Start() { return m_start == DOWN; }
	
	bool Up() { return m_up; }
	bool Down() { return m_down; }
	bool Left() { return m_left; }
	bool Right() { return m_right; }

	void OnUpdate();

public:

protected:
	int m_attack;
	int m_start;
	bool m_up;
	bool m_down;
	bool m_left;
	bool m_right;
};
