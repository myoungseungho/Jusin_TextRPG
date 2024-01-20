#include "Inventory.h"

Inventory::Inventory()
{
	m_iMoney = 5000;
	m_iLimit = 0;
}

Inventory::~Inventory()
{
	Release();
}

void Inventory::Initialize()
{
}

void Inventory::Update()
{
}

void Inventory::Release()
{
}
