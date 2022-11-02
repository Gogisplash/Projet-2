#include "framework.h"
#include "Controller.h"

Controller::Controller()
{
    Reset();
}

Controller::~Controller()
{
}

void Controller::Reset()
{
    m_up = NONE;
    m_down = NONE;
    m_left = NONE;
    m_right = NONE;

    m_attack = NONE;
    m_pickup = NONE;
    m_map = NONE;
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
    m_up = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
    m_down = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
    m_left = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
    m_right = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);

    m_attack = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
    m_pickup = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P);
    m_map = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::M);


}
