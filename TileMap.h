#pragma once

class TileMap
{
public:

    TileMap();
    virtual ~TileMap();
    void Init();
    virtual void OnExecute();
    virtual void OnExecuteMain();           // Déclarer la fonction d'éxécution de l'écran Main
    virtual void OnUpdate();
    virtual void OnRender(sf::RenderTexture& rt);

private:

    //virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    //{
    //    // on applique la transformation
    //    states.transform *= getTransform();

    //    // on applique la texture du tileset
    //    states.texture = &m_tileset;

    //    // et on dessine enfin le tableau de vertex
    //    target.draw(m_vertices, states);
    //}

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
    sf::Sprite m_sprite;
    sf::Sprite m_sprite1;
};
