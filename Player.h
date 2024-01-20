#pragma once

#include "Define.h"
#include "Creature.h"
class Player : public Creature
{
public:
	virtual void	Input_Data(int _iInput);
};

