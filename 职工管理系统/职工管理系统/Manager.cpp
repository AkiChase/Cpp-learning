#include <iostream>
using namespace std;
#include <string>
#include "Manager.h"

Manager::Manager(int id, string name, int dId){
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}

void Manager::showInfo() {
	cout << "职工编号: " << m_Id
		<< "\t职工姓名: " << m_Name
		<< "\t岗位:" << getDeptName()
		<< "\t岗位职责：完成老板交给的任务，并下发任务给员工" << endl;
}

string Manager::getDeptName() {
	return string("经理");
}