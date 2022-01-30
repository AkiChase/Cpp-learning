#include <iostream>
#include <string>
#define MAX 1000

using namespace std;

void showMenu() {
	cout << "1.添加联系人" << endl;
	cout << "2.显示联系人" << endl;
	cout << "3.删除联系人" << endl;
	cout << "4.查找联系人" << endl;
	cout << "5.修改联系人" << endl;
	cout << "6.清空联系人" << endl;
	cout << "0.退出通讯录" << endl;
}

struct Person
{
	string name;
	int sex; //男1，女0
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
	cout << "输入姓名:" << endl;
	cin >> name;
	ps.name = name;

	int sex;
	cout << "输入性别（男：1，女：0）: " << endl;
	while (!(cin >> sex) || !(sex == 0 || sex == 1))
	{
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "请输入0或1，男：1，女：0" << endl;
	}
	ps.sex = sex;


	int age;
	cout << "输入年龄:" << endl;

	while (!(cin >> age) || age < 0)
	{
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "输入正确的年龄!" << endl;
	}
	ps.age = age;

	string phone;
	cout << "输入电话:" << endl;
	cin >> phone;
	ps.phone = phone;

	string adress;
	cout << "输入地址:" << endl;
	cin >> adress;
	ps.adress = adress;

	return ps;
}

void addPerson(AdressBooks *p) {
	if (p->count >= MAX) {
		cout << "通讯录已满，无法添加" << endl;
		return;
	}

	Person ps = newPerson();
	p->personArr[p->count] = ps;
	p->count++;
	cout << "添加成功！" << endl;
	system("pause");
}

void  showPerson(AdressBooks *p) {
	int count = p->count;
	if (count == 0)
	{
		cout << "通讯录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < count; i++)
		{
			Person ps = p->personArr[i];
			cout << "姓名：" << ps.name << "\t";
			cout << "性别：" << (ps.sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << ps.age << "\t";
			cout << "电话：" << ps.phone << "\t";
			cout << "地址：" << ps.adress << endl;
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
	cout << "输入要删除的联系人姓名" << endl;
	cin >> name;
	int index = getPersonIndex(p, name);
	if (index >= 0)
	{
		for (int i = index; i < p->count; i++)
		{
			p->personArr[i] = p->personArr[i + 1];
		}
		p->count--;
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
}


void findPerson(AdressBooks *p) {
	string name;
	cout << "输入要查找的联系人姓名" << endl;
	cin >> name;
	int index = getPersonIndex(p, name);
	if (index >= 0)
	{
		Person ps = p->personArr[index];
		cout << "姓名：" << ps.name << "\t";
		cout << "性别：" << (ps.sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << ps.age << "\t";
		cout << "电话：" << ps.phone << "\t";
		cout << "地址：" << ps.adress << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
}


void editPerson(AdressBooks *p) {
	string name;
	cout << "输入要修改的联系人姓名" << endl;
	cin >> name;
	int index = getPersonIndex(p, name);
	if (index >= 0)
	{
		Person ps = newPerson();
		p->personArr[index] = ps;
		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
}


void clearPerson(AdressBooks *p) {
	// count置0，逻辑清空
	p->count = 0;
	cout << "清空成功！" << endl;
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
			cout << "欢迎下次使用" << endl;
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