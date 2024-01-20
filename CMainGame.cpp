#include "CMainGame.h"
#include "stdafx.h"

CMainGame::CMainGame()
{
	m_pPlayer = nullptr;
	m_pEnemy = nullptr;
	m_pInteraction = nullptr;
	m_pShop = nullptr;
}

CMainGame::~CMainGame()
{
}

int GetRandom()
{
	return rand();
}

void CMainGame::Initialize()
{
	if (!m_pPlayer)
	{
		m_pPlayer = new Player;
		m_pPlayer->Initialize();
	}
}


void CMainGame::Update()
{
	Select_Job();
	while (true)
	{
		Join_BattleGroundOrShop();
		while (true)
		{
			const int PREVIOUS = 1;
			if (Select_GroundLevel() == PREVIOUS)
				break;

			Select_AttackAndRun();
		}
	}
}

void CMainGame::Select_Job()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		cout << "직업을 선택하세요(1. 전사 2. 마법사 3. 도적) : ";
		cin >> iInput;

		if (iInput >= 1 && iInput <= 3)
		{
			if (m_pPlayer != NULL)
				m_pPlayer->Input_Data(iInput);
			break;
		}
		else
			continue;
	}
}
void CMainGame::Join_BattleGroundOrShop()
{
	int iInput(0);

	while (true)
	{
		system("cls");
		m_pPlayer->Output_Data();

		cout << "1. 사냥터 2. 종료 3. 상점 : ";
		cin >> iInput;

		if (iInput == 1)
			break;
		else if (iInput == 2)
			exit(0);
		else if (iInput == 3)
			SelectShop();
		else
			continue;
	}
}

void CMainGame::SelectShop()
{
	int iInput(0);
	enum SHOP_LEVEL
	{
		LEVEL1 = 1,
		LEVEL2,
		LEVEL3
	};

	while (true)
	{
		system("cls");
		cout << "1. 초급상점 2. 중급상점 3. 고급상점 4. 되돌아가기 : ";
		cin >> iInput;
		if (iInput >= 1 && iInput <= 3)
		{
			switch (iInput)
			{
			case SHOP_LEVEL::LEVEL1:
				m_pShop = new Level1_Shop(m_pPlayer);
				break;
			case SHOP_LEVEL::LEVEL2:
				m_pShop = new Level2_Shop(m_pPlayer);
				break;
			case SHOP_LEVEL::LEVEL3:
				m_pShop = new Level3_Shop(m_pPlayer);
				break;
			}
			system("cls");
			m_pShop->Initialize();
			m_pShop->Update();
			system("cls");
		}
		else if (iInput == 4)
			break;
		else
			continue;
	}
}

int CMainGame::Select_GroundLevel()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		m_pPlayer->Output_Data();
		cout << "1. 초급 2. 중급 3. 고급 4. 전 단계 :";
		cin >> iInput;

		if (iInput >= 1 && iInput <= 3)
		{
			if (m_pEnemy == nullptr)
			{
				m_pEnemy = new Enemy;
				m_pEnemy->Initialize();
				m_pEnemy->Input_Data(iInput);

				m_pInteraction = new CInteraction;
				m_pInteraction->Initialize(dynamic_cast<Player*>(m_pPlayer), dynamic_cast<Enemy*>(m_pEnemy));
				return 0;
			}
		}
		else if (iInput == 4)
			return 1;
		else
			continue;
	}
}

void CMainGame::Select_AttackAndRun()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		m_pPlayer->Output_Data();
		m_pEnemy->Output_Data();

		cout << "1. 공격 2. 도망 : ";
		cin >> iInput;
		if (iInput == 1)
		{
			m_pInteraction->Attack();
			int iState = m_pInteraction->WhoIsDie();
			const int PLAYERDIE = 1;
			const int ENEMYDIE = 2;

			switch (iState)
			{
			case PLAYERDIE:
				cout << "플레이어 사망" << endl;
				m_pPlayer->Input_Data(0);
				SAFE_DELETE(m_pEnemy);
				system("pause");
				return;
			case ENEMYDIE:
				cout << "승리" << endl;
				SAFE_DELETE(m_pEnemy);
				system("pause");
				return;
			case 0:
				continue;
			}
		}
		else if (iInput == 2)
		{
			SAFE_DELETE(m_pEnemy);
			return;
		}
		else
			continue;
	}
}

void CMainGame::Release()
{
}

