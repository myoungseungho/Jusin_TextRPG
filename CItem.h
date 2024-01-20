#pragma once
#include "stdafx.h"
class CItem
{
public:
	CItem(int _iLevel,int _iPrice);
	virtual ~CItem();

public:
	void	Initialize();
	void	Update();
	void	Release();
public:
	void SetName(string name);
	string GetName();
	int GetLevel();
	int GetPrice();
protected:
	string sName;
	int m_iLevel, m_iPrice;
};

