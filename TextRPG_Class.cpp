﻿#include "stdafx.h"
#include "CMainGame.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	CMainGame MainGame;

	MainGame.Initialize();
	MainGame.Update();
}

