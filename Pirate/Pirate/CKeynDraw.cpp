#include "CKeynDraw.h"
#include "CMainScene.h"
CKeynDraw::CKeynDraw()
	:CursorSpeed(1)
{
	for (int i = 0; i < 4; ++i)
		m_IsKeyDown[i] = false;

	for (int i = 0; i < 10; ++i)
	{
		m_isFirstDraw[i] = true;
	}
}

CKeynDraw::~CKeynDraw()
{
}


void CKeynDraw::KeyCheck_UP(bool & pisValueCG)
{
	if (GetKeyState(VK_UP) < 0)
	{
		m_IsKeyDown[UP] = true;
	}
	else
	{
		if (m_IsKeyDown[UP])
		{
			m_IsKeyDown[UP] = false;
			pisValueCG = true;
			pos.Y -= CursorSpeed;
		}
	}
}
void CKeynDraw::KeyCheck_DOWN(bool & pisValueCG)
{
	if (GetKeyState(VK_DOWN) < 0)
	{
		m_IsKeyDown[DOWN] = true;
	}
	else
	{
		if (m_IsKeyDown[DOWN])
		{
			m_IsKeyDown[DOWN] = false;
			pisValueCG = true;
			pos.Y += CursorSpeed;
		}
	}

}

void CKeynDraw::KeyCheck_RIGHT(bool & pisValueCG)
{
	if (GetKeyState(VK_RIGHT) < 0)
	{
		m_IsKeyDown[RIGHT] = true;
	}
	else
	{
		if (m_IsKeyDown[RIGHT])
		{
			m_IsKeyDown[RIGHT] = false;
			pisValueCG = true;
			pos.X += CursorSpeed;
		}
	}

}

void CKeynDraw::KeyCheck_LEFT(bool & pisValueCG)
{
	if (GetKeyState(VK_LEFT) < 0)
	{
		m_IsKeyDown[LEFT] = true;
	}
	else
	{
		if (m_IsKeyDown[LEFT])
		{
			m_IsKeyDown[LEFT] = false;
			pisValueCG = true;
			pos.X -= CursorSpeed;
		}
	}

}

bool CKeynDraw::KeyCheck(void)
{
	bool IsValueChange = false;
	KeyCheck_UP(IsValueChange);
	KeyCheck_DOWN(IsValueChange);
	KeyCheck_RIGHT(IsValueChange);
	KeyCheck_LEFT(IsValueChange);

	return IsValueChange;
}

void CKeynDraw::Draw_Player()
{
	
	if (KeyCheck())
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		cout << "★";
	}
}

MainMenu CKeynDraw::Draw_Main(const CMainScene& cmain)
{

	if (m_isFirstDraw[IS_MAIN])
	{
		system("cls");
		cmain.Print_Main();
		pos.X = 14;
		pos.Y = 8;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		cout << "←";
		m_isFirstDraw[IS_MAIN] = false;
	}
	
	if (KeyCheck())
	{
		system("cls");
		cmain.Print_Main();
	
		if (pos.X > 14 ||pos.X<14)
		{
			pos.X = 14; // 14로 고정
		}
		//8 9 10 11
		if (pos.Y > 12 || pos.Y < 8)
		{
			pos.Y = 8;
		}
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		cout << "←";

	}

	if (GetKeyState(VK_RETURN) < 0)
	{
		m_isFirstDraw[IS_MAIN] = true;
		return (MainMenu)pos.Y;
	}

	return MAIN_ETC;
}

StoreMenu CKeynDraw::Draw_Store(const CMainScene & cmain)
{
	if (m_isFirstDraw[IS_STORE])
	{
		pos.X = 14;
		pos.Y = 14;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		cout << "★";
		m_isFirstDraw[IS_STORE] = false;
	}
	if (KeyCheck())
	{
		system("cls");
		cmain.Print_Store();
		//이동범위 제한
		if (pos.X > 28)
		{
			pos.X = 28; 
		}
		if (pos.X < 2)
		{
			pos.X = 2;
		}
		if (pos.Y > 17)
		{
			pos.Y = 17;
		}
		if (pos.Y < 9)
		{
			pos.Y = 9;
		}
	
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		cout << "★"<<pos.X<<pos.Y;
	}

	if (9 == pos.X && 11 == pos.Y)
	{
		return WEAPON;
	}
	else if (21 == pos.X && 11 == pos.Y)
	{
		return PROTECT;
	}
	else if (8 == pos.X && 15 == pos.Y)
	{
		return SHIP;
	}
	else if (21 == pos.X && 15 == pos.Y)
	{
		return POTION;
	}
	else if (14 == pos.X && 10 == pos.Y)
	{
		m_isFirstDraw[IS_STORE] = true;
		return STORE_EXIT;
	}

	return STORE_ETC;
}
