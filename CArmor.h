#pragma once
#include "stdafx.h"
#include "CItem.h"
class CArmor : public CItem
{
public:
	CArmor(int _iLevel, int _iPrice, int _iDef);

	virtual ~CArmor();

public:
	virtual void	Initialize();
	void	Update();
	void	Release();
public:
	int GetDef();
private:
	int m_iDef;
};

