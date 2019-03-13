#pragma once
#include "Library.h"
class CGameObject
{
public:
	CGameObject();
	~CGameObject();

protected:
	int m_iHp;
	int m_iMp;
	char m_Name[100];

};

