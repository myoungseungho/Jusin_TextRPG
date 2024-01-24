#pragma once
#include "stdafx.h"
#include "CInventory.h"
#include "Player.h"
class CCloset
{
public:
	CCloset(Creature* _pPlayer);
	~CCloset();
public:
	void Initialize();
	void	Update();
	void	Release();
private:
	Player* m_pPlayerCopy;
	CInventory* m_pInventory;
};

