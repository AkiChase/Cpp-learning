#pragma once
#include "Identity.h"
class Admin :
	public Identity
{
public:
	Admin();
	Admin(string name, string pwd);

	//菜单界面
	virtual void openMenu();

	//添加账号
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清空预约记录
	void cleanFile();

	//初始化容器
	void initVector();

	//检测重复 参数1 检测学号/职工号  参数2  检测类型
	bool checkRepeat(int id, int type);
};

