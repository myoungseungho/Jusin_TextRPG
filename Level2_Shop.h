#pragma once
#include "CShop.h"
class Level2_Shop :public CShop
{
public:
	Level2_Shop(Creature* _creatureP);
	~Level2_Shop();
public:
	virtual void	Initialize();
	virtual void	Release();
};

