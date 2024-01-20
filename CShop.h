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
protected:
	AttackItemInfo* m_attackItemInfo;
	DefensiveItemInfo* m_defensiveItemInfo;
	const Player* m_playerP;
	CInventory* pInventory;
	string sShopName;
};

