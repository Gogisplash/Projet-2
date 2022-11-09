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

    int box_sizeX = 80;
    int box_sizeY = 90;

    //int map[10][20] =
    //{
    //     // Map Spawn
    //    
    //    {0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,4},
    //    {0,0,7,7,0,7,0,7,0,7,0,0,0,0,0,0,0,0,9,4},
    //    {7,0,0,0,0,0,0,0,0,0,0,7,7,0,7,0,0,7,7,4},
    //    {0,7,0,7,0,7,7,0,7,0,0,0,0,0,0,0,0,0,0,4},
    //    {0,0,0,0,0,0,0,0,0,0,7,0,7,0,0,0,0,0,0,4},
    //    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,7,0,0,4},
    //    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,4},
    //    {0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,7,0,7,7,4},
    //    {0,0,7,0,7,7,7,0,0,0,0,0,0,0,7,7,7,7,7,4},
    //    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}

    //};

    int map[10][80] =
    {
    {0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,4},
    {0,0,7,7,0,7,0,7,0,7,0,0,0,0,0,0,0,0,9,0,0,0,7,7,0,7,0,7,0,7,0,0,0,0,0,0,0,0,9,4,0,0,7,7,0,7,0,7,0,7,0,0,0,0,0,0,0,0,9,4,0,0,7,7,0,7,0,7,0,7,0,0,0,0,0,0,0,0,9,4},
    {7,0,0,0,0,0,0,0,0,0,0,7,7,0,7,0,0,7,7,0,7,0,0,0,0,0,0,0,0,0,0,7,7,0,7,0,0,7,7,4,7,0,0,0,0,0,0,0,0,0,0,7,7,0,7,0,0,7,7,4,7,0,0,0,0,0,0,0,0,0,0,7,7,0,7,0,0,7,7,4},
    {0,7,0,7,0,7,7,0,7,0,0,0,0,0,0,0,0,0,0,0,0,7,0,7,0,7,7,0,7,0,0,0,0,0,0,0,0,0,0,4,0,7,0,7,0,7,7,0,7,0,0,0,0,0,0,0,0,0,0,4,0,7,0,7,0,7,7,0,7,0,0,0,0,0,0,0,0,0,0,4},
    {0,0,0,0,0,0,0,0,0,0,7,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,7,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,7,0,7,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,7,0,7,0,0,0,0,0,0,4},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,7,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,7,0,0,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,7,0,0,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,7,0,0,4},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,4},
    {0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,7,0,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,4},
    {0,0,7,0,7,7,7,0,0,0,0,0,0,0,7,7,7,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,4},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}
    };

    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 20; x++)
        {
            if (map[y][x] == 1)
            {
                // Sol marron
                sf::RectangleShape box(sf::Vector2f(box_sizeX, box_sizeY));
                box.setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                sf::Texture t = GetApp()->m_texTileSet;
                box.setTexture(&t);
                box.setTextureRect(sf::IntRect(98, 66, 141 - 98, 109 - 66));
                rt.draw(box);
            }

            if (map[y][x] == 2)
            {
                // Sol vert
                sf::RectangleShape box(sf::Vector2f(box_sizeX, box_sizeY));
                box.setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                sf::Texture t = GetApp()->m_texTileSet;
                box.setTexture(&t);
                box.setTextureRect(sf::IntRect(98, 2, 141 - 98, 45 - 2));
                rt.draw(box);
            }

            if (map[y][x] == 3)
            {
                // Sol violet
                sf::RectangleShape box(sf::Vector2f(box_sizeX, box_sizeY));
                box.setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                sf::Texture t = GetApp()->m_texTileSet;
                box.setTexture(&t);
                box.setTextureRect(sf::IntRect(98, 130, 141 - 98, 173 - 130));
                rt.draw(box);
            }

            if (map[y][x] == 4)
            {
                // Brique rouge
                sf::RectangleShape box(sf::Vector2f(box_sizeX, box_sizeY));
                box.setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                sf::Texture t = GetApp()->m_texTileSet;
                box.setTexture(&t);
                box.setTextureRect(sf::IntRect(274, 66, 314 - 274, 109 - 66));
                rt.draw(box);
            }

            if (map[y][x] == 5)
            {
                // Relief marron
                sf::RectangleShape box(sf::Vector2f(box_sizeX, box_sizeY));
                box.setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                sf::Texture t = GetApp()->m_texTileSet;
                box.setTexture(&t);
                box.setTextureRect(sf::IntRect(210, 18, 237 - 210, 45 - 18));
                rt.draw(box);
            }

            if (map[y][x] == 6)
            {
                // Relief gris
                sf::RectangleShape box(sf::Vector2f(box_sizeX, box_sizeY));
                box.setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                sf::Texture t = GetApp()->m_texTileSet;
                box.setTexture(&t);
                box.setTextureRect(sf::IntRect(211, 84, 237 - 211, 109 - 84));
                rt.draw(box);
            }

            if (map[y][x] == 7)
            {
                // Relief orange
                sf::RectangleShape box(sf::Vector2f(box_sizeX, box_sizeY));
                box.setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                sf::Texture t = GetApp()->m_texTileSet;
                box.setTexture(&t);
                box.setTextureRect(sf::IntRect(210, 146, 237 - 210, 173 - 146));
                rt.draw(box);
            }

            if (map[y][x] == 8)
            {
                // Relief gold
                sf::RectangleShape box(sf::Vector2f(box_sizeX, box_sizeY));
                box.setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                sf::Texture t = GetApp()->m_texTileSet;
                box.setTexture(&t);
                box.setTextureRect(sf::IntRect(290, 146, 317 - 290, 173 - 146));
                rt.draw(box);
            }

            if (map[y][x] == 9)
            {
                // Porte
                sf::RectangleShape box(sf::Vector2f(box_sizeX, box_sizeY));
                box.setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                sf::Texture t = GetApp()->m_texTileSet;
                box.setTexture(&t);
                box.setTextureRect(sf::IntRect(1, 65, 47 - 1, 111 - 65));
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

