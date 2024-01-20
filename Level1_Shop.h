#pragma once
#include "CShop.h"
class Level1_Shop : public CShop
{
public:
	Level1_Shop(Creature* _creatureP) : CShop(_creatureP) {};
public:
	virtual void	Initialize();
	virtual void	Release();
};

