#include "CKeynDraw.h"


CKeynDraw::CKeynDraw()
{
	for (int i = 0; i < 4; ++i)
		m_IsKeyDown[i] = false;

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
			pos.Y -= 2;
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
			pos.Y += 2;
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
			pos.X += 2;
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
			pos.X -= 2;
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
		cout << "กฺ";
	}
}

//void CKeynDraw::Draw_Main(const CMainScene& cmain)
//{
//	if (KeyCheck())
//	{
//		system("cls");
//		cmain.Print_Main();
//		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
//		cout << "ก็";
//	}
//}
