#include "CMainScene.h"



CMainScene::CMainScene()
{
	m_pPlayer = new CPlayer("하이젠버그");
	m_pKeynDraw = new CKeynDraw;
}


CMainScene::~CMainScene()
{
	delete m_pPlayer;
	delete m_pKeynDraw;

}
