#include "CItem.h"

CItem::CItem(int _iLevel, int _iPrice)
{
	sName = "";
	m_iLevel = _iLevel;
	m_iPrice = _iPrice;
}

CItem::~CItem()
{
	Release();
}

void CItem::Initialize()
{
}

void CItem::Update()
{
}

void CItem::Release()
{
}

void CItem::SetName(string name)
{
	sName = name;
}

string CItem::GetName()
{
	return sName;
}

int CItem::GetLevel()
{
	return m_iLevel;
}

int CItem::GetPrice()
{
	return m_iPrice;
}
