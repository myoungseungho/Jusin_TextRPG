#include "Enemy.h"
#include "stdafx.h"

void Enemy::Input_Data(int _iInput)
{
	if (m_pInfo == nullptr)
		m_pInfo = new INFO;

	switch (_iInput)
	{
	case 1:
		m_pInfo->sName = "초급";
		m_pInfo->iHp = 30;
		m_pInfo->iAttack = 3;
		break;
	case 2:
		m_pInfo->sName = "중급";
		m_pInfo->iHp = 60;
		m_pInfo->iAttack = 6;
		break;
	case 3:
		m_pInfo->sName = "고급";
		m_pInfo->iHp = 90;
		m_pInfo->iAttack = 9;
		break;
	}
}
