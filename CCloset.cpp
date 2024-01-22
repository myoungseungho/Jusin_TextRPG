#include "CCloset.h"
CCloset::CCloset()
{
	m_pInventory = nullptr;
}

CCloset::~CCloset()
{
}

void CCloset::Initialize(CInventory* _pInventory)
{
	m_pInventory = _pInventory;
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
