#include "framework.h"

State::State()
{
	m_state = 0;
	m_stateTime = 0.0f;
}

State::~State()
{
}

void State::ToState(int id)
{
	int oldState = m_state;
	OnExit(id);
	m_state = id;
	m_stateTime = GetApp()->GetTime();
	OnEnter(oldState);
}
