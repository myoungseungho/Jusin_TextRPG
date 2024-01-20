#pragma once
#include "stdafx.h"
#include "Item.h"
class Weapon : Item
{
public:
	Weapon();
	virtual ~Weapon();

public:
	void	Initialize();
	void	Update();
	void	Release();
};

