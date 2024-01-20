#pragma once
#include "stdafx.h"
#include "CItem.h"
class CInventory
{
public:
	CInventory(size_t _iLimit, int _iMoney);
	~CInventory();

public:
	void	Initialize();
	void	Update();
	void	Release();
public:
	int GetMoney() const;
	int SetMoney(int iBuyMoney);
	int AddItem(CItem* _pItem);
private:
	int m_iMoney;
	int m_iInventoryLimit;
	vector<CItem*> m_vecItemP;
};

