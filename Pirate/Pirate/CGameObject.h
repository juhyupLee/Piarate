#pragma once
#include "Library.h"
class CGameObject
{
public:
	CGameObject(const char* pName,int hp, int mp);
	~CGameObject();

protected:
	int m_iHp;
	int m_iMp;
	char m_Name[100];

};

