#include "framework.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Init()
{
	m_pPlayer = new Entity;
	m_pPlayer->SetTexture(GetApp()->m_texPlayer);
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
}
