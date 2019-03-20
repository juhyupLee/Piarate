#pragma once
#include "Library.h"
class CMainScene;
class CKeynDraw
{
public:
	CKeynDraw();
	~CKeynDraw();

private:
	void KeyCheck_UP( bool & pisValueCG);
	void KeyCheck_DOWN( bool & pisValueCG);
	void KeyCheck_RIGHT( bool & pisValueCG);
	void KeyCheck_LEFT(bool & pisValueCG);
	bool KeyCheck(void);
	
	bool EnterCheck(void);

	
public:
	void Draw_Player();
	MainMenu Draw_Main(const CMainScene& cmain);
	StoreMenu Draw_Store(const CMainScene& cmain);
	Weapon Draw_WeaponStore(const CMainScene& cmain);

	int Draw_Inventory(const CMainScene& cmain);
	
private:
	const int CursorSpeed;
	bool m_IsKeyDown[4] ;
	bool m_isFirstDraw[10];
	bool m_isEnterKeyDown;

	COORD pos;

	


};

