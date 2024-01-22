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
	AttackItemInfo(string _sName, int _iLevel, int _iPrice, int _iAttack)
	{
		sName = _sName;
		iLevel = _iLevel;
		iPrice = _iPrice;
		iAttack = _iAttack;
	}
	string sName;
	int iLevel, iAttack, iPrice;
};

typedef struct DefensiveItemInfo
{
	DefensiveItemInfo(string _sName, int _iLevel, int _iPrice, int _iDef)
	{
		sName = _sName;
		iLevel = _iLevel;
		iPrice = _iPrice;
		iDef = _iDef;
	}
	string sName;
	int iLevel, iDef, iPrice;
};
