#include "Level2_Shop.h"

void Level2_Shop::Initialize()
{
	CShop::Initialize();
	m_attackItemInfo->sName = "�߱޹���";
	m_attackItemInfo->iLevel = 2;
	m_attackItemInfo->iAttack = 6;
	m_attackItemInfo->iPrice = 600;
	m_defensiveItemInfo->sName = "�߱޹�";
	m_defensiveItemInfo->iLevel = 2;
	m_defensiveItemInfo->iDef = 6;
	m_defensiveItemInfo->iPrice = 600;
}

void Level2_Shop::Release()
{
}
