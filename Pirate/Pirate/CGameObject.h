#pragma once
class CGameObject
{
public:
	CGameObject();
	~CGameObject();

private:
	int m_iHp;
	int m_iMp;
	char m_Name[100];

};

