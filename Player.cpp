#include "framework.h"

Player::Player()
{
	//m_speed = 35.0f;
	animState = IDLE;
	
	m_scale_left = { -1,1 };
	m_scale_right = { 1,-1 };

	m_lastJump = 0.f;
	
}

Player::~Player()
{
}

void Player::Init()
{
	m_pPlayer = new Entity;
	m_pPlayer->SetPlayer();
	m_pPlayer->SetPosition(800.f,600.f);
	
	m_pPlayer->SetTexture(GetApp()->m_texPlayerIdle);
	
	sf::Vector2f size = sf::Vector2f(80.0f, 80.0f);
	m_pPlayer->GetSprite()->SetSize(size);
	m_animIdle = new Animation(11, 20);
	m_animRun = new Animation(12, 20);
	
	
	
}

void Player::Mouvement()
{
	
	float time = GetApp()->GetTime();
	float elapsed = GetApp()->GetElapsedTime();
	if (GetController()->Right())
	{
		m_pPlayer->Move(1.0f, 0.0f);
		
		this->animState = RUN_RIGHT;
	}
	if (GetController()->Left())
	{
		m_pPlayer->Move(-1.0f, 0.0f);
		
		this->animState = RUN_LEFT;
	}
	if (GetController()->Jump())
	{
		if (time - m_lastJump > 1.f)
		{
			m_pPlayer->SetVelocityY(-350.f);
			m_lastJump = time;
			this->animState = JUMPING;
		}
	}
	if (GetController()->Down())
	{
		m_pPlayer->Move(0.f, 1.f);
		this->animState = CRAWLING;
	}
	else
	{
		this->animState = IDLE;
		m_pPlayer->Deceleration();
	}
	
	m_pPlayer->AddY(m_pPlayer->GetVelocity().y * elapsed);
	m_pPlayer->AddX(m_pPlayer->GetVelocity().x * elapsed);
}

float Player::GetXplayer()
{
	return m_pPlayer->GetX();
}

float Player::GetYplayer()
{
	return m_pPlayer->GetY();
}


void Player::UpdatePlayerAnimation()
{
	Sprite* t_sprite = m_pPlayer->GetSprite();
	switch (animState)
	{
	case IDLE:
		t_sprite->SetTexture((GetApp()->m_texPlayerIdle));
		m_animIdle->Update();
		t_sprite->SetTextureRect(m_animIdle->GetCurrentFrame());
		break;
	case RUN_LEFT:
		t_sprite->SetTexture((GetApp()->m_texPlayerRun));
		m_animRun->Update();
		t_sprite->SetTextureRect(m_animRun->GetCurrentFrame());
		//t_sprite->GetSprite()->setScale(m_scale_right);
		break;
	case RUN_RIGHT:
		t_sprite->SetTexture((GetApp()->m_texPlayerRun));
		m_animRun->Update();
		t_sprite->SetTextureRect(m_animRun->GetCurrentFrame());
		break;
	default:
		break;
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
	m_pPlayer->GetSprite()->SetPosition(GetXplayer(), GetYplayer());
	sf::Vector2f a = m_pPlayer->GetSprite()->GetPosition();
	GetManager()->TestCollision(m_pPlayer);
	
}