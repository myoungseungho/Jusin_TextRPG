#pragma once
#include "stdafx.h"
#define		SAFE_DELETE(p)			if(p) { delete p; p = nullptr;}
#define		SAFE_DELETE_ARRAY(p)	if(p) { delete []p; p = nullptr;}

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

typedef struct AttackItemInfo
{
	AttackItemInfo()
	{
		sName = "";
		iLevel = 0;
		iAttack = 0;
		iPrice = 0;
	}
	string sName;
	int iLevel, iAttack, iPrice;
};

typedef struct DefensiveItemInfo
{
	DefensiveItemInfo()
	{
		sName = "";
		iLevel = 0;
		iDef = 0;
		iPrice = 0;
	}
	string sName;
	int iLevel, iDef, iPrice;
};

typedef struct PlayerItemInfo
{
	PlayerItemInfo()
	{

	}
};