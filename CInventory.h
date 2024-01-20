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
	void SetMoney(int iBuyMoney);
	void AddItem(CItem* _pItem);
	bool CanBuyMoney(int iBuyMoney);
	bool CanAddItem();
	vector<CItem*>* GetVecItemInfo() const;
	void PrintInventory();
private:
	int m_iMoney;
	int m_iInventoryLimit;
	vector<CItem*>* m_vecItemP;
};

