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
	cout << "�̸�:" << m_Name << "\t" << "���ݷ�:" << m_iAttack << "\t" << "����:" << m_iArmor << "\t" << "���:" << m_iGrade << endl;
}
