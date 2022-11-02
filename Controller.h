#pragma once

class Controller
{
public:

    enum
    {
        NONE,
        DOWN,
        UP,
        PUSH,
    };

public:

    class Controller();
    virtual ~Controller();

    void Reset();
    int GetKey(int key, bool press);

    int Up() { return m_up; }
    int Down() { return m_down; }
    int Left() { return m_left; }
    int Right() { return m_right; }

    int Attack() { return m_attack == DOWN; }

    int Pickup() { return m_pickup == DOWN; }

    int Map() { return m_map == DOWN; }

    void OnUpdate();

protected:

    bool m_up;
    bool m_down;
    bool m_left;
    bool m_right;

    bool m_attack;
    bool m_pickup;
    bool m_map;

};