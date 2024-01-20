#include "CShop.h"
#include "stdafx.h"
#include "Level1_Shop.h"
#include "Level2_Shop.h"
#include "Level3_Shop.h"
CShop::CShop(Creature* _playerP)
{
	m_attackItemInfo = nullptr;
	m_defensiveItemInfo = nullptr;
	m_playerP = nullptr;
	pInventory = nullptr;
	sShopName = "";

	if (m_playerP == nullptr)
	{
		Player* pPlayer = dynamic_cast<Player*>(_playerP);
		m_playerP = pPlayer;
		pInventory = m_playerP->GetInventoryP();
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

	if (typeid(*this) == typeid(Level1_Shop))
	{
		sShopName = "초급 상점";
	}
	else if (typeid(*this) == typeid(Level2_Shop))
	{
		sShopName = "중급 상점";
	}
	else if (typeid(*this) == typeid(Level3_Shop))
	{
		sShopName = "고급 상점";
	}
}

void CShop::Update()
{
	while (true)
	{
		system("cls");
		cout << "===============================" << sShopName << "========================" << endl << endl << endl;
		Print_Item();
		m_playerP->Print_PlayerMoney();

		cout << endl << endl;
		cout << "1. 사기 2. 팔기(미구현) 3. 되돌아가기 : ";
		int iInput(0);
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			Buy();
			break;
		case 2:
			Sell();
			break;
		case 3:
			return;
		}
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

void CShop::Buy()
{
	int iInput(0);
	int iComplete(-1);
	while (true)
	{
		system("cls");
		Print_Item();
		cout << endl;
		m_playerP->Print_PlayerMoney();
		cout << endl;
		cout << "무엇을 사시겠습니까? 1. 무기 2. 방어구 3. 되돌아가기 : ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			iComplete = pInventory->SetMoney(m_attackItemInfo->iPrice);
			break;
		case 2:
			iComplete = pInventory->SetMoney(m_defensiveItemInfo->iPrice);
			break;
		case 3:
			return;
		}
		iComplete == 0 ? cout << "잔액이 부족합니다" << endl : cout << "성공적으로 구매했습니다" << endl;
		system("pause");
	}

}

void CShop::Sell()
{
}


