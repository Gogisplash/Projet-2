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

    GetApp()->m_musicMenu.play();
    GetApp()->m_musicMenu.setVolume(20.f);
    GetApp()->m_musicMenu.setLoop(true);

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

    for (int i = 0; i < m_maxSettings; i++)
    {
        m_menu[i].setFillColor(sf::Color::White);
    }

    m_menu[selectedItemIndex].setFillColor(sf::Color::Blue);
    m_settings[selectedItemIndex].setFillColor(sf::Color::Blue);


    GetApp()->m_soundDMenu.play();
    GetApp()->m_soundDMenu.setVolume(99.0f);

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
            m_menu[0].setFillColor(sf::Color::Blue);
            m_menu[0].setCharacterSize(30);
            m_menu[0].setStyle(sf::Text::Bold);
            m_menu[0].setString("Start Game");
            m_menu[0].setPosition(sf::Vector2f(300 / 2, 950 / (MAX_NUMBER_OF_ITEMS + 1) * 1));

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
            m_menu[2].setString("Credits");
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
            m_maxSettings = 2;
            m_maxItems = 0;
            selectedItemIndex = 0;
            UpdateButtons();
            GetApp()->m_musicMenu.stop();

            m_sprite.setTexture(GetApp()->m_texSettings);

            m_settings[0].setFont(m_font);
            m_settings[0].setFillColor(sf::Color::Blue);
            m_settings[0].setCharacterSize(30);
            m_settings[0].setStyle(sf::Text::Bold);
            m_settings[0].setString("1. Music ON");
            m_settings[0].setPosition(sf::Vector2f(300 / 2, 950 / (MAX_NUMBER_OF_ITEMS + 1) * 1));

            m_settings[1].setFont(m_font);
            m_settings[1].setFillColor(sf::Color::White);
            m_settings[1].setCharacterSize(30);
            m_settings[1].setStyle(sf::Text::Bold);
            m_settings[1].setString("2. Music OFF");
            m_settings[1].setPosition(sf::Vector2f(300 / 2, 900 / (MAX_NUMBER_OF_ITEMS + 1) * 2));


            break;
        }
        case STATE_CREDITS:
        {
            m_maxItems = 0;
            m_maxSettings = 0;
            m_sprite.setTexture(GetApp()->m_texCredits);

            GetApp()->m_musicMenu.stop();
            GetApp()->m_musicCredits.play();
            GetApp()->m_musicCredits.setVolume(30);
            GetApp()->m_musicCredits.setLoop(true);


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
    case STATE_SETTINGS:
        OnExecuteSettings();
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
        case MAIN_SETTINGS:
            ToState(STATE_SETTINGS);
            break;
        case MAIN_CREDITS:
            ToState(STATE_CREDITS);
            break;
        case MAIN_QUIT:
            GetApp()->Quit();
            break;
        }
    }
 
}

void Menu::OnExecuteSettings()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        switch (GetPressedItem())
        {
        case MUSIC_OFF:

            GetApp()->m_musicMenu.stop();
            GetApp()->m_musicGame.stop();
            break;

        case MUSIC_ON:

            GetApp()->m_musicMenu.play();
            GetApp()->m_musicMenu.setVolume(20.f);
            GetApp()->m_musicMenu.setLoop(true);
        }
    }
}




void Menu::OnExit(int newState)
{
}

void Menu::OnUpdate()
{
    if (GetController()->Back()) // Revenir dans le menu avec echap
    {
        ToState(STATE_MAIN);
        m_sprite.setTexture(GetApp()->m_texMenu);
        GetApp()->m_musicGame.stop();
        GetApp()->m_musicCredits.stop();
        GetApp()->m_musicMenu.play();
    }

    if (GetController()->Up())
    {
        if (selectedItemIndex - 1 >= 0)
        {
            selectedItemIndex--;
            UpdateButtons();
            Sleep(200);
        }
    }
    if (GetController()->Down())
    {
        if (selectedItemIndex + 1 < m_maxItems)
        {
            selectedItemIndex++;
            UpdateButtons();
            Sleep(200);
        }

        if (selectedItemIndex + 1 < m_maxSettings)
        {
            selectedItemIndex++;
            UpdateButtons();
            Sleep(200);
        }

    }
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

    // Settings

    if (m_state == (STATE_SETTINGS))
    {
        for (int i = 0; i < m_maxSettings; i++)
        {
            rt.draw(m_settings[i]);
        }
    }


}


