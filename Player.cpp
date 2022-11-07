#include "framework.h"

Player::Player()
{
	m_speed = 400.0f;
	currentframe = 0;
}

Player::~Player()
{
}

void Player::Init()
{
	m_pPlayer = new Entity;
	m_pPlayer->SetPlayer();
	m_pPlayer->SetPosition(500, 500);
	m_pPlayer->SetTexture(GetApp()->m_texPlayerIdle);
	
}

void Player::Mouvement()
{
	float time = GetApp()->GetTime();
	float elapsed = GetApp()->GetElapsedTime();
	if (GetController()->Right())
	{
		m_pPlayer->AddX(m_speed * elapsed);
	}
		
	if (GetController()->Left())
		m_pPlayer->AddX(-m_speed * elapsed);
	if (GetController()->Up())
		m_pPlayer->AddY(m_speed * elapsed);
	if (GetController()->Down())
		m_pPlayer->AddY(-m_speed * elapsed);
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
	UpdatePlayerAnimation();
}

void Player::UpdatePlayerAnimation()
{
	/*float time = GetApp()->GetTime();
	float updateTime = GetApp()->GetController();*/
	
	if (GetController()->Right())
	{
		m_pPlayer->SetTexture(GetApp()->m_texPlayerRun);
		m_pPlayer->GetSprite()->SetTextureRect(32,currentframe,0);
		currentframe += 32;
		if (currentframe > 352)
		{
			currentframe = 0;
		}
	}

	if (GetController()->Left())

		if (GetController()->Up())

			if (GetController()->Down())

				;
}
