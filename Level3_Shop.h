#pragma once
#include "CShop.h"
class Level3_Shop : public CShop
{
public:
	Level3_Shop(Creature* _creatureP);
	~Level3_Shop();
public:
	virtual void	Initialize();
	virtual void	Release();
};

