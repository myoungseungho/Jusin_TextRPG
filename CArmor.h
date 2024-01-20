#pragma once
#include "stdafx.h"
#include "CItem.h"
class CArmor : public CItem
{
public:
	CArmor();
	virtual ~CArmor();

public:
	void	Initialize();
	void	Update();
	void	Release();
};

