#pragma once

#include "Player.h"
#include "Enemy.h"
#include "Mediate.h"
#include "Shop.h"
#include "Level1_Shop.h"
#include "Level2_Shop.h"
#include "Level3_Shop.h"
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
private:
	Creature* m_pPlayer;
	Creature* m_pEnemy;
	Mediate* m_pMediate;
	Shop* m_pShop;
};