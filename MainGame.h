#pragma once

#include "Player.h"
#include "Enemy.h"
#include "Mediate.h"
class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void	Initialize();	// ��� ������ ���� �����ϴ� �Լ�
	void	Update();		// �� �����Ӹ��� ���ŵǴ� �����͸� �����ϴ� �Լ�
	void	Release();		// �����Ҵ��� �������� �޸� ���� �ڵ带 ����, �����ϴ� �뵵�� �Լ�
	void Select_Job();
	void Join_BattleGround();
	int Select_GroundLevel();
	void Select_AttackAndRun();
private:
	Creature* m_pPlayer;
	Creature* m_pEnemy;
	Mediate* m_pMediate;
};