#pragma once
class State
{
public:
	State();
	virtual ~State();

	void ToState(int id);

	virtual void OnEnter(int oldState) = 0;
	virtual void OnExecute() = 0;
	virtual void OnExit(int newState) = 0;

protected:
	int m_state;
	float m_stateTime;

};

