#include "framework.h"

Player::Player()
{
	//m_speed = 35.0f;
	animState = IDLE;
	m_scale_left = { -1,1 };
	m_scale_right = { 1,-1 };
	
}

Player::~Player()
{
}

void Player::Init()
{
	m_pPlayer = new Entity;
	m_pPlayer->SetPlayer();
	m_pPlayer->SetPosition(1000,200);
	
	m_pPlayer->SetTexture(GetApp()->m_texPlayerIdle);
	m_pPlayer->GetSprite()->SetScale(3.f,3.f);
	
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
		m_pPlayer->SetVelocityY(-250.f);
		this->animState = JUMPING;
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
	if (!GetManager()->TestCollision(m_pPlayer))
	{
		return;
	};
}