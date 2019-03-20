#include "CPlayer.h"



CPlayer::CPlayer(const char*pName)
	:CGameObject(pName,100,100,10,0),m_Title("거리의 방랑자"), m_iExp(0),m_iLev(1),m_iMoney(50000)
{
	m_Itemvector.reserve(1000);

}


CPlayer::~CPlayer()
{
}

void CPlayer::Buy_Item(const char* pName, int money, int attack, int armor)
{
	if (m_iMoney < money)
	{
		Print_BuyFail();
	}
	else
	{
		Print_BuySuc();
		m_iMoney -= money;
		CItem* pNewItem = new CItem(pName, attack, armor);
		m_Itemvector.push_back(pNewItem);
	}


}

void CPlayer::Use_Item(int itemnum)
{
	//m_Itemvector[itemnum+1]->m_iArmor
	if (m_Itemvector[itemnum -1]->isUsed)
	{
		cout << "이미 착용하셨습니다" << endl;
		Sleep(300);
		return;
	}
	m_iArmor += m_Itemvector[itemnum - 1]->m_iArmor;
	m_iAttack += m_Itemvector[itemnum - 1]->m_iAttack;
	m_Itemvector[itemnum - 1]->isUsed = true;
}

void CPlayer::Unuse_Item(int itemnum)
{
	if (!(m_Itemvector[itemnum - 1]->isUsed))
	{
		cout << "사용하지 않으셨습니다." << endl;
		Sleep(300);
		return;
	}
	m_iArmor -= m_Itemvector[itemnum - 1]->m_iArmor;
	m_iAttack -= m_Itemvector[itemnum - 1]->m_iAttack;
	m_Itemvector[itemnum - 1]->isUsed = false;
}

void CPlayer::Print_PlayerInfo(void) const
{
		cout << "-------------------------------------------------------------" << endl;
		cout << "1.이름: " << m_Name		<< "\t"<< "7.공격력: " << m_iAttack << endl;
		cout << "2.칭호: " << m_Title		<< "\t" << "8.방어력: " << m_iArmor<< endl;
		cout << "3.LV: " << m_iLev		    << "\t" << "9.;;: " << m_iArmor << endl;
		cout << "4.HP: " << m_iHp			<< "\t" << "10.;;: " << m_iArmor << endl;
		cout << "5.MP: " << m_iMp			<< "\t" << "11.;;: " << m_iArmor << endl;
		cout << "5.EXP: " << m_iExp			<< "\t" << "12.;;: " << m_iArmor << endl;
		cout << "6.Money: " << m_iMoney		<< "\t" << "13.;;: " << m_iArmor << endl;
		cout << "-------------------------------------------------------------" << endl;
}

void CPlayer::Print_BuyFail(void) const
{
	system("cls");
	cout << endl;
	cout << "돈없으면 썩 꺼져!!" << endl;
	cout << endl;
	Sleep(500);
}

void CPlayer::Print_BuySuc(void) const
{
	system("cls");
	cout << endl;
	cout << "구매해주셔서 감사합니다." << endl;
	cout << endl;
	Sleep(300);
}

void CPlayer::Print_Itemlist(void) const
{
	for (int i=0 ;i<m_Itemvector.size();++i)
	{
		cout << i+1 << ". ";
		m_Itemvector[i]->Print_ItemInfo();
	}
}


