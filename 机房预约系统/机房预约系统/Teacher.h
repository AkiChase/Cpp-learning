#pragma once
#include "Identity.h"
class Teacher :
	public Identity
{
public:
	Teacher();
	Teacher(int empId, string name, string pwd);

	//�˵�����
	void openMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	//ְ����
	int m_EmpId;
};

