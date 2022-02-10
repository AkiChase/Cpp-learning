#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include "Identity.h"
#include "Student.h"
#include "Teacher.h"
#include "Admin.h"


//进入学生子菜单界面
void studentMenu(Identity* &student)
{

}

//进入教师子菜单界面
void teacherMenu(Identity * &teacher)
{
}

//进入管理员子菜单界面
void adminMenu(Identity * &admin)
{
}



void Login(string fileName, int type) {
	Identity* person = NULL; //多态
	person = new Student(1, "a", "a");

	ifstream ifs(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	int id = 0; string name, pwd;
	if (type == 1) //学生身份
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2) //教师
	{
		cout << "请输入您的职工号： " << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生身份验证
		int fId; //从文件中读取的id号
		string fName; //从文件中获取的姓名
		string fPwd; //从文件中获取密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//与用户输入的信息做对比
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生身份的子菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师身份验证
		int fId; //从文件中获取的id号
		string fName; //从文件中获取的姓名
		string fPwd; //从文件中获取的密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入教师子菜单
				teacherMenu(person);
				return;
			}
		}

	}
	else if (type == 3)
	{
		//管理员身份验证
		string fName; //从文件中获取姓名
		string fPwd; //从文件中获取密码

		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "管理员验证登录成功!" << endl;
				system("pause");
				system("cls");

				person = new Admin(name, pwd);

				//进入管理员子菜单界面
				adminMenu(person);

				return;
			}
		}

	}

	cout << "验证登录失败！" << endl;
	system("pause");
	system("cls");

	return;

}

int main() {
	int select = 0; //用于接受用户的选择

	while (true)
	{
		cout << "======================  欢迎来到传智播客机房预约系统  =====================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

		cin >> select; //接受用户选择

		switch (select) //根据用户选择 实现不同接口
		{
		case 1: //学生身份
			break;
		case 2: //老师身份
			break;
		case 3:  //管理员身份
			break;
		case 0:  //退出系统
			cout << "欢迎下一次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}




	system("pause");
	return 0;
}