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

	if (m_pAttackItem == nullptr)
		m_pAttackItem = new CWeapon(3, 900, 9);

	if (m_pDefensiveItem == nullptr)
		m_pDefensiveItem = new CArmor(3, 800, 9);

	m_pAttackItem->SetName("��޹���");
	m_pDefensiveItem->SetName("��޹�");
}


void Level3_Shop::Release()
{
}
