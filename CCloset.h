#pragma once
#include "stdafx.h"
#include "CInventory.h"
class CCloset
{
public:
	CCloset();
	~CCloset();
public:
	void Initialize(CInventory* _pInventory);
	void	Update();
	void	Release();
private:
	CInventory* m_pInventory;
};

