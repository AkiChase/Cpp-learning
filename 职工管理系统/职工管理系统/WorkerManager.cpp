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
		cout << "�ļ�������" << endl;
		// �ļ�������
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
		cout << "�ļ�Ϊ��" << endl;
		//�ļ�Ϊ��
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
	cout << "***** ��ӭʹ��ְ������ϵͳ *****" << endl;
	cout << "******** 0.�˳�����ϵͳ ********" << endl;
	cout << "******** 1.����ְ����Ϣ ********" << endl;
	cout << "******** 2.��ʾְ����Ϣ ********" << endl;
	cout << "******** 3.ɾ����ְְ�� ********" << endl;
	cout << "******** 4.�޸�ְ����Ϣ ********" << endl;
	cout << "******** 5.����ְ����Ϣ ********" << endl;
	cout << "******** 6.���ձ������ ********" << endl;
	cout << "******** 7.��������ĵ� ********" << endl;
	cout << "\n��������ţ�" << endl;
}

void WorkerManager::exitSystem() {
	cout << "��ӭ�´�ʹ��~" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::addEmp() {
	cout << "������Ҫ���ְ��������:" << endl;
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
		// ����µ�
		for (int i = 0; i < num; i++)
		{
			int id;
			string name;
			cout << "�������" << i + 1 << "��ְ���ı��:" << endl;
			cin >> id;

			cout << "�������" << i + 1 << "��ְ��������:" << endl;
			cin >> name;

			int dId;
			cout << "��ѡ���" << i + 1 << "��ְ���ĸ�λ:" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;

			while (!(cin >> dId) || !(dId == 1 || dId == 2 || dId == 3))
			{
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "������1��2��3" << endl;
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
		cout << "�ɹ����" << num << "����ְ��" << endl;
	}
	else
	{
		cout << "������������" << endl;
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		return;
	}

	int id = 0;
	cout << "������Ҫɾ����ְ�����:" << endl;
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
		cout << "ɾ���ɹ�!" << endl;
	}
	else
	{
		cout << "ɾ��ʧ�ܣ����޴���" << endl;
	}
}