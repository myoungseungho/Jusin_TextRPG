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

	if (m_pAttackItem == nullptr)
		m_pAttackItem = new CWeapon(2, 600, 6);

	if (m_pDefensiveItem == nullptr)
		m_pDefensiveItem = new CArmor(2, 500, 6);

	m_pAttackItem->SetName("중급무기");
	m_pDefensiveItem->SetName("중급방어구");
}

void Level2_Shop::Release()
{
}
