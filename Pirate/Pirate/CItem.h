#pragma once
#include "Library.h"

class CItem
{
	friend class CPlayer;

public:
	CItem(const char* pName,int attack,int armor);
	~CItem();

	void Print_ItemInfo(void)const;
	
protected:
	int m_iAttack;
	int m_iArmor;
	int m_iGrade;
	char m_Name[100];
	bool isUsed;
};

