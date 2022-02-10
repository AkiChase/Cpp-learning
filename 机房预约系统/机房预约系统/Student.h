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
	//菜单界面
	void openMenu();

	//申请预约
	void applyOrder();

	//查看自身预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

	//学生学号
	int m_Id;
};

