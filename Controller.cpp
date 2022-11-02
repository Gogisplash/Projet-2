#include "framework.h"

Controller::Controller()
{
	Reset();
}

Controller::~Controller()
{
}

void Controller::Reset()
{
	m_back = NONE;
	m_start = NONE;
	
	m_up = false;
	m_down = false;
	m_left = false;
	m_right = false;

}

int Controller::GetKey(int key, bool press)
{
	if (press)
	{
		if (key == NONE || key == UP)
			key = DOWN;
		else if (key == DOWN)
			key = PUSH;
	}
	else
	{
		if (key == PUSH || key == DOWN)
			key = UP;
		else if (key == UP)
			key = NONE;
	}
	return key;
}

void Controller::OnUpdate()
{
	m_start = GetKey(m_start, sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
	m_back = GetKey(m_back, sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
	m_up = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	m_down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
	m_left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	m_right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}