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
	void SetMoney(int iBuyMoney);
	void AddItem(CItem* _pItem);
	void RemoveItem(CItem* _pItem);
	void PrintInventory();
	void PrintEquipmentStatus();
	void SetItem(CItem* _pItem);
	int GetMoney() const;

	bool CanBuyMoney(int iBuyMoney);
	bool CanAddItem();

	vector<CItem*>* GetVecItemInfo() const;
private:
	int m_iMoney;
	int m_iInventoryLimit;
	
	vector<CItem*>* m_vecItemP;
	CItem* m_currentWeapon;
	CItem* m_currentArmor;
};

