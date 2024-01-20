#include "CWeapon.h"

CWeapon::CWeapon(int _iLevel, int _iPrice, int _iAttack) : CItem(_iLevel, _iPrice)
{
	m_iAttack = _iAttack;
};


CWeapon::~CWeapon()
{
}

void CWeapon::Initialize()
{
}

void CWeapon::Update()
{
}

void CWeapon::Release()
{
}

int CWeapon::GetAttack()
{
	return m_iAttack;
}
