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
	if (m_pAttackItem == nullptr)
		m_pAttackItem = new CWeapon(1,300,3);

	if (m_pDefensiveItem == nullptr)
		m_pDefensiveItem = new CArmor(1,200,3);

	m_pAttackItem->SetName("초급무기");
	m_pDefensiveItem->SetName("초급방어구");
}

void Level1_Shop::Release()
{
}
