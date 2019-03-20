#include "CItem.h"

CItem::CItem(const char* pName, int attack, int armor)
	:m_iAttack(attack), m_iArmor(armor), isUsed(false)
{
	strcpy_s(m_Name, pName);
	m_iGrade = 0;
}

CItem::~CItem()
{

}

void CItem::Print_ItemInfo(void) const
{
	cout << "이름:" << m_Name << "\t" << "공격력:" << m_iAttack << "\t" << "방어력:" << m_iArmor << "\t" << "등급:" << m_iGrade << endl;
}
