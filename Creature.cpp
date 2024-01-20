#include "Creature.h"

Creature::Creature()
{
	m_pInfo = nullptr;
}

Creature::~Creature()
{
	Release();
}

void Creature::Initialize()
{
	m_pInfo = new INFO();
}

void Creature::Update()
{
}

void Creature::Release()
{
	SAFE_DELETE(m_pInfo);
}



void Creature::Set_Damage(int _iAttack)
{
	m_pInfo->iHp -= _iAttack;
}

void Creature::Output_Data()
{
	cout << "=====================================" << endl;
	cout << "이름 : " << m_pInfo->sName << endl;
	cout << "체력 : " << m_pInfo->iHp << '\t' << "공격력 : " << m_pInfo->iAttack << endl;
}

int Creature::Get_Attack()
{
	return m_pInfo->iAttack;
}

bool Creature::IsDie()
{
	if (m_pInfo->iHp <= 0)
		return true;
	else
		return false;
}

INFO* Creature::GetInfo()
{
	if (m_pInfo != nullptr)
		return m_pInfo;
}


