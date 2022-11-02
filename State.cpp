#include "framework.h"

State::State()
{
	
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
