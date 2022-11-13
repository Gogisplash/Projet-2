#include "framework.h"

TileMap::TileMap()
{
    m_box = nullptr;
}

TileMap::~TileMap()
{
}

void TileMap::Init(sf::RenderTexture& rt)
{
    m_sprite1.setTexture(GetApp()->m_texBgLevel1);
    m_tileset = GetApp()->m_texTileSet;
      
    LoadMap();
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
    rt.draw(m_sprite1); // Background
    
    GetApp()->GetManager()->DrawPlateform(&rt);

}

void TileMap::LoadMap()
{

    int box_sizeX = 80;
    int box_sizeY = 90;

    // Map 2

    //int map[10][20] =
    //{
    //    // Map Spawn

    //   {0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,4},
    //   {0,0,7,7,0,7,0,7,0,7,0,0,0,0,0,0,0,0,9,4},
    //   {7,0,0,0,0,0,0,0,0,0,0,7,7,0,7,0,0,7,7,4},
    //   {0,7,0,7,0,7,7,0,7,0,0,0,0,0,0,0,0,0,0,4},
    //   {0,0,0,0,0,0,0,0,0,0,7,0,7,0,0,0,0,0,0,4},
    //   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,7,0,0,4},
    //   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,4},
    //   {0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,7,0,7,7,4},
    //   {0,0,7,0,7,7,7,0,0,0,0,0,0,0,7,7,7,7,7,4},
    //   {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}

    //};

    int map[12][25] =
    {
        // Map Spawn

       {0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0},//   1   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
       {9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//   2
       {1,0,0,5,0,0,0,6,0,0,0,5,0,6,0,5,0,0,5,0,0,5,0,0,0},//   3   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
       {0,0,0,5,0,0,0,0,0,0,0,5,0,0,0,5,0,5,0,0,0,0,0,1,1},//   4
       {5,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0},//   5   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
       {0,0,0,0,0,0,0,0,5,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0},//   6
       {0,0,0,0,5,0,0,0,0,0,0,0,5,0,0,5,0,0,5,5,5,0,0,0,5},//   7   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
       {0,5,0,0,0,0,0,5,5,5,0,0,0,0,0,5,0,0,5,0,0,0,0,0,0},//   8
       {0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,5},//   9   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
       {0,0,0,0,0,5,0,0,0,5,0,0,0,5,0,0,5,0,5,0,5,0,0,5,0},//   10
       {0,0,0,5,0,0,0,0,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//   11   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
       {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} //   12

    };

    // Map 2

    //int map[12][25] =
    //{
    //    // Map Spawn

    //   {0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0},//   1   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    //   {9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//   2
    //   {1,0,0,5,0,0,0,6,0,0,0,5,0,6,0,5,0,0,5,0,0,5,0,0,0},//   3   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    //   {0,0,0,5,0,0,0,0,0,0,0,5,0,0,0,5,0,5,0,0,0,0,0,1,1},//   4
    //   {5,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0},//   5   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    //   {0,0,0,0,0,0,0,0,5,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0},//   6
    //   {0,0,0,0,5,0,0,0,0,0,0,0,5,0,0,5,0,0,5,5,5,0,0,0,5},//   7   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    //   {0,5,0,0,0,0,0,5,5,5,0,0,0,0,0,5,0,0,5,0,0,0,0,0,0},//   8
    //   {0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,5},//   9   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    //   {0,0,0,0,0,5,0,0,0,5,0,0,0,5,0,0,5,0,5,0,5,0,0,5,0},//   10
    //   {0,0,0,5,0,0,0,0,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//   11   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    //   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} //   12

    //};

    

    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 20; x++)
        {
            switch (map[y][x])
            {
            case 1:
            {
                // Sol marron
                m_box = new sf::RectangleShape(sf::Vector2f(box_sizeX, box_sizeY));
                m_box->setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                m_box->setTexture(&m_tileset);
                m_box->setTextureRect(sf::IntRect(98, 66, 141 - 98, 109 - 66));
                GetApp()->GetManager()->NotifyNewPlatform(m_box);

                break;
            }
            case 2:
            {
                // Sol vert
                m_box = new sf::RectangleShape(sf::Vector2f(box_sizeX, box_sizeY));
                m_box->setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                m_box->setTexture(&m_tileset);
                m_box->setTextureRect(sf::IntRect(98, 2, 141 - 98, 45 - 2));
                GetApp()->GetManager()->NotifyNewPlatform(m_box);

                break;
            }
            case 3:
            {
                // Sol violet
                m_box = new sf::RectangleShape(sf::Vector2f(box_sizeX, box_sizeY));
                m_box->setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                
                m_box->setTexture(&m_tileset);
                m_box->setTextureRect(sf::IntRect(98, 130, 141 - 98, 173 - 130));
                GetApp()->GetManager()->NotifyNewPlatform(m_box);
                break;
            }
            case 4:
            {
                // Brique rouge
                m_box = new sf::RectangleShape(sf::Vector2f(box_sizeX, box_sizeY));
                m_box->setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
               
                m_box->setTexture(&m_tileset);
                m_box->setTextureRect(sf::IntRect(274, 66, 314 - 274, 109 - 66));
                GetApp()->GetManager()->NotifyNewPlatform(m_box);
                break;
            }
            case 5:
            {
                // Relief marron
                m_box = new sf::RectangleShape(sf::Vector2f(box_sizeX, box_sizeY));
                m_box->setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                
                m_box->setTexture(&m_tileset);
                m_box->setTextureRect(sf::IntRect(210, 18, 237 - 210, 45 - 18));
                GetApp()->GetManager()->NotifyNewPlatform(m_box);
                break;
            }
            case 6:
            {
                // Relief gris
                m_box = new sf::RectangleShape(sf::Vector2f(box_sizeX, box_sizeY));
                m_box->setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                m_box->setTexture(&m_tileset);
                m_box->setTextureRect(sf::IntRect(211, 84, 237 - 211, 109 - 84));
                GetApp()->GetManager()->NotifyNewPlatform(m_box);
                break;
            }
            case 7:
            {
                // Relief orange
                m_box = new sf::RectangleShape(sf::Vector2f(box_sizeX, box_sizeY));
                m_box->setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                
                m_box->setTexture(&m_tileset);
                m_box->setTextureRect(sf::IntRect(210, 146, 237 - 210, 173 - 146));
                GetApp()->GetManager()->NotifyNewPlatform(m_box);
                break;
            }
            case 8:
            {
                // Relief gold
                m_box = new sf::RectangleShape(sf::Vector2f(box_sizeX, box_sizeY));
                m_box->setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                
                m_box->setTexture(&m_tileset);
                m_box->setTextureRect(sf::IntRect(290, 146, 317 - 290, 173 - 146));
                GetApp()->GetManager()->NotifyNewPlatform(m_box);
                break;
            }
            case 9:
            {
                // Porte
                m_box = new sf::RectangleShape(sf::Vector2f(box_sizeX, box_sizeY));
                m_box->setPosition(sf::Vector2f(x * box_sizeX, y * box_sizeY));
                
                m_box->setTexture(&m_tileset);
                m_box->setTextureRect(sf::IntRect(1, 65, 47 - 1, 111 - 65));
                GetApp()->GetManager()->NotifyNewPlatform(m_box);
                break;
            }
            default:
                break;
            }
            

        }
    }
    
    
}

