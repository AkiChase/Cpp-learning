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
	cout << "职工编号: " << m_Id
		<< "\t职工姓名: " << m_Name
		<< "\t岗位:" << getDeptName()
		<< "\t岗位职责：管理公司所有事务" << endl;
}

string Boss::getDeptName() {
	return string("总裁");
}