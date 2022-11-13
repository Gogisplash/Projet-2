#pragma once

class TileMap
{
public:

    TileMap();
    virtual ~TileMap();
    void Init(sf::RenderTexture& rt);
    virtual void OnExecute();
    virtual void OnExecuteMain();           // D�clarer la fonction d'�x�cution de l'�cran Main
    virtual void OnUpdate();
    virtual void OnRender(sf::RenderTexture& rt);

    void LoadMap();
   
private:

    sf::RectangleShape* m_box;
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
    sf::Sprite m_sprite;
    sf::Sprite m_sprite1;
};
