#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "Identity.h"


#include <fstream>
#include "globalFile.h"

class Student :public Identity
{
public:
	Student();
	Student(int id, string name, string pwd);
	//�˵�����
	void openMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴����ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	//ѧ��ѧ��
	int m_Id;
};

