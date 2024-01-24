#include "Player.h"
#include "stdafx.h"

Player::~Player()
{
	Release();
}

void Player::Input_Data(int _iInput)
{
	switch (_iInput)
	{
	case 1:
		m_Info.sName = "전사";
		m_Info.iHp = 100;
		m_Info.iAttack = 10;
		break;
	case 2:
		m_Info.sName = "마법사";
		m_Info.iHp = 100;
		m_Info.iAttack = 10;
		break;
	case 3:
		m_Info.sName = "도적";
		m_Info.iHp = 100;
		m_Info.iAttack = 10;
		break;
	case 0:
		m_Info.iHp = 100;
		m_Info.iAttack = 10;
	}
}

void Player::Initialize()
{
	Creature::Initialize();

	m_InventoryP = new CInventory(5, 5000);
	m_InventoryP->Initialize();
}

void Player::Release()
{
	SAFE_DELETE(m_InventoryP);
}

void Player::Print_PlayerMoney() const
{
	int iMoney = m_InventoryP->GetMoney();
	cout << "====================" << endl;
	cout << "보유 금액 : " << iMoney << "원" << endl;
}

CInventory* Player::GetInventoryP() const
{
	return m_InventoryP;
}
