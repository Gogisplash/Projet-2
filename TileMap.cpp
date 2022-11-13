#include "framework.h"

TileMap::TileMap()
{
    m_box = nullptr;
}

TileMap::~TileMap()
{
}

void TileMap::Init()
{
    m_sprite1.setTexture(GetApp()->m_texBgLevel1);
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

void TileMap::Map1(sf::RenderTexture& rt)
{
    {

        //float time = GetApp()->GetTime();
        //float elapsed = GetApp()->GetElapsedTime();

        //int box_sizeX = 142 - 97;
        //int box_sizeY = 110 - 65;

        int box_sizeX = 80;
        int box_sizeY = 90;

        int map[10][20] =
        {
            // Map Spawn

           {0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,4},
           {0,0,7,7,0,7,0,7,0,7,0,0,0,0,0,0,0,0,9,4},
           {7,0,0,0,0,0,0,0,0,0,0,7,7,0,7,0,0,7,7,4},
           {0,7,0,7,0,7,7,0,7,0,0,0,0,0,0,0,0,0,0,4},
           {0,0,0,0,0,0,0,0,0,0,7,0,7,0,0,0,0,0,0,4},
           {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,7,0,0,4},
           {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,4},
           {0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,7,0,7,7,4},
           {0,0,7,0,7,7,7,0,0,0,0,0,0,0,7,7,7,7,7,4},
           {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}

        };



        m_box = new sf::RectangleShape(sf::Vector2f(box_sizeX, box_sizeY));
        for (int y = 0; y < 10; y++)
        {
            for (int x = 0; x < 20; x++)
            {
                if (map[y][x] == 1)
                {
                    // Sol marron
                    m_box->setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                    sf::Texture t = GetApp()->m_texTileSet;
                    m_box->setTexture(&t);
                    m_box->setTextureRect(sf::IntRect(98, 66, 141 - 98, 109 - 66));
                    rt.draw(*m_box);
                }

                if (map[y][x] == 2)
                {
                    // Sol vert
                    m_box->setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                    sf::Texture t = GetApp()->m_texTileSet;
                    m_box->setTexture(&t);
                    m_box->setTextureRect(sf::IntRect(98, 2, 141 - 98, 45 - 2));
                    rt.draw(*m_box);
                }

                if (map[y][x] == 3)
                {
                    // Sol violet
                    m_box->setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                    sf::Texture t = GetApp()->m_texTileSet;
                    m_box->setTexture(&t);
                    m_box->setTextureRect(sf::IntRect(98, 130, 141 - 98, 173 - 130));
                    rt.draw(*m_box);
                }

                if (map[y][x] == 4)
                {
                    // Brique rouge
                    m_box->setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                    sf::Texture t = GetApp()->m_texTileSet;
                    m_box->setTexture(&t);
                    m_box->setTextureRect(sf::IntRect(274, 66, 314 - 274, 109 - 66));
                    rt.draw(*m_box);
                }

                if (map[y][x] == 5)
                {
                    // Relief marron
                    m_box->setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                    sf::Texture t = GetApp()->m_texTileSet;
                    m_box->setTexture(&t);
                    m_box->setTextureRect(sf::IntRect(210, 18, 237 - 210, 45 - 18));
                    rt.draw(*m_box);
                }

                if (map[y][x] == 6) // Plateforme Mouvante
                {
                    // Relief gris
                    m_box->setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                    sf::Texture t = GetApp()->m_texTileSet;
                    m_box->setTexture(&t);
                    m_box->setTextureRect(sf::IntRect(211, 84, 237 - 211, 109 - 84));
                    rt.draw(*m_box);
                }

                if (map[y][x] == 7)
                {
                    // Relief orange
                    m_box->setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                    sf::Texture t = GetApp()->m_texTileSet;
                    m_box->setTexture(&t);
                    m_box->setTextureRect(sf::IntRect(210, 146, 237 - 210, 173 - 146));
                    rt.draw(*m_box);
                }

                if (map[y][x] == 8)
                {
                    // Relief gold
                    m_box->setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                    sf::Texture t = GetApp()->m_texTileSet;
                    m_box->setTexture(&t);
                    m_box->setTextureRect(sf::IntRect(290, 146, 317 - 290, 173 - 146));
                    rt.draw(*m_box);
                }

                if (map[y][x] == 9)
                {
                    // Porte
                    m_box->setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                    sf::Texture t = GetApp()->m_texTileSet;
                    m_box->setTexture(&t);
                    m_box->setTextureRect(sf::IntRect(1, 65, 47 - 1, 111 - 65));
                    rt.draw(*m_box);
                }
                GetManager()->NotifyNewPlatform(m_box);
            }
        }
    }
}

void TileMap::Map2(sf::RenderTexture& rt)
{
    {

        //float time = GetApp()->GetTime();
        //float elapsed = GetApp()->GetElapsedTime();

        //int box_sizeX = 142 - 97;
        //int box_sizeY = 110 - 65;

        int box_sizeX = 80;
        int box_sizeY = 90;

        int map[12][25] =
        {
            // Map Spawn

           {0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0},//   1
           {9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//   2
           {1,0,0,5,0,0,0,6,0,0,0,5,0,6,0,5,0,0,5,0,0,5,0,0,0},//   3
           {0,0,0,5,0,0,0,0,0,0,0,5,0,0,0,5,0,5,0,0,0,0,0,1,1},//   4
           {5,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0},//   5
           {0,0,0,0,0,0,0,0,5,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0},//   6
           {0,0,0,0,5,0,0,0,0,0,0,0,5,0,0,5,0,0,5,5,5,0,0,0,5},//   7
           {0,5,0,0,0,0,0,5,5,5,0,0,0,0,0,5,0,0,5,0,0,0,0,0,0},//   8
           {0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,5},//   9
           {0,0,0,0,0,5,0,0,0,5,0,0,0,5,0,0,5,0,5,0,5,0,0,5,0},//   10
           {0,0,0,5,0,0,0,0,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//   11
           {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} //   12

        };



        m_box = new sf::RectangleShape(sf::Vector2f(box_sizeX, box_sizeY));
        for (int y = 0; y < 12; y++)
        {
            for (int x = 0; x < 25; x++)
            {
                if (map[y][x] == 1)
                {
                    // Sol marron
                    m_box->setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                    sf::Texture t = GetApp()->m_texTileSet;
                    m_box->setTexture(&t);
                    m_box->setTextureRect(sf::IntRect(98, 66, 141 - 98, 109 - 66));
                    rt.draw(*m_box);
                }

                if (map[y][x] == 2)
                {
                    // Sol vert
                    m_box->setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                    sf::Texture t = GetApp()->m_texTileSet;
                    m_box->setTexture(&t);
                    m_box->setTextureRect(sf::IntRect(98, 2, 141 - 98, 45 - 2));
                    rt.draw(*m_box);
                }

                if (map[y][x] == 3)
                {
                    // Sol violet
                    m_box->setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                    sf::Texture t = GetApp()->m_texTileSet;
                    m_box->setTexture(&t);
                    m_box->setTextureRect(sf::IntRect(98, 130, 141 - 98, 173 - 130));
                    rt.draw(*m_box);
                }

                if (map[y][x] == 4)
                {
                    // Brique rouge
                    m_box->setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                    sf::Texture t = GetApp()->m_texTileSet;
                    m_box->setTexture(&t);
                    m_box->setTextureRect(sf::IntRect(274, 66, 314 - 274, 109 - 66));
                    rt.draw(*m_box);
                }

                if (map[y][x] == 5)
                {
                    // Relief marron
                    m_box->setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                    sf::Texture t = GetApp()->m_texTileSet;
                    m_box->setTexture(&t);
                    m_box->setTextureRect(sf::IntRect(210, 18, 237 - 210, 45 - 18));
                    rt.draw(*m_box);
                }

                if (map[y][x] == 6) // Plateforme Mouvante
                {
                    // Relief gris
                    m_box->setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                    sf::Texture t = GetApp()->m_texTileSet;
                    m_box->setTexture(&t);
                    m_box->setTextureRect(sf::IntRect(211, 84, 237 - 211, 109 - 84));
                    rt.draw(*m_box);
                }

                if (map[y][x] == 7)
                {
                    // Relief orange
                    m_box->setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                    sf::Texture t = GetApp()->m_texTileSet;
                    m_box->setTexture(&t);
                    m_box->setTextureRect(sf::IntRect(210, 146, 237 - 210, 173 - 146));
                    rt.draw(*m_box);
                }

                if (map[y][x] == 8)
                {
                    // Relief gold
                    m_box->setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                    sf::Texture t = GetApp()->m_texTileSet;
                    m_box->setTexture(&t);
                    m_box->setTextureRect(sf::IntRect(290, 146, 317 - 290, 173 - 146));
                    rt.draw(*m_box);
                }

                if (map[y][x] == 9)
                {
                    // Porte
                    m_box->setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                    sf::Texture t = GetApp()->m_texTileSet;
                    m_box->setTexture(&t);
                    m_box->setTextureRect(sf::IntRect(1, 65, 47 - 1, 111 - 65));
                    rt.draw(*m_box);
                }
                GetManager()->NotifyNewPlatform(m_box);
            }
        }
    }
}

void TileMap::OnRender(sf::RenderTexture& rt)
{
    rt.draw(m_sprite1); // Background
    //GetManager()->
}