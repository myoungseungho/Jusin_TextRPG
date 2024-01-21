#pragma once

#include "Player.h"
#include "Enemy.h"
#include "CInteraction.h"
#include "CShop.h"
#include "CCloset.h"
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
	void Join_BattleGroundOrShop();
	void SelectShop();
	int Select_GroundLevel();
	void Select_AttackAndRun();
	void 	SelectCloset();
private:
	Creature* m_pPlayer;
	Creature* m_pEnemy;
	CInteraction* m_pInteraction;
	CShop* m_pShop;
	CCloset* m_pCloset;
};