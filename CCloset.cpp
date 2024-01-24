#include "CCloset.h"
#include "Player.h"


CCloset::CCloset(Creature* _pPlayer) : m_pInventory(nullptr), m_pPlayerCopy(nullptr)
{
	m_pPlayerCopy = dynamic_cast<Player*>(_pPlayer);
	m_pInventory = m_pPlayerCopy->GetInventoryP();
}

CCloset::~CCloset()
{
}

void CCloset::Initialize()
{
}

void CCloset::Update()
{
	while (true)
	{
		system("cls");

		if (m_pInventory->GetVecItemInfo()->size() == 0)
		{
			cout << "������ ��ǰ�� �����ϴ�" << endl;
			system("pause");
			return;
		}
		else
		{
			int iInput(0);

			m_pInventory->PrintInventory();
			cout << "==============" << endl << endl;
			m_pInventory->PrintEquipmentStatus();
			cout << endl << endl;
			cout << "� ��� �����Ͻðڽ��ϱ�?" << endl;
			cin >> iInput;

			vector<CItem*>* vec = m_pInventory->GetVecItemInfo();
			m_pInventory->SetItem(((*vec)[iInput - 1]));
			m_pInventory->PrintEquipmentStatus();
			system("pause");
		}
	}
}

void CCloset::Release()
{
}
