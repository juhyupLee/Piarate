#pragma once
#include "Library.h"
#include "CPlayer.h"
#include "CKeynDraw.h"
class CMainScene
{
public:
	CMainScene();
	~CMainScene();

public:
	void Print_Main() const
	{
		m_pPlayer->Print_PlayerInfo();
		cout << "1.상점" << endl;
		cout << "2.착용 아이템" << endl;
		cout << "3.선박" << endl;
		cout << "4.출항" << endl;
		cout << "5.나가기" << endl;
	}
	void Print_Store()const
	{
		m_pPlayer->Print_PlayerInfo();
		cout << "■■■■■■■■■■■■■■■■" << endl;
		cout << "■           EXIT             ■" << endl;
		cout << "■            ㉧              ■" << endl;
		cout << "■      ▩           ▩       ■" << endl;
		cout << "■   (Weapon)     (Protect)   ■" << endl;
		cout << "■                            ■" << endl;
		cout << "■                            ■" << endl;
		cout << "■      ▩           ▩       ■" << endl;
		cout << "■    (Ship)      (Potion)    ■" << endl;
		cout << "■                            ■" << endl;
		cout << "■■■■■■■■■■■■■■■■" << endl;
	}
	void Print_Weapon()const
	{
		m_pPlayer->Print_PlayerInfo();
		cout << "\"어서오시게 한번 골라봐\"                   " << endl;
		cout << "                                             " << endl;
		cout << "† 시미터     [공력력+5,강화0](500coin)       " << endl;
		cout << "† 카타나     [공격력+20,강화0](6900coin)     " << endl;
		cout << "† 하이랜드   [공격력+30 강화 0](10,000coin)  " << endl;
		cout << "┒  38구경     [공격력+40 강화 0](50,000       " << endl;
		cout << "나가기" << endl;
	}

	void Print_Inventory()const
	{
		
		system("cls");
		m_pPlayer->Print_PlayerInfo();
		m_pPlayer->Print_Itemlist();
		cout << "아이템을 고르십시오:(-1번 나가기)";

	}
	void Print_Item() const
	{
		cout << "1.착용" << endl;
		cout << "2.해제" << endl;
		cout << "3.강화" << endl;
	}

public:
	void Main_Running()
	{
		Print_Main();
		MainMenu Select ;

		while (true)
		{
			Select = m_pKeynDraw->Draw_Main(*this);
			switch (Select)
			{
			case STORE:
				Store_Running();
				break;
			case INVENTORY:
				Inventory_Running();
				break;
			case SHIP_MAINTAIN:
				break;
			case DEPARTURE:
				break;
			case EXIT:
				return;
				break;
			}
		}
		
	}

	void Store_Running()
	{
		system("cls");
		Print_Store();
		StoreMenu Select;

		while (true)
		{
			Select = m_pKeynDraw->Draw_Store(*this);
			switch (Select)
			{
			case WEAPON:
				WeaponStore();
				break;
			case PROTECT:
				break;
			case SHIP:
				break;
			case POTION:
				break;
			case STORE_EXIT:
				return;
				break;
			}

		}
	}

	void WeaponStore(void)
	{
		system("cls");
		Print_Weapon();
		Weapon Select;

		while (true)
		{
			Select = m_pKeynDraw->Draw_WeaponStore(*this);
			switch (Select)
			{
			case SHIMETER:
				m_pPlayer->Buy_Item("시미터", 500, 5,0);
				break;
			case KATANA:
				break;
			case HILAND:
				break;
			case  GUN:
				break;
			case WEAPON_EXIT:
				return;
				break;
			case WEAPON_ETC:
				break;

			}
		}
		

	}

	void Inventory_Running()
	{
		Print_Inventory();
		int ItemNo = 0;
		int Itemact = 0;

		while (true)
		{
			ItemNo = m_pKeynDraw->Draw_Inventory(*this);
			if (-1==ItemNo)
			{
				return;
			}
				
			Print_Item();
			cin >> Itemact;
			
			switch ((ItemAct)Itemact)
			{
			case USE:
				m_pPlayer->Use_Item(ItemNo);
				break;
			case UNUSE:
				m_pPlayer->Unuse_Item(ItemNo);
				break;
			case ENHANCEMENT:
				break;
			}
			

		}

	}
private:
	CPlayer* m_pPlayer;
	CKeynDraw* m_pKeynDraw;


};

