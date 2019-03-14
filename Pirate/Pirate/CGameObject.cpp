#include "CGameObject.h"



CGameObject::CGameObject(const char* pName, int hp, int mp)
	:m_iHp(hp), m_iMp(mp)
{
	strcpy_s(m_Name, pName);

}


CGameObject::~CGameObject()
{
}
