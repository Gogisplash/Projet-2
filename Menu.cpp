#include "framework.h"

Menu::Menu()
{
    
}

Menu::~Menu()
{
}


void Menu::Init()
{

    m_sprite.setTexture(GetApp()->m_texMenu);
    m_font.loadFromFile("C:\\Windows\\Fonts\\verdana.ttf");

    ToState(STATE_MAIN);

}

void Menu::Uninit()
{
}

void Menu::UpdateButtons()
{
    for (int i = 0; i < m_maxItems; i++)
    {
        m_menu[i].setFillColor(sf::Color::White);
    }

    m_menu[selectedItemIndex].setFillColor(sf::Color::Red);

}

void Menu::OnEnter(int oldState)
{
    switch (m_state)
    {

    case STATE_MAIN:
    {
        m_maxItems = 4;
        selectedItemIndex = 0;
        UpdateButtons();

        //Menu
        m_menu[0].setFont(m_font);
        m_menu[0].setFillColor(sf::Color::Red);
        m_menu[0].setCharacterSize(30);
        m_menu[0].setStyle(sf::Text::Bold);
        m_menu[0].setString("Start Game");
        m_menu[0].setPosition(sf::Vector2f(300 / 2, 1800 / (MAX_NUMBER_OF_ITEMS + 1) * 1));

        m_menu[1].setFont(m_font);
        m_menu[1].setFillColor(sf::Color::White);
        m_menu[1].setCharacterSize(30);
        m_menu[1].setStyle(sf::Text::Bold);
        m_menu[1].setString("Settings");
        m_menu[1].setPosition(sf::Vector2f(300 / 2, 900 / (MAX_NUMBER_OF_ITEMS + 1) * 2));

        m_menu[2].setFont(m_font);
        m_menu[2].setFillColor(sf::Color::White);
        m_menu[2].setCharacterSize(30);
        m_menu[2].setStyle(sf::Text::Bold);
        m_menu[2].setString("Manual");
        m_menu[2].setPosition(sf::Vector2f(300 / 2, 850 / (MAX_NUMBER_OF_ITEMS + 1) * 3));

        m_menu[3].setFont(m_font);
        m_menu[3].setFillColor(sf::Color::White);
        m_menu[3].setCharacterSize(30);
        m_menu[3].setStyle(sf::Text::Bold);
        m_menu[3].setString("Quit");
        m_menu[3].setPosition(sf::Vector2f(300 / 2, 800 / (MAX_NUMBER_OF_ITEMS + 1) * 4));

        selectedItemIndex = 0;

        break;
    }
    case STATE_SETTINGS:
    {
        m_maxItems = 0;
        m_sprite.setTexture(GetApp()->m_texGround);

        break;
    }
    case STATE_MANUAL:
    {
        m_maxItems = 0;
        m_sprite.setTexture(GetApp()->m_texGround);


        break;
    }
    }
}

void Menu::OnExecute()
{
    switch (m_state)
    {
    case STATE_MAIN:
        OnExecuteMain();
        break;
    }

}

void Menu::OnExecuteMain()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        switch (GetPressedItem())
        {
        case MAIN_START_GAME:
            GetApp()->ToPhase(GAME);
            break;
        case MAIN_QUIT:
            GetApp()->Quit();
            break;
        }
    }
 
}



void Menu::OnExit(int newState)
{
}

void Menu::OnUpdate()
{

}

void Menu::OnRender(sf::RenderTexture& rt)
{
    // Background
    rt.draw(m_sprite);

    // Menu
    if (m_state == (STATE_MAIN))
    {
        for (int i = 0; i < m_maxItems; i++)
        {
            rt.draw(m_menu[i]);
        }
    }

}

void Menu::Init()
{
}

void Menu::Uninit()
{
}

void Menu::OnEnter(int oldState)
{
}

void Menu::OnExecute()
{
}

void Menu::OnExit(int newState)
{
}

void Menu::OnUpdate()
{
}

void Menu::OnRender(sf::RenderTexture& rt)
{
}
