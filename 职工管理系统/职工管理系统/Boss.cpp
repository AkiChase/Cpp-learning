#include <iostream>
using namespace std;
#include <string>
#include "Boss.h"

Boss::Boss(int id, string name, int dId) {
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}

void Boss::showInfo() {
	cout << "ְ�����: " << m_Id
		<< "\tְ������: " << m_Name
		<< "\t��λ:" << getDeptName()
		<< "\t��λְ�𣺹���˾��������" << endl;
}

string Boss::getDeptName() {
	return string("�ܲ�");
}