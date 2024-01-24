#include "Enemy.h"
#include "stdafx.h"

void Enemy::Input_Data(int _iInput)
{
	switch (_iInput)
	{
	case 1:
		m_Info.sName = "초급";
		m_Info.iHp = 30;
		m_Info.iAttack = 3;
		break;
	case 2:
		m_Info.sName = "중급";
		m_Info.iHp = 60;
		m_Info.iAttack = 6;
		break;
	case 3:
		m_Info.sName = "고급";
		m_Info.iHp = 90;
		m_Info.iAttack = 9;
		break;
	}
}
