#include "Level1_Shop.h"

void Level1_Shop::Initialize()
{
	Shop::Initialize();
	m_attackItemInfo->sName = "�ʱ޹���";
	m_attackItemInfo->iLevel = 1;
	m_attackItemInfo->iAttack = 3;
	m_attackItemInfo->iPrice = 300;
	m_defensiveItemInfo->sName = "�ʱ޹�";
	m_defensiveItemInfo->iLevel = 1;
	m_defensiveItemInfo->iDef = 3;
	m_defensiveItemInfo->iPrice = 300;
}

void Level1_Shop::Release()
{
}
