#include "CInventory.h"
#include "stdafx.h"
#include "Define.h"
#include "CWeapon.h"
#include "CArmor.h"
CInventory::CInventory(size_t _iLimit, int _iMoney) : m_iInventoryLimit(_iLimit), m_iMoney(_iMoney)
{
	m_vecItemP = nullptr;
	m_currentWeapon = nullptr;
	m_currentArmor = nullptr;
}

CInventory::~CInventory()
{
	Release();
}

void CInventory::Initialize()
{
	m_vecItemP = new vector<CItem*>;
	m_vecItemP->reserve(m_iInventoryLimit);
}

void CInventory::Update()
{
}

void CInventory::Release()
{
	SAFE_DELETE(m_vecItemP);
}

int CInventory::GetMoney() const
{
	return m_iMoney;
}

void CInventory::SetMoney(int iBuyMoney)
{
	m_iMoney -= iBuyMoney;
}

void CInventory::AddItem(CItem* _pItem)
{
	m_vecItemP->push_back(_pItem);
}

bool CInventory::CanBuyMoney(int iBuyMoney)
{
	if (m_iMoney >= iBuyMoney)
		return true;
	else
		return false;
}

bool CInventory::CanAddItem()
{
	if (m_vecItemP->size() == m_iInventoryLimit)
		return false;
	else
		return true;
}

void CInventory::PrintInventory()
{
	int iCount(1);
	for (vector<CItem*>::iterator iter = m_vecItemP->begin(); iter != m_vecItemP->end(); ++iter)
	{
		cout << iCount << ". " << (*iter)->GetName() << endl;
		iCount++;
	}

	cout << "===================" << endl;
	cout << "���� ������ �� : " << m_vecItemP->size() << " / " << m_vecItemP->capacity() << endl;
}

void CInventory::PrintEquipmentStatus()
{
	cout << "���� ������ ���� : " << ((m_currentWeapon == nullptr) ? "������ ���� ����" : m_currentWeapon->GetName()) << endl;
	cout << "���� ���� �� : " << ((m_currentArmor == nullptr) ? "������ �� ����" : m_currentArmor->GetName()) << endl;
}

void CInventory::SetItem(CItem* _pItem)
{
	if (typeid(*_pItem) == typeid(CWeapon))
		m_currentWeapon = _pItem;
	else if (typeid(*_pItem) == typeid(CArmor))
		m_currentArmor = _pItem;
}


vector<CItem*>* CInventory::GetVecItemInfo() const
{
	return m_vecItemP;
}


