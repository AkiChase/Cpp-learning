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
	cout << "ְ�����: " << m_Id
		<< "\tְ������: " << m_Name
		<< "\t��λ:" << getDeptName()
		<< "\t��λְ������ϰ彻�������񣬲��·������Ա��" << endl;
}

string Manager::getDeptName() {
	return string("����");
}