#include <iostream>
using namespace std;
#include <string>
#include "Employee.h"


Employee::Employee(int id, string name, int dId){
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}

void Employee::showInfo() {
	cout << "ְ�����: " << m_Id
		<< "\tְ������: " << m_Name
		<< "\t��λ:" << getDeptName()
		<< "\t��λְ����ɾ�����������" << endl;
}

string Employee::getDeptName() {
	return string("Ա��");
}