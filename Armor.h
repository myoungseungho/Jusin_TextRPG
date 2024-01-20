#pragma once
#include "stdafx.h"
#include "Item.h"
class Armor : public Item
{
public:
	Armor();
	virtual ~Armor();

public:
	void	Initialize();
	void	Update();
	void	Release();
};

