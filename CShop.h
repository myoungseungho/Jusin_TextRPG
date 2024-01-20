#pragma once
#include "Define.h"
#include "Player.h"

class CShop abstract
{
public:
	CShop(Creature* pPlayer);
	virtual ~CShop();
public:
	virtual void	Initialize();
	void	Update();
	virtual void	Release();
public:
	virtual void Print_Item();
	void Print_PlayerMoney();
public:
	AttackItemInfo* m_attackItemInfo;
	DefensiveItemInfo* m_defensiveItemInfo;
	const Player* m_playerP;
};

