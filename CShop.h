#pragma once
#include "Define.h"
#include "Player.h"
#include "Creature.h"
#include "stdafx.h"
class CShop abstract
{
public:
	CShop(Creature* pPlayer);
	virtual ~CShop();
public:
	virtual void	Initialize();
	void	Update();
	virtual void	Release();
protected:
	virtual void Print_Item();
	void Buy();
	void Sell();
	void PrintInventory();
protected:
	CItem* m_pAttackItem;
	CItem* m_pDefensiveItem;
	const Player* m_playerP;
	CInventory* pInventory;
	string sShopName;
};

