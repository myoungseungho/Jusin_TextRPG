#include "Level2_Shop.h"
#include "CWeapon.h"
#include "CArmor.h"
Level2_Shop::Level2_Shop(Creature* _creatureP) : CShop(_creatureP)
{

}
Level2_Shop::~Level2_Shop()
{
	Release();
}
void Level2_Shop::Initialize()
{
	CShop::Initialize();
	m_pAttackItemInfo = new AttackItemInfo("중급무기", 2, 600, 6);
	m_pDefensiveItemInfo = new DefensiveItemInfo("중급방어구", 2, 500, 6);
}

void Level2_Shop::Release()
{
	
}
