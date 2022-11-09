#include "framework.h"

Player::Player()
{
	m_speed = 400.0f;
	animState = IDLE;
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
	
	m_animIdle = new Animation(11, 20);
	m_animRun = new Animation(12, 20);
	//m_pPlayer->GetSprite()->SetTextureRect(currentframe);
	
}

void Player::Mouvement()
{
	float time = GetApp()->GetTime();
	float elapsed = GetApp()->GetElapsedTime();
	if (GetController()->Right())
	{
		m_pPlayer->AddX(m_speed * elapsed);
		this->animState = RUN_RIGHT;
	}
	else if (GetController()->Left())
	{
		m_pPlayer->AddX(-m_speed * elapsed);
		this->animState = RUN_LEFT;
	}
	else if (GetController()->Up())
	{
		m_pPlayer->AddY(-m_speed * elapsed);
		this->animState = JUMPING;
	}
	else if (GetController()->Down())
	{
		m_pPlayer->AddY(m_speed * elapsed);
		this->animState = CRAWLING;
	}
	else
	{
		this->animState = IDLE;
	}
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
	Sprite* t_sprite = m_pPlayer->GetSprite();
		if (animState == IDLE)
		{
			t_sprite->SetTexture((GetApp()->m_texPlayerIdle));
			m_animIdle->Update();
			t_sprite->SetTextureRect(m_animIdle->GetCurrentFrame());
			t_sprite->SetPosition(m_pPlayer->GetX(), m_pPlayer->GetY());
		}
		else if (animState == RUN_RIGHT)
		{
			t_sprite->SetTexture((GetApp()->m_texPlayerRun));
			m_animRun->Update();
			t_sprite->SetTextureRect(m_animRun->GetCurrentFrame());
			t_sprite->SetPosition(m_pPlayer->GetX(), m_pPlayer->GetY());
		}
		else if (animState == RUN_LEFT)
		{

			t_sprite->SetTexture((GetApp()->m_texPlayerRun));
			m_animRun->Update();
			//m_pPlayer->GetSprite()->SetScale(-2.0f, 2.0f);
			t_sprite->SetTextureRect(m_animRun->GetCurrentFrame());
			//t_sprite->SetOrigin((GetApp()->m_texPlayerRun));
			
			t_sprite->SetPosition(m_pPlayer->GetX(), m_pPlayer->GetY());
			
		}


}
