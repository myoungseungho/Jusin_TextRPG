#include "Level3_Shop.h"

void Level3_Shop::Initialize()
{
	CShop::Initialize();
	m_attackItemInfo->sName = "��޹���";
	m_attackItemInfo->iLevel = 3;
	m_attackItemInfo->iAttack = 9;
	m_attackItemInfo->iPrice = 900;
	m_defensiveItemInfo->sName = "��޹�";
	m_defensiveItemInfo->iLevel = 3;
	m_defensiveItemInfo->iDef = 9;
	m_defensiveItemInfo->iPrice = 900;
}


void Level3_Shop::Release()
{
}
