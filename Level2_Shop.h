#pragma once
#include "CShop.h"
class Level2_Shop :public CShop
{
public:
	Level2_Shop(Creature* _creatureP) : CShop(_creatureP) {};
public:
	virtual void	Initialize();
	virtual void	Release();
};

