#include "CMainScene.h"



CMainScene::CMainScene()
{
	m_pPlayer = new CPlayer("����������");
	m_pKeynDraw = new CKeynDraw;
}


CMainScene::~CMainScene()
{
	delete m_pPlayer;
	delete m_pKeynDraw;

}
