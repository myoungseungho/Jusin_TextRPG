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
			cout << "소지한 물품이 없습니다" << endl;
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
			cout << "어떤 장비를 착용하시겠습니까? (0번 되돌아가기)" << endl;
			cin >> iInput;

			if (iInput == 0)
				return;

			vector<CItem*>* vec = m_pInventory->GetVecItemInfo();
			m_pInventory->SetItem(((*vec)[iInput - 1]));
		}
	}
}

void CCloset::Release()
{
}
