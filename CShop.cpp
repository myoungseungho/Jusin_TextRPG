#include "CShop.h"
#include "stdafx.h"
#include "Level1_Shop.h"
#include "Level2_Shop.h"
#include "Level3_Shop.h"
#include "CWeapon.h"
#include "CArmor.h"

CShop::CShop(Creature* _playerP)
{
	m_playerP = nullptr;
	pInventory = nullptr;
	m_pAttackItemInfo = nullptr;
	m_pDefensiveItemInfo = nullptr;

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
		cout << "1. 사기 2. 팔기 3. 되돌아가기 : ";
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
}


void CShop::Print_Item()
{
	cout << m_pAttackItem->GetName() << endl;
	cout << "가격 : " << m_pAttackItem->GetPrice() << endl;
	cout << "아이템 레벨 : " << m_pAttackItem->GetLevel() << endl;
	cout << "공격력 : " << dynamic_cast<CWeapon*>(m_pAttackItem)->GetAttack() << endl << endl;
	cout << "====================" << endl;
	cout << m_pDefensiveItem->GetName() << endl;
	cout << "가격 : " << m_pDefensiveItem->GetPrice() << endl;
	cout << "아이템 레벨 : " << m_pDefensiveItem->GetLevel() << endl;
	cout << "방어력 : " << dynamic_cast<CArmor*>(m_pDefensiveItem)->GetDef() << endl << endl;
}

void CShop::Buy()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		int iPrice;
		bool bIsCanBuyMoney;
		bool bIsCanAddItem;

		Print_Item();
		cout << endl;
		m_playerP->Print_PlayerMoney();
		cout << endl;
		cout << "무엇을 사시겠습니까? 1. 무기 2. 방어구 3. 되돌아가기 : ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			iPrice = m_pAttackItem->GetPrice();
			bIsCanBuyMoney = pInventory->CanBuyMoney(iPrice);
			bIsCanAddItem = pInventory->CanAddItem();

			if (!bIsCanBuyMoney)
				cout << "잔액이 부족합니다" << endl;
			else if (!bIsCanAddItem)
				cout << "인벤토리가 꽉찼습니다" << endl;
			else if (bIsCanAddItem && bIsCanBuyMoney)
			{
				cout << "성공적으로 구매했습니다" << endl;
				pInventory->SetMoney(iPrice);
				pInventory->AddItem(m_pAttackItem);
			}
			pInventory->PrintInventory();
			break;
		case 2:
			iPrice = m_pDefensiveItem->GetPrice();
			bIsCanBuyMoney = pInventory->CanBuyMoney(iPrice);
			bIsCanAddItem = pInventory->CanAddItem();

			if (!bIsCanBuyMoney)
				cout << "잔액이 부족합니다" << endl;
			else if (!bIsCanAddItem)
				cout << "인벤토리가 꽉찼습니다" << endl;
			else if (bIsCanBuyMoney && bIsCanAddItem)
			{
				cout << "성공적으로 구매했습니다" << endl;
				pInventory->SetMoney(iPrice);
				pInventory->AddItem(m_pDefensiveItem);
			}
			pInventory->PrintInventory();
			break;
		case 3:
			return;
		}
		system("pause");
	}

}

void CShop::Sell()
{
	int iCount(0);
	while (true)
	{
		system("cls");

		int ivecSize = pInventory->GetVecItemInfo()->size();
		if (ivecSize <= 0)
		{
			cout << "가지고 있는 장비가 없습니다" << endl;
			system("pause");
			return;
		}

		cout << "몇번 물건을 파시겠습니까 ? (0번 되돌아가기)" << endl;
		pInventory->PrintInventory();
		cout << endl << "=================" << endl;
		cout << "현재 돈 : " << pInventory->GetMoney() << endl;
		cout << "=================" << endl;

		cin >> iCount;

		if (iCount > ivecSize || iCount < 0)
		{
			cout << "해당 장비는 없습니다" << endl;
			system("pause");
			continue;
		}
		else if (iCount == 0)
			return;
		else
		{
			//인벤토리에서 지웠지만 Shop에서 생성한 아이템도 지워야 함.
			vector<CItem*>* vec = pInventory->GetVecItemInfo();
			vector<CItem*>::iterator iter = vec->begin();
			iter = iter + iCount - 1;
			pInventory->SetMoney(-((*vec)[iCount - 1]->GetPrice()));
			iter = vec->erase(iter);

			pInventory->PrintInventory();
			cout << "=================" << endl;
			cout << "현재 돈 : " << pInventory->GetMoney() << endl;
			system("pause");
			continue;
		}
	}
}



