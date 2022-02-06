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

Worker* WorkerManager::createNewWorker() {
	int id;
	string name;
	cout << "������ְ���ı��:" << endl;
	cin >> id;

	cout << "������ְ��������:" << endl;
	cin >> name;

	int dId;
	cout << "��ѡ��ְ���ĸ�λ:" << endl;
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

	return newWorker;
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
			newEmpArr[i + this->m_empNum] = createNewWorker();
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

void WorkerManager::modifyEmp() {
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		return;
	}

	int id = 0;
	cout << "������Ҫ�޸ĵ�ְ�����:" << endl;
	cin >> id;

	int index = getEmpIndex(id);
	if (index >= 0)
	{
		this->m_empArr[index] = this->createNewWorker();
		this->save();
		cout << "�޸ĳɹ�!" << endl;
	}
	else
	{
		cout << "�޸�ʧ�ܣ����޴���" << endl;
	}
}

void WorkerManager::findEmp() {
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		return;
	}
	else
	{
		int choice;
		cout << "��ѡ����ҷ�ʽ:" << endl;
		cout << "1.��Ų���" << endl;
		cout << "2.��������" << endl;

		while (!(cin >> choice) || !(choice == 1 || choice == 2))
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "������1��2" << endl;
		}

		if (choice == 1)
		{
			int id;
			cout << "��������ҵ�ְ�����:" << endl;
			cin >> id;

			bool flag = false;
			for (int i = 0; i < this->m_empNum; i++)
			{
				if (this->m_empArr[i]->m_Id == id)
				{
					this->m_empArr[i]->showInfo();
					flag = true;
				}
			}
			if (!flag)
			{
				cout << "����ʧ�ܣ����޴���!" << endl;
			}
		}
		else
		{
			string name;
			cout << "��������ҵ�ְ������:" << endl;
			cin >> name;

			bool flag = false;
			for (int i = 0; i < this->m_empNum; i++)
			{
				if (this->m_empArr[i]->m_Name == name)
				{
					this->m_empArr[i]->showInfo();
					flag = true;
				}
			}
			if (!flag)
			{
				cout << "����ʧ�ܣ����޴���!" << endl;
			}
		}
	}
}

void WorkerManager::sortEmp() {
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		return;
	}

	int choice;
	cout << "��ѡ������ʽ:" << endl;
	cout << "1.�������" << endl;
	cout << "2.��Ž���" << endl;

	while (!(cin >> choice) || !(choice == 1 || choice == 2))
	{
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "������1��2" << endl;
	}

	for (int i = 0; i < this->m_empNum - 1; i++)
	{
		int minOrMaxIndex = i;
		for (int j = i + 1; j < this->m_empNum; j++)
		{
			if (choice == 2) // ����
			{
				if (this->m_empArr[j]->m_Id > this->m_empArr[minOrMaxIndex]->m_Id)
				{
					minOrMaxIndex = j; // max
				}
			}
			else // ����
			{
				if (this->m_empArr[j]->m_Id < this->m_empArr[minOrMaxIndex]->m_Id)
				{
					minOrMaxIndex = j; // min
				}
			}
		}

		if (minOrMaxIndex!=i) // ��Ҫ����
		{
			Worker* tmp = this->m_empArr[minOrMaxIndex];
			this->m_empArr[minOrMaxIndex] = this->m_empArr[i];
			this->m_empArr[i] = tmp;
		}
	}

	this->save();
	cout << "����ɹ�������ʽ:" << (choice==1? "�������":"��Ž���") <<endl;
}

void WorkerManager::clearFile() {
	cout << "ȷ������ļ���" << endl;
	cout << "����\"y\"ȷ����գ����򷵻�:";
	string choice;
	cin >> choice;
	if (choice!="y")
	{
		return;
	}

	if (!this->m_FileIsEmpty)
	{
		//����ļ�
		ofstream ofs;
		ofs.open(FILEPATH, ios::trunc);
		ofs.close();

		//�ͷŶ���
		for (int i=1;i<this->m_empNum;i++)
		{
			if (this->m_empArr[i]!=NULL)
			{
				delete m_empArr[i];
			}
		}
		this->m_empNum = 0;
		delete[] this->m_empArr; // �����������
		this->m_empArr = NULL;
		this->m_FileIsEmpty = true;
	}

	cout << "��ճɹ���" << endl;

}