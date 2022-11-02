#pragma once

class Game : public Phase
{
public:
    Game();
    virtual ~Game();

    virtual int GetID() { return GAME; }

    void Init();
    void Uninit();
    void Start();
    void LoadLevel();

    void UpdateUI();

    void Score(int score);

    void ExecutePlay();

    virtual void OnEnter(int oldState);
    virtual void OnExecute();
    virtual void OnExit(int newState);
    virtual void OnUpdate();
    virtual void OnRender(sf::RenderTexture& rt);

protected:
    sf::Sprite m_sprite;
};

