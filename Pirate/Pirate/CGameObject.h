#pragma once
#include "Library.h"
class CGameObject
{
public:
	CGameObject(const char* pName, int hp, int mp, int Attack, int armor);
	~CGameObject();

protected:
	int m_iHp;
	int m_iMp;
	int m_iAttack;
	int m_iArmor;
	char m_Name[100];

};

