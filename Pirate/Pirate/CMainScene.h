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
				break;
			case SHIP_MAINTAIN:
				break;
			case DEPARTURE:
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
				cout << "hi" << endl;
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

	}
private:
	CPlayer* m_pPlayer;
	CKeynDraw* m_pKeynDraw;


};

