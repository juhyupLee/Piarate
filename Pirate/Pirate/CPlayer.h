#pragma once
#include "CGameObject.h"
class CPlayer :
	public CGameObject
{


public:
	CPlayer();
	~CPlayer();

private:
	char m_Title[100];
	char m_Name[100];
	int m_iPassword;
	int m_iExp;

	


};

