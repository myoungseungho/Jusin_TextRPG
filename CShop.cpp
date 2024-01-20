#include "CShop.h"
#include "stdafx.h"
#include "Level1_Shop.h"
#include "Level2_Shop.h"
#include "Level3_Shop.h"
#include "CWeapon.h"
#include "CArmor.h"

CShop::CShop(Creature* _playerP)
{
	m_pAttackItem = nullptr;
	m_pDefensiveItem = nullptr;
	m_playerP = nullptr;
	pInventory = nullptr;

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
		cout << "1. ��� 2. �ȱ�(�̱���) 3. �ǵ��ư��� : ";
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
	SAFE_DELETE(m_pAttackItem);
	SAFE_DELETE(m_pDefensiveItem);
}


void CShop::Print_Item()
{
	if (m_pAttackItem == nullptr || m_pDefensiveItem == nullptr)
		return;

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
	int iComplete(-1);
	while (true)
	{
		system("cls");
		Print_Item();
		cout << endl;
		m_playerP->Print_PlayerMoney();
		cout << endl;
		cout << "������ ��ðڽ��ϱ�? 1. ���� 2. �� 3. �ǵ��ư��� : ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			iComplete = pInventory->SetMoney(m_pAttackItem->GetPrice());
			break;
		case 2:
			iComplete = pInventory->SetMoney(m_pDefensiveItem->GetPrice());
			break;
		case 3:
			return;
		}
		iComplete == 0 ? cout << "�ܾ��� �����մϴ�" << endl : cout << "���������� �����߽��ϴ�" << endl;
		system("pause");
	}

}

void CShop::Sell()
{
}


