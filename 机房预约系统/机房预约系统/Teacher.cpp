#include <iostream>
using namespace std;
#include <string>
#include "Teacher.h"

Teacher::Teacher() {}

Teacher::Teacher(int empId, string name, string pwd) {
	this->m_EmpId = empId; this->m_Name = name; this->m_Pwd = pwd;
}

//菜单界面
void Teacher::openMenu() {

}

//查看所有预约
void Teacher::showAllOrder() {

}

//审核预约
void Teacher::validOrder() {

}
