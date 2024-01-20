#include "CArmor.h"


CArmor::CArmor(int _iLevel, int _iPrice, int _iDef) : CItem(_iLevel, _iPrice)
{
	m_iDef = _iDef;
};


CArmor::~CArmor()
{
}

void CArmor::Initialize()
{

}

void CArmor::Update()
{
}

void CArmor::Release()
{
}

int CArmor::GetDef()
{
	return m_iDef;
}
