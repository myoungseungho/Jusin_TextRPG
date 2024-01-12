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