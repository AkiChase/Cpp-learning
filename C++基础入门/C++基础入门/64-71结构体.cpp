#include <iostream>
#include <string>
#include <ctime>

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

struct Teacher
{
	string name;
	int age;
	Student stu;
	Student stuGroup[5];
};


// ֵ����
void printStudent1(Student stu) {
	// �˴��޸Ĳ���Ӱ�쵽ʵ�ε�ֵ
	cout << "����:" << stu.name << " ����:" << stu.age << " �ɼ�:" << stu.score << endl;
}

// ��ַ����
void printStudent2(Student * p) {
	// �˴��޸Ļ�Ӱ�쵽ʵ�ε�ֵ
	cout << "����:" << p->name << " ����:" << p->age << " �ɼ�:" << p->score << endl;
}


// ע��tArr[] ������ʵ����ָ��
void allocateSpace(Teacher tArr[], int len) {
	srand((unsigned int)time(NULL));
	string nameSeed = "ABCDEFG";
	for (int i = 0; i < len; i++)
	{
		tArr[i].name = "��ʦ";
		tArr[i].name += nameSeed[i];
		tArr[i].age = 666 + i;
		for (int j = 0; j < 5; j++)
		{
			tArr[i].stuGroup[j].age = 10 + 5 * i + j;
			tArr[i].stuGroup[j].name = "ѧ��";
			tArr[i].stuGroup[j].name += nameSeed[i];
			tArr[i].stuGroup[j].name += nameSeed[j];
			tArr[i].stuGroup[j].score = rand() % 61 + 40; // 40-100��
		}
	}

}


void printTeacherAndStudent(Teacher tArr[], int len) {
	for (int i = 0; i < len; i++)
	{
		cout << tArr[i].name << "\t����"<< tArr[i].age << endl;
		cout << tArr[i].name << "ѧ���ǣ�" << endl;

		for (int j = 0; j < 5; j++)
		{
			Student s = tArr[i].stuGroup[j];
			cout << '\t' << j + 1 << '.' << s.name << "\t����:" << s.age << "\t�ɼ�:" << s.score <<endl;
		}
	}
}

void studentBubbleSort(Student sGroup[], int len) {
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (sGroup[j].score < sGroup[j + 1].score) {
				Student tmp = sGroup[j];
				sGroup[j] = sGroup[j + 1];
				sGroup[j + 1] = tmp;
			}
		}
	}
}

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

	arr[0].score = 123;

	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]) ; i++)
	{
		cout << "����:" << arr[i].name << " ����:" << arr[i].age << " �ɼ�:" << arr[i].score << endl;
	}


	// ͨ��ָ����� ʹ��->��������
	Student * p = &arr[1];
	p->name = "����";
	cout << "����:" << p->name << " ����:" << p->age << " �ɼ�:" << p->score << endl;


	// �ṹ��Ƕ��
	Teacher t;
	t.age = 666;
	t.name = "��ʦ";
	t.stu = *p; //����һ��ѧ���Ľṹ��
	cout << "��ʦ������Ϊ:" << t.stu.name << endl;

	cout << "��ʦѧ��������Ϊ:" << t.stu.name <<endl;


	// �ṹ����Ϊ��������������ֵ���ݣ�Ҳ���Ե�ַ����
	printStudent1(arr[0]);
	printStudent1(*p);


	// Ϊ�˼����ڴ�ռ�ռ�ã�ʹ�õ�ַ���ݣ�ֵ������Ҫ����һ���������ԣ�������������ռ���ڴ�ռ䣩

	// ������������β�ָ�� ����const�ؼ���
	// ���Ա��⺯���ж�ָ�����ݽ����޸ģ������ö���ָ�뻹���ܸĵģ�

	Teacher teachers[6];
	int len = sizeof(teachers) / sizeof(teachers[0]);
	allocateSpace(teachers, len);
	for (int i = 0; i < len ; i++)
	{
		studentBubbleSort(teachers[i].stuGroup, 5); // ѧ���ɼ�����
	}
	printTeacherAndStudent(teachers, len);
}



