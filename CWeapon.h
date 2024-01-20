#pragma once
#include "stdafx.h"
#include "CItem.h"
class CWeapon : CItem
{
public:
	CWeapon();
	virtual ~CWeapon();

public:
	void	Initialize();
	void	Update();
	void	Release();
};

