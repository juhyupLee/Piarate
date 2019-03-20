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
		cout << "1.����" << endl;
		cout << "2.���� ������" << endl;
		cout << "3.����" << endl;
		cout << "4.����" << endl;
		cout << "5.������" << endl;
	}
	void Print_Store()const
	{
		m_pPlayer->Print_PlayerInfo();
		cout << "�����������������" << endl;
		cout << "��           EXIT             ��" << endl;
		cout << "��            ��              ��" << endl;
		cout << "��      ��           ��       ��" << endl;
		cout << "��   (Weapon)     (Protect)   ��" << endl;
		cout << "��                            ��" << endl;
		cout << "��                            ��" << endl;
		cout << "��      ��           ��       ��" << endl;
		cout << "��    (Ship)      (Potion)    ��" << endl;
		cout << "��                            ��" << endl;
		cout << "�����������������" << endl;
	}
	void Print_Weapon()const
	{
		m_pPlayer->Print_PlayerInfo();
		cout << "\"����ð� �ѹ� ����\"                   " << endl;
		cout << "                                             " << endl;
		cout << "�� �ù���     [���·�+5,��ȭ0](500coin)       " << endl;
		cout << "�� īŸ��     [���ݷ�+20,��ȭ0](6900coin)     " << endl;
		cout << "�� ���̷���   [���ݷ�+30 ��ȭ 0](10,000coin)  " << endl;
		cout << "��  38����     [���ݷ�+40 ��ȭ 0](50,000       " << endl;
		cout << "������" << endl;
	}

	void Print_Inventory()const
	{
		
		system("cls");
		m_pPlayer->Print_PlayerInfo();
		m_pPlayer->Print_Itemlist();
		cout << "�������� ���ʽÿ�:";

	}
	void Print_Item() const
	{
		cout << "1.����" << endl;
		cout << "2.����" << endl;
		cout << "3.��ȭ" << endl;
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
				m_pPlayer->Buy_Item("�ù���", 500, 5,0);
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

