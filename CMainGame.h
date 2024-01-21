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
	void	Initialize();	// 멤버 변수의 값을 세팅하는 함수
	void	Update();		// 매 프레임마다 갱신되는 데이터를 관리하는 함수
	void	Release();		// 동적할당한 포인터의 메모리 해제 코드를 보관, 관리하는 용도의 함수
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