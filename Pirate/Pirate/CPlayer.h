#pragma once
#include "CGameObject.h"
class CPlayer :
	public CGameObject
{


public:
	CPlayer(const char*pName);
	~CPlayer();

	void Print_PlayerInfo(void) const
	{
		cout << "---------------------------" << endl;
		cout << "1.�̸�: " << m_Name << endl;
		cout << "2.Īȣ: "  << m_Title<< endl;
		cout << "3.LV: "    << m_iLev << endl;
		cout << "4.HP: "    << m_iHp  << endl;
		cout << "5.MP: "    << m_iMp  << endl;
		cout << "5.EXP: "	  << m_iExp  <<endl;
		cout << "---------------------------" << endl;
	}


private:
	char m_Title[100];
	int m_iExp;
	int m_iLev;

	


};

