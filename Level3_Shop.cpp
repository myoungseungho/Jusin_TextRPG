#include "Level3_Shop.h"

#include "CWeapon.h"
#include "CArmor.h"
Level3_Shop::Level3_Shop(Creature* _creatureP) : CShop(_creatureP) 
{
	
}

Level3_Shop::~Level3_Shop()
{
	Release();
}


void Level3_Shop::Initialize()
{
	CShop::Initialize();
	m_pAttackItemInfo = new AttackItemInfo("고급무기", 3, 900, 9);
	m_pDefensiveItemInfo = new DefensiveItemInfo("고급방어구", 3, 800, 9);
}


void Level3_Shop::Release()
{
	SAFE_DELETE(m_pAttackItemInfo);
	SAFE_DELETE(m_pDefensiveItemInfo);
}
