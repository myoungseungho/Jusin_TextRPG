#pragma once
#include "Define.h"
#include "Enemy.h"
#include "Player.h"
class Mediate
{
public:
	Mediate();
	~Mediate();
public:
	void Initialize(Player* _pPlayer, Enemy* _pEnemy);
	void Attack();
	int Die();
private:
	Creature* m_pPlayer;
	Creature* m_pEnemy;
};