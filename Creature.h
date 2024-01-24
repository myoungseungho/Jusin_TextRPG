#pragma once
#include "Define.h"
class Creature
{
public:
	Creature();
	virtual ~Creature();
public:
	virtual void	Initialize();
	void	Update();
	virtual void	Release();
public:
	void Set_Damage(int _iAttack);
	void	Output_Data();

	int Get_Attack();
	bool IsDie();

	INFO GetInfo();
public:
	virtual void Input_Data(int _iInput) = 0;
protected:
	INFO m_Info;
};

