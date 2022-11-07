#include "framework.h"

TileMap::TileMap()
{
}

TileMap::~TileMap()
{
}

void TileMap::Init()
{
    m_sprite.setTexture(GetApp()->m_texTileSet);
    m_sprite.setTexture(GetApp()->m_texGround);   
}

void TileMap::OnExecute()
{
}

void TileMap::OnExecuteMain()
{
    sf::RectangleShape test(sf::Vector2f(120, 50));
    sf::Texture t = GetApp()->m_texTileSet;
    test.setTexture(&t);
    test.setTextureRect(sf::IntRect(97.1, 142.1, 97.46, 142.46));
}

void TileMap::OnUpdate()
{
    int offsetX = 100, offsetY = 100;

    sf::Vector2f previous;

    int tabmap[10][20] =
    {
        {0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0},
        {0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,1,1,0},
        {0,3,3,0,0,1,1,1,2,2,0,0,0,0,0,0,0,1,1,0},
        {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1,1,0},
        {0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,1,1,0},
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,0},
        {0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0},
        {0,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0}
    };

    //plateforme test

    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 20; x++)
        {
            if (tabmap[y][x] == 1)
            {
                sf::RectangleShape box(sf::Vector2f(offsetX, offsetY));
                box.setFillColor(sf::Color::Red);
                box.setPosition(sf::Vector2f(x * offsetX, y * offsetY));
                box.setOutlineThickness(1.f);
                box.setOutlineColor(sf::Color::Black);
                //GetApp()->m_window->draw(box);
            };

            if (tabmap[y][x] == 2)
            {
                sf::RectangleShape box(sf::Vector2f(offsetX, offsetY));
                box.setFillColor(sf::Color::Blue);
                box.setPosition(sf::Vector2f(x * offsetX, y * offsetY));
                box.setOutlineThickness(1.f);
                box.setOutlineColor(sf::Color::Black);
                //draw(box);
            };

            if (tabmap[y][x] == 3)
            {
                sf::RectangleShape box(sf::Vector2f(offsetX, offsetY));
                box.setFillColor(sf::Color::Green);
                box.setPosition(sf::Vector2f(x * offsetX, y * offsetY));
                box.setOutlineThickness(1.f);
                box.setOutlineColor(sf::Color::Black);
                //->draw(box);
            };
        }
    }
}

void TileMap::OnRender(sf::RenderTexture& rt)
{
    
}

//sf::IntRect(10, 10, 100, 100);


