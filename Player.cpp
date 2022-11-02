#include "framework.h"

Player::Player()
{
	m_speed = 400.0f;
}

Player::~Player()
{
}

void Player::Init()
{
	m_pPlayer = new Entity;
	m_pPlayer->SetPlayer();
	m_pPlayer->SetPosition(500, 500);
	m_pPlayer->SetTexture(GetApp()->m_texPlayer);
	
}

void Player::Mouvement()
{
	float time = GetApp()->GetTime();
	float elapsed = GetApp()->GetElapsedTime();
	if (GetController()->Right())
		m_pPlayer->AddX(m_speed * elapsed);
	if (GetController()->Left())
		m_pPlayer->AddX(-m_speed * elapsed);
}

void Player::OnEnter(int oldState)
{
}

void Player::OnExecute()
{
}

void Player::OnExit(int newState)
{
}

void Player::OnUpdate()
{
	Mouvement();
}
