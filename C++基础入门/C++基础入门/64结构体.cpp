#include <iostream>
#include <string>

using namespace std;


/*
�ṹ�壺�����û��Զ�����������ͣ��������Զ�������
*/

struct Student
{
	string name;
	int age;
	int score = 100;
};


void func_64() {
	struct Student s1;
	s1.name = "������";
	Student s2 = { "����", 1 }; //struct�ؼ��ֿ�ʡ��
	cout << s2.name << endl;

	// ���Դ���Student���͵�����
	Student arr[] = {
		{"С��", 1, 2},
		{"С��", 1}
	};

	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]) ; i++)
	{
		cout << "����:" << arr[i].name << " ����:" << arr[i].age << " �ɼ�:" << arr[i].score << endl;
	}

}



