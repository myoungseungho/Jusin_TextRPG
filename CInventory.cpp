#include "CInventory.h"
#include "stdafx.h"

CInventory::CInventory(size_t _iLimit, int _iMoney) : m_iInventoryLimit(_iLimit), m_iMoney(_iMoney)
{
	m_vecItemP.reserve(_iLimit);
}

CInventory::~CInventory()
{
	Release();
}

void CInventory::Initialize()
{
}

void CInventory::Update()
{
}

void CInventory::Release()
{
}

int CInventory::GetMoney() const
{
	return m_iMoney;
}

int CInventory::SetMoney(int iBuyMoney)
{
	//제대로 살 수 있으면 1 반환
	if (m_iMoney >= iBuyMoney)
	{
		m_iMoney -= iBuyMoney;
		return 1;
	}
	//돈없으면 0 반환
	else
		return 0;
}
