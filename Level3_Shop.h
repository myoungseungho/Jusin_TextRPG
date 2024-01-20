#pragma once
#include "CShop.h"
class Level3_Shop : public CShop
{
public:
	Level3_Shop(Creature* _creatureP) : CShop(_creatureP) {};
public:
	virtual void	Initialize();
	virtual void	Release();
};

