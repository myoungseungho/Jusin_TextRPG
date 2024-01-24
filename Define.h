#pragma once
#include "stdafx.h"
#define		SAFE_DELETE(p)			if(p) { delete p; p = nullptr;}
#define		SAFE_DELETE_ARRAY(p)	if(p) { delete []p; p = nullptr;}

template<typename T>
void Safe_Delete(T& p)
{
	if (p)
	{
		delete p;
		p = nullptr;
	}
};

typedef struct tagInfo
{
	tagInfo()
	{
		sName = "";
		iHp = 0;
		iAttack = 0;
	}
	string sName;
	int iHp, iAttack;
}INFO;

typedef struct ItemInfo
{
	ItemInfo()
	{
		sName = "";
		iLevel = 0;
		iPrice = 0;
	}
	string sName;
	int iLevel, iPrice;
};

typedef struct AttackItemInfo : public ItemInfo
{
	AttackItemInfo()
	{
		iAttack = 0;
	}
	int iAttack;
};

typedef struct DefensiveItemInfo : public ItemInfo
{
	DefensiveItemInfo()
	{
		iDef = 0;
	}
	int iDef;
};
