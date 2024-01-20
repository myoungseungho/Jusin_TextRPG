#include "CShop.h"
#include "stdafx.h"
CShop::CShop(Creature* _playerP)
{
	m_attackItemInfo = nullptr;
	m_defensiveItemInfo = nullptr;
	m_playerP = nullptr;

	if (m_playerP == nullptr)
	{
		Player* pPlayer = dynamic_cast<Player*>(_playerP);
		m_playerP = pPlayer;
	}
}

CShop::~CShop()
{
	Release();
}

void CShop::Initialize()
{
	if (m_attackItemInfo == nullptr)
		m_attackItemInfo = new AttackItemInfo;
	if (m_defensiveItemInfo == nullptr)
		m_defensiveItemInfo = new DefensiveItemInfo;
}

void CShop::Update()
{
	while (true)
	{
		Print_Item();
		Print_PlayerMoney();
		cout << endl << endl;
		cout << "1. 사기(미구현) 2. 팔기(미구현)" << endl;;
		system("pause");
		break;
	}
}

void CShop::Release()
{
	SAFE_DELETE(m_attackItemInfo);
	SAFE_DELETE(m_defensiveItemInfo);
}

void CShop::Print_Item()
{
	if (m_attackItemInfo == nullptr || m_defensiveItemInfo == nullptr)
		return;

	cout << m_attackItemInfo->sName << endl;
	cout << "가격 : " << m_attackItemInfo->iPrice << endl;
	cout << "아이템 레벨 : " << m_attackItemInfo->iLevel << endl;
	cout << "공격력 : " << m_attackItemInfo->iAttack << endl << endl;
	cout << "====================" << endl;
	cout << m_defensiveItemInfo->sName << endl;
	cout << "가격 : " << m_defensiveItemInfo->iPrice << endl;
	cout << "아이템 레벨 : " << m_defensiveItemInfo->iLevel << endl;
	cout << "방어력 : " << m_defensiveItemInfo->iDef << endl << endl;
}

void CShop::Print_PlayerMoney()
{
	int iMoney = m_playerP->GetInventoryP()->GetMoney();
	cout << "====================" << endl;
	cout << "보유 금액 : " << iMoney << "원" << endl;
}


