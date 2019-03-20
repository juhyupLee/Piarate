#include "CGameObject.h"



CGameObject::CGameObject(const char* pName, int hp, int mp,int attack,int armor)
	:m_iHp(hp), m_iMp(mp),m_iAttack(attack),m_iArmor(armor)
{
	strcpy_s(m_Name, pName);

}


CGameObject::~CGameObject()
{
}
