#include "MainGame.h"
#include "stdafx.h"

CMainGame::CMainGame()
{
	m_pPlayer = nullptr;
	m_pEnemy = nullptr;
	m_pMediate = nullptr;
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
		Join_BattleGround();
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
		cout << "������ �����ϼ���(1. ���� 2. ������ 3. ����) : ";
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
void CMainGame::Join_BattleGround()
{
	int iInput(0);

	while (true)
	{
		system("cls");
		m_pPlayer->Output_Data();

		cout << "1. ����� 2. ���� : ";
		cin >> iInput;

		if (iInput == 1)
			break;
		else if (iInput == 2)
			exit(0);
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
		cout << "1. �ʱ� 2. �߱� 3. ��� 4. �� �ܰ� :";
		cin >> iInput;

		if (iInput >= 1 && iInput <= 3)
		{
			if (m_pEnemy == nullptr)
			{
				m_pEnemy = new Enemy;
				m_pEnemy->Initialize();
				m_pEnemy->Input_Data(iInput);

				m_pMediate = new Mediate;
				m_pMediate->Initialize((Player*)m_pPlayer, (Enemy*)m_pEnemy);
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

		cout << "1. ���� 2. ���� : ";
		cin >> iInput;
		if (iInput == 1)
		{
			m_pMediate->Attack();
			int iState = m_pMediate->Die();
			const int PLAYERDIE = 1;
			const int ENEMYDIE = 2;

			switch (iState)
			{
			case PLAYERDIE:
				cout << "�÷��̾� ���" << endl;
				m_pPlayer->Input_Data(0);
				SAFE_DELETE(m_pEnemy);
				system("pause");
				return;
			case ENEMYDIE:
				cout << "�¸�" << endl;
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

