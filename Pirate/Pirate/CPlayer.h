#pragma once
#include "CGameObject.h"
class CPlayer :
	public CGameObject
{


public:
	CPlayer();
	~CPlayer();

	void Print_PlayerInfo(void) const
	{
		cout << "1.ÀÌ¸§:" << m_Name << endl;
		cout << "2.ÄªÈ£"  << m_Title<< endl;
		cout << "3.LV"    << m_iLev << endl;
		cout << "4.HP"    << m_iHp  << endl;
		cout << "5.MP"    << m_iMp  << endl;
		cout << "5.EXP"	  << m_iExp  <<endl;
	}


private:
	char m_Title[100];
	char m_Name[100];
	int m_iExp;
	int m_iLev;

	


};

