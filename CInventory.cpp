#include "CInventory.h"
#include "stdafx.h"
#include "Define.h"

CInventory::CInventory(size_t _iLimit, int _iMoney) : m_iInventoryLimit(_iLimit), m_iMoney(_iMoney)
{
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
	cout << "현재 아이템 수 : " << m_vecItemP->size() << " / " << m_vecItemP->capacity() << endl;
}


vector<CItem*>* CInventory::GetVecItemInfo() const
{
	return m_vecItemP;
}


