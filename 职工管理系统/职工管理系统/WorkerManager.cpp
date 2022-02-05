#include "WorkerManager.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"
#include <fstream>
#define FILEPATH "empFile.txt"


WorkerManager::WorkerManager() {
	ifstream ifs;
	ifs.open(FILEPATH, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		// 文件不存在
		this->m_empNum = 0;
		this->m_empArr = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		//文件为空
		this->m_empNum = 0;
		this->m_empArr = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
	}

	this->m_empNum = this->getEmpNum();
	this->initEmp();
}

WorkerManager::~WorkerManager() {

}

void WorkerManager::showMenu() {
	cout << "***** 欢迎使用职工管理系统 *****" << endl;
	cout << "******** 0.退出管理系统 ********" << endl;
	cout << "******** 1.增加职工信息 ********" << endl;
	cout << "******** 2.显示职工信息 ********" << endl;
	cout << "******** 3.删除离职职工 ********" << endl;
	cout << "******** 4.修改职工信息 ********" << endl;
	cout << "******** 5.查找职工信息 ********" << endl;
	cout << "******** 6.按照编号排序 ********" << endl;
	cout << "******** 7.清空所有文档 ********" << endl;
	cout << "\n请输入序号：" << endl;
}

void WorkerManager::exitSystem() {
	cout << "欢迎下次使用~" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::addEmp() {
	cout << "请输入要添加职工的数量:" << endl;
	int num = 0;
	cin >> num;
	if (num > 0)
	{
		int newSize = this->m_empNum + num;
		Worker** newEmpArr = new Worker*[newSize];

		if (newEmpArr != NULL)
		{
			for (int i = 0; i < this->m_empNum; i++)
			{
				newEmpArr[i] = this->m_empArr[i];
			}
		}
		// 添加新的
		for (int i = 0; i < num; i++)
		{
			int id;
			string name;
			cout << "请输入第" << i + 1 << "个职工的编号:" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "个职工的姓名:" << endl;
			cin >> name;

			int dId;
			cout << "请选择第" << i + 1 << "个职工的岗位:" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;

			while (!(cin >> dId) || !(dId == 1 || dId == 2 || dId == 3))
			{
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "请输入1或2或3" << endl;
			}

			Worker* newWorker = NULL;
			switch (dId)
			{
			case 1:
				newWorker = new Employee(id, name, dId);
				break;
			case 2:
				newWorker = new Manager(id, name, dId);
				break;
			case 3:
				newWorker = new Boss(id, name, dId);
				break;
			}

			newEmpArr[i + this->m_empNum] = newWorker;
		}

		delete this->m_empArr;
		this->m_empArr = newEmpArr;
		this->m_empNum = newSize;
		this->m_FileIsEmpty = false;

		this->save();
		cout << "成功添加" << num << "名新职工" << endl;
	}
	else
	{
		cout << "输入数据有误" << endl;
	}
}


void WorkerManager::save() {
	fstream fs;
	fs.open(FILEPATH, ios::out);
	for (int i = 0; i < this->m_empNum; i++)
	{
		fs << this->m_empArr[i]->m_Id << " "
			<< this->m_empArr[i]->m_Name << " "
			<< this->m_empArr[i]->m_DeptId << endl;
	}
	fs.close();
}

int WorkerManager::getEmpNum() {
	ifstream ifs;
	ifs.open(FILEPATH, ios::in);
	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	return num;
}

void WorkerManager::initEmp() {
	ifstream ifs;
	ifs.open(FILEPATH, ios::in);
	int id;
	string name;
	int dId;

	this->m_empArr = new Worker*[this->m_empNum];
	int i = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 0)
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 1)
		{
			worker = new Manager(id, name, dId);
		}
		else
		{
			worker = new Boss(id, name, dId);
		}

		this->m_empArr[i++] = worker;
	}
	ifs.close();
}

void WorkerManager::showEmp() {
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_empNum; i++)
		{
			this->m_empArr[i]->showInfo();
		}
	}
}

int WorkerManager::getEmpIndex(int id) {
	int index = -1;
	for (int i = 0; i < this->m_empNum; i++)
	{
		if (this->m_empArr[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::delEmp() {
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
		return;
	}

	int id = 0;
	cout << "请输入要删除的职工编号:" << endl;
	cin >> id;

	int index = getEmpIndex(id);
	if (index >= 0)
	{
		for (int i = index; i < this->m_empNum - 1; i++)
		{
			this->m_empArr[i] = this->m_empArr[i + 1];
		}
		this->m_empNum--;
		this->save();
		cout << "删除成功!" << endl;
	}
	else
	{
		cout << "删除失败！查无此人" << endl;
	}
}