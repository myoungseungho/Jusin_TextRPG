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
	//����� �� �� ������ 1 ��ȯ
	if (m_iMoney >= iBuyMoney)
	{
		m_iMoney -= iBuyMoney;
		return 1;
	}
	//�������� 0 ��ȯ
	else
		return 0;
}
