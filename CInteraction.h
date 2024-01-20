#pragma once
#include "Define.h"
#include "Enemy.h"
#include "Player.h"
class CInteraction
{
public:
	CInteraction();
	~CInteraction();
public:
	void Initialize(Player* _pPlayer, Enemy* _pEnemy);
	void Attack();
	int WhoIsDie();
private:
	Creature* m_pPlayer;
	Creature* m_pEnemy;
};