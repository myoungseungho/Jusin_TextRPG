#pragma once
#include "CShop.h"
class Level1_Shop : public CShop
{
public:
	Level1_Shop(Creature* _creatureP);
	virtual ~Level1_Shop();
public:
	virtual void	Initialize();
	virtual void	Release();
};

