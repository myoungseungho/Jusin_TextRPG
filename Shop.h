#pragma once
#include "Define.h"

class Shop abstract
{
public:
	Shop();
	virtual ~Shop();
public:
	virtual void	Initialize();
	void	Update();
	virtual void	Release();
public:
	virtual void Print_Item();
public:
	AttackItemInfo* m_attackItemInfo;
	DefensiveItemInfo* m_defensiveItemInfo;
};

