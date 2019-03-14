#include "CPlayer.h"



CPlayer::CPlayer(const char*pName)
	:CGameObject(pName,100,100),m_Title("거리의방랑자"), m_iExp(0),m_iLev(1)
{

}


CPlayer::~CPlayer()
{
}
