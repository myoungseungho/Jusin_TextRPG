#pragma once
#include "stdafx.h"
#include "Item.h"
class Inventory
{
public:
	Inventory();
	~Inventory();

public:
	void	Initialize();
	void	Update();
	void	Release();
private:
	int m_iMoney;
	int m_iLimit;
	vector<Item*> m_vecItemP;
	/*vector<Item*> m_vecWeaponP;
	vector<Item*> m_vecArmorP;*/
};

