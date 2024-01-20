#include "CInteraction.h"

CInteraction::CInteraction()
{
	m_pPlayer = nullptr;
	m_pEnemy = nullptr;
}

CInteraction::~CInteraction()
{
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pEnemy);
}

void CInteraction::Initialize(Player* _pPlayer, Enemy* _pEnemy)
{
	if (m_pPlayer == nullptr)
		m_pPlayer = _pPlayer;

	if (m_pEnemy == nullptr)
		m_pEnemy = _pEnemy;
}

void CInteraction::Attack()
{
	INFO* playerInfo = m_pPlayer->GetInfo();
	INFO* enemyInfo = m_pEnemy->GetInfo();

	m_pPlayer->Set_Damage(m_pEnemy->Get_Attack());
	m_pEnemy->Set_Damage(m_pPlayer->Get_Attack());
}

int CInteraction::WhoIsDie()
{
	bool bIsPlayerDie = m_pPlayer->IsDie();
	bool bIsEnemyDie = m_pEnemy->IsDie();

	if (bIsPlayerDie)
		return 1;
	else if (bIsEnemyDie)
		return 2;
	else
		return 0;
}
