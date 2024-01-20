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

int CInventory::AddItem(CItem* _pItem)
{
	//���� ��á�� ��.
	if (m_vecItemP.size() == m_iInventoryLimit)
		return 0;
	else
	{
		m_vecItemP.push_back(_pItem);
		return 1;
	}
}
