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
		cout << "1. ���(�̱���) 2. �ȱ�(�̱���)" << endl;;
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
	cout << "���� : " << m_attackItemInfo->iPrice << endl;
	cout << "������ ���� : " << m_attackItemInfo->iLevel << endl;
	cout << "���ݷ� : " << m_attackItemInfo->iAttack << endl << endl;
	cout << "====================" << endl;
	cout << m_defensiveItemInfo->sName << endl;
	cout << "���� : " << m_defensiveItemInfo->iPrice << endl;
	cout << "������ ���� : " << m_defensiveItemInfo->iLevel << endl;
	cout << "���� : " << m_defensiveItemInfo->iDef << endl << endl;
}

void CShop::Print_PlayerMoney()
{
	int iMoney = m_playerP->GetInventoryP()->GetMoney();
	cout << "====================" << endl;
	cout << "���� �ݾ� : " << iMoney << "��" << endl;
}


