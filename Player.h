#pragma once

#include "Define.h"
#include "Creature.h"
#include "CInventory.h"
class Player : public Creature
{
public:
	virtual ~Player();
public:
	virtual void	Input_Data(int _iInput);
public:
	virtual void Initialize();
	virtual void Release();
public:
	CInventory* GetInventoryP() const;
private:
	CInventory* m_InventoryP;
};

