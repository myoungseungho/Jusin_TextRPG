#include "Shop.h"
#include "stdafx.h"
Shop::Shop()
{
	m_attackItemInfo = nullptr;
	m_defensiveItemInfo = nullptr;
}

Shop::~Shop()
{
	SAFE_DELETE(m_attackItemInfo);
	SAFE_DELETE(m_defensiveItemInfo);
	Release();
}

void Shop::Initialize()
{
	if (m_attackItemInfo == nullptr)
		m_attackItemInfo = new AttackItemInfo;
	if (m_defensiveItemInfo == nullptr)
		m_defensiveItemInfo = new DefensiveItemInfo;
}

void Shop::Update()
{
	while (true)
	{
		Print_Item();

		cout << endl << endl;
		cout << "1. ���(�̱���) 2. �ȱ�(�̱���)" << endl;;
		system("pause");
		break;
	}
}

void Shop::Release()
{
}

void Shop::Print_Item()
{
	if (m_attackItemInfo == nullptr || m_defensiveItemInfo == nullptr)
		return;

	cout << m_attackItemInfo->sName << endl;
	cout << "���� : " << m_attackItemInfo->iPrice << endl;
	cout << "������ ���� : " << m_attackItemInfo->iLevel << endl;
	cout << "���ݷ� : " << m_attackItemInfo->iAttack << endl << endl;

	cout << m_defensiveItemInfo->sName << endl;
	cout << "���� : " << m_defensiveItemInfo->iPrice << endl;
	cout << "������ ���� : " << m_defensiveItemInfo->iLevel << endl;
	cout << "���� : " << m_defensiveItemInfo->iDef << endl << endl;
}


