#include "Level1_Shop.h"
#include "CArmor.h"
#include "CWeapon.h"
Level1_Shop::Level1_Shop(Creature* _creatureP) : CShop(_creatureP)
{
	
}

Level1_Shop::~Level1_Shop()
{
	Release();
}
void Level1_Shop::Initialize()
{
	CShop::Initialize();

	m_pAttackItemInfo = new AttackItemInfo("�ʱ޹���", 1, 300, 3);
	m_pDefensiveItemInfo = new DefensiveItemInfo("�ʱ޹�", 1, 200, 3);
}

void Level1_Shop::Release()
{
	SAFE_DELETE(m_pAttackItemInfo);
	SAFE_DELETE(m_pDefensiveItemInfo);
}
