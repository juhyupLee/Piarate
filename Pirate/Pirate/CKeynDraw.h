#pragma once
#include "Library.h"
#include "CMainScene.h"

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
	
public:
	void Draw_Player();
	//void Draw_Main(const CMainScene & cmain);

	
private:
	bool m_IsKeyDown[4] ;
	COORD pos;

	


};

