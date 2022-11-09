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

}

void TileMap::OnUpdate()
{

}

void TileMap::OnRender(sf::RenderTexture& rt)
{

    //int box_sizeX = 142 - 97;
    //int box_sizeY = 110 - 65;

    int box_sizeX = 90;
    int box_sizeY = 90;

    sf::Vector2f previous;

    int map[10][20] =
    {
        {0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0},
        {0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,1,1,0},
        {0,3,3,0,0,1,1,1,2,2,0,0,0,0,0,0,0,1,1,0},
        {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1,1,0},
        {0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,1,1,0},
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,0},
        {3,3,2,3,1,3,0,1,0,1,0,0,0,0,0,0,0,1,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0},
        {0,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0}
    };

    //plateforme test

    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 20; x++)
        {
            if (map[y][x] == 1)
            {
                sf::RectangleShape box(sf::Vector2f(box_sizeX, box_sizeY));
                box.setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                sf::Texture t = GetApp()->m_texTileSet;
                box.setTexture(&t);
                box.setTextureRect(sf::IntRect(98, 66, 141 - 98, 109 - 66));
                rt.draw(box);
            }

            if (map[y][x] == 2)
            {
                sf::RectangleShape box(sf::Vector2f(box_sizeX, box_sizeY));
                box.setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                sf::Texture t = GetApp()->m_texTileSet;
                box.setTexture(&t);
                box.setTextureRect(sf::IntRect(1, 65, 46 - 1, 111 - 65));
                rt.draw(box);
            }

            if (map[y][x] == 3)
            {
                sf::RectangleShape box(sf::Vector2f(box_sizeX, box_sizeY));
                box.setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                sf::Texture t = GetApp()->m_texTileSet;
                box.setTexture(&t);
                box.setTextureRect(sf::IntRect(98, 130, 141 - 98, 173 - 130));
                rt.draw(box);
            }  

        }
    }
    //sf::RectangleShape box(sf::Vector2f(offsetX, offsetY));
    //box.setFillColor(sf::Color::Green);
    //box.setPosition(sf::Vector2f(x * offsetX, y * offsetY));
    //box.setOutlineThickness(1.f);
    //box.setOutlineColor(sf::Color::Black);
    //window->draw(box);
}

