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
		sShopName = "�ʱ� ����";
	}
	else if (typeid(*this) == typeid(Level2_Shop))
	{
		sShopName = "�߱� ����";
	}
	else if (typeid(*this) == typeid(Level3_Shop))
	{
		sShopName = "��� ����";
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
		cout << "1. ��� 2. �ȱ� 3. �ǵ��ư��� : ";
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
	cout << "���� : " << m_pAttackItem->GetPrice() << endl;
	cout << "������ ���� : " << m_pAttackItem->GetLevel() << endl;
	cout << "���ݷ� : " << dynamic_cast<CWeapon*>(m_pAttackItem)->GetAttack() << endl << endl;
	cout << "====================" << endl;
	cout << m_pDefensiveItem->GetName() << endl;
	cout << "���� : " << m_pDefensiveItem->GetPrice() << endl;
	cout << "������ ���� : " << m_pDefensiveItem->GetLevel() << endl;
	cout << "���� : " << dynamic_cast<CArmor*>(m_pDefensiveItem)->GetDef() << endl << endl;
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
		cout << "������ ��ðڽ��ϱ�? 1. ���� 2. �� 3. �ǵ��ư��� : ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			iPrice = m_pAttackItem->GetPrice();
			bIsCanBuyMoney = pInventory->CanBuyMoney(iPrice);
			bIsCanAddItem = pInventory->CanAddItem();

			if (!bIsCanBuyMoney)
				cout << "�ܾ��� �����մϴ�" << endl;
			else if (!bIsCanAddItem)
				cout << "�κ��丮�� ��á���ϴ�" << endl;
			else if (bIsCanAddItem && bIsCanBuyMoney)
			{
				cout << "���������� �����߽��ϴ�" << endl;
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
				cout << "�ܾ��� �����մϴ�" << endl;
			else if (!bIsCanAddItem)
				cout << "�κ��丮�� ��á���ϴ�" << endl;
			else if (bIsCanBuyMoney && bIsCanAddItem)
			{
				cout << "���������� �����߽��ϴ�" << endl;
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
			cout << "������ �ִ� ��� �����ϴ�" << endl;
			system("pause");
			return;
		}

		cout << "��� ������ �Ľðڽ��ϱ� ? (0�� �ǵ��ư���)" << endl;
		pInventory->PrintInventory();
		cout << endl << "=================" << endl;
		cout << "���� �� : " << pInventory->GetMoney() << endl;
		cout << "=================" << endl;

		cin >> iCount;

		if (iCount > ivecSize || iCount < 0)
		{
			cout << "�ش� ���� �����ϴ�" << endl;
			system("pause");
			continue;
		}
		else if (iCount == 0)
			return;
		else
		{
			//�κ��丮���� �������� Shop���� ������ �����۵� ������ ��.
			vector<CItem*>* vec = pInventory->GetVecItemInfo();
			vector<CItem*>::iterator iter = vec->begin();
			iter = iter + iCount - 1;
			pInventory->SetMoney(-((*vec)[iCount - 1]->GetPrice()));
			iter = vec->erase(iter);

			pInventory->PrintInventory();
			cout << "=================" << endl;
			cout << "���� �� : " << pInventory->GetMoney() << endl;
			system("pause");
			continue;
		}
	}
}



