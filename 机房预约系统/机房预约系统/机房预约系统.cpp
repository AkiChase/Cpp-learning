#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include "Identity.h"
#include "Student.h"
#include "Teacher.h"
#include "Admin.h"


//����ѧ���Ӳ˵�����
void studentMenu(Identity* &student)
{

}

//�����ʦ�Ӳ˵�����
void teacherMenu(Identity * &teacher)
{
}

//�������Ա�Ӳ˵�����
void adminMenu(Identity * &admin)
{
}



void Login(string fileName, int type) {
	Identity* person = NULL; //��̬
	person = new Student(1, "a", "a");

	ifstream ifs(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	int id = 0; string name, pwd;
	if (type == 1) //ѧ�����
	{
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2) //��ʦ
	{
		cout << "����������ְ���ţ� " << endl;
		cin >> id;
	}

	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//ѧ�������֤
		int fId; //���ļ��ж�ȡ��id��
		string fName; //���ļ��л�ȡ������
		string fPwd; //���ļ��л�ȡ����
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//���û��������Ϣ���Ա�
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ����ݵ��Ӳ˵�
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ�����֤
		int fId; //���ļ��л�ȡ��id��
		string fName; //���ļ��л�ȡ������
		string fPwd; //���ļ��л�ȡ������
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//�����ʦ�Ӳ˵�
				teacherMenu(person);
				return;
			}
		}

	}
	else if (type == 3)
	{
		//����Ա�����֤
		string fName; //���ļ��л�ȡ����
		string fPwd; //���ļ��л�ȡ����

		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "����Ա��֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");

				person = new Admin(name, pwd);

				//�������Ա�Ӳ˵�����
				adminMenu(person);

				return;
			}
		}

	}

	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");

	return;

}

int main() {
	int select = 0; //���ڽ����û���ѡ��

	while (true)
	{
		cout << "======================  ��ӭ�������ǲ��ͻ���ԤԼϵͳ  =====================" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";

		cin >> select; //�����û�ѡ��

		switch (select) //�����û�ѡ�� ʵ�ֲ�ͬ�ӿ�
		{
		case 1: //ѧ�����
			break;
		case 2: //��ʦ���
			break;
		case 3:  //����Ա���
			break;
		case 0:  //�˳�ϵͳ
			cout << "��ӭ��һ��ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}




	system("pause");
	return 0;
}