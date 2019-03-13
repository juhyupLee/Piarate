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
public:
	//void Main_Running()
	//{
	//	Print_Main();
	//	while (true)
	//	{
	//		//m_pKeynDraw->Draw_Main(this);

	//	}
	//	
	//}

private:
	CPlayer* m_pPlayer;
	CKeynDraw* m_pKeynDraw();


};

