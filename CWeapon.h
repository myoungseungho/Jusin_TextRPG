#pragma once
#include "stdafx.h"
#include "CItem.h"
class CWeapon : public CItem
{
public:
	CWeapon(int _iLevel, int _iPrice, int _iAttack);
	virtual ~CWeapon();

public:
	void	Initialize();
	void	Update();
	void	Release();
public:
	int GetAttack();
private:
	int m_iAttack;
};

