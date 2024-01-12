#include "Player.h"
#include "stdafx.h"



void Player::Input_Data(int _iInput)
{
	if (m_pInfo == nullptr)
		m_pInfo = new INFO;

	switch (_iInput)
	{
	case 1:
		m_pInfo->sName = "전사";
		m_pInfo->iHp = 100;
		m_pInfo->iAttack = 10;
		break;
	case 2:
		m_pInfo->sName = "마법사";
		m_pInfo->iHp = 100;
		m_pInfo->iAttack = 10;
		break;
	case 3:
		m_pInfo->sName = "도적";
		m_pInfo->iHp = 100;
		m_pInfo->iAttack = 10;
		break;
	case 0:
		m_pInfo->iHp = 100;
		m_pInfo->iAttack = 10;
	}
}
