#include <iostream>
#include <string>
#define MAX 1000

using namespace std;

void showMenu() {
	cout << "1.�����ϵ��" << endl;
	cout << "2.��ʾ��ϵ��" << endl;
	cout << "3.ɾ����ϵ��" << endl;
	cout << "4.������ϵ��" << endl;
	cout << "5.�޸���ϵ��" << endl;
	cout << "6.�����ϵ��" << endl;
	cout << "0.�˳�ͨѶ¼" << endl;
}

struct Person
{
	string name;
	int sex; //��1��Ů0
	int age;
	string phone;
	string adress;
};

struct AdressBooks
{
	Person personArr[MAX];
	int count;
};


Person newPerson() {
	Person ps;

	string name;
	cout << "��������:" << endl;
	cin >> name;
	ps.name = name;

	int sex;
	cout << "�����Ա��У�1��Ů��0��: " << endl;
	while (!(cin >> sex) || !(sex == 0 || sex == 1))
	{
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "������0��1���У�1��Ů��0" << endl;
	}
	ps.sex = sex;


	int age;
	cout << "��������:" << endl;

	while (!(cin >> age) || age < 0)
	{
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "������ȷ������!" << endl;
	}
	ps.age = age;

	string phone;
	cout << "����绰:" << endl;
	cin >> phone;
	ps.phone = phone;

	string adress;
	cout << "�����ַ:" << endl;
	cin >> adress;
	ps.adress = adress;

	return ps;
}

void addPerson(AdressBooks *p) {
	if (p->count >= MAX) {
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}

	Person ps = newPerson();
	p->personArr[p->count] = ps;
	p->count++;
	cout << "��ӳɹ���" << endl;
	system("pause");
}

void  showPerson(AdressBooks *p) {
	int count = p->count;
	if (count == 0)
	{
		cout << "ͨѶ¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < count; i++)
		{
			Person ps = p->personArr[i];
			cout << "������" << ps.name << "\t";
			cout << "�Ա�" << (ps.sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << ps.age << "\t";
			cout << "�绰��" << ps.phone << "\t";
			cout << "��ַ��" << ps.adress << endl;
		}
	}
	system("pause");
}

int getPersonIndex(AdressBooks *p, string name) {
	for (int i = 0; i < p->count; i++)
	{
		if (p->personArr[i].name == name)
		{
			return i;
		}
	}
	return -1;
}


void deletePerson(AdressBooks *p) {
	string name;
	cout << "����Ҫɾ������ϵ������" << endl;
	cin >> name;
	int index = getPersonIndex(p, name);
	if (index >= 0)
	{
		for (int i = index; i < p->count; i++)
		{
			p->personArr[i] = p->personArr[i + 1];
		}
		p->count--;
		cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
}


void findPerson(AdressBooks *p) {
	string name;
	cout << "����Ҫ���ҵ���ϵ������" << endl;
	cin >> name;
	int index = getPersonIndex(p, name);
	if (index >= 0)
	{
		Person ps = p->personArr[index];
		cout << "������" << ps.name << "\t";
		cout << "�Ա�" << (ps.sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << ps.age << "\t";
		cout << "�绰��" << ps.phone << "\t";
		cout << "��ַ��" << ps.adress << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
}


void editPerson(AdressBooks *p) {
	string name;
	cout << "����Ҫ�޸ĵ���ϵ������" << endl;
	cin >> name;
	int index = getPersonIndex(p, name);
	if (index >= 0)
	{
		Person ps = newPerson();
		p->personArr[index] = ps;
		cout << "�޸ĳɹ���" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
}


void clearPerson(AdressBooks *p) {
	// count��0���߼����
	p->count = 0;
	cout << "��ճɹ���" << endl;
	system("pause");
}

int main() {

	int select = 0;
	AdressBooks adb;
	adb.count = 0;


	while (true)
	{
		system("cls");
		showMenu();
		cin >> select;
		switch (select)
		{
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		case 1:
			addPerson(&adb);
			break;
		case 2:
			showPerson(&adb);
			break;
		case 3:
			deletePerson(&adb);
			break;
		case 4:
			findPerson(&adb);
			break;
		case 5:
			editPerson(&adb);
			break;
		case 6:
			clearPerson(&adb);
			break;
		}
	}

	return 0;
}