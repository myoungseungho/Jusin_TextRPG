#include "Creature.h"

Creature::Creature() : m_Info()
{
}

Creature::~Creature()
{
	Release();
}

void Creature::Initialize()
{
}

void Creature::Update()
{
}

void Creature::Release()
{
}



void Creature::Set_Damage(int _iAttack)
{
	m_Info.iHp -= _iAttack;
}

void Creature::Output_Data()
{
	cout << "=====================================" << endl;
	cout << "�̸� : " << m_Info.sName << endl;
	cout << "ü�� : " << m_Info.iHp << '\t' << "���ݷ� : " << m_Info.iAttack << endl;
}

int Creature::Get_Attack()
{
	return m_Info.iAttack;
}

bool Creature::IsDie()
{
	if (m_Info.iHp <= 0)
		return true;
	else
		return false;
}

INFO Creature::GetInfo()
{
	return m_Info;
}


