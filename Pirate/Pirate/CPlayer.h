#pragma once
#include "CGameObject.h"
#include "CItem.h"

class CPlayer :
	public CGameObject
{


public:
	CPlayer(const char*pName);
	~CPlayer();

	void Buy_Item(const char* pName, int money,int attack, int armor);
	void Use_Item(int itemnum);
	void Unuse_Item(int itemnum);
	void Print_PlayerInfo(void) const;
	void Print_BuyFail(void)const;
	void Print_BuySuc(void)const;
	void Print_Itemlist(void)const;


private:
	vector<CItem*> m_Itemvector;
	char m_Title[100];
	int m_iExp;
	int m_iLev;
	int m_iMoney;



};

