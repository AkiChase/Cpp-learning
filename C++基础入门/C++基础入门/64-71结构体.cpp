#include <iostream>
#include <string>
#include <ctime>

using namespace std;


/*
结构体：属于用户自定义的数据类型，允许储存自定义数据
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


// 值传递
void printStudent1(Student stu) {
	// 此处修改不会影响到实参的值
	cout << "姓名:" << stu.name << " 年龄:" << stu.age << " 成绩:" << stu.score << endl;
}

// 地址传递
void printStudent2(Student * p) {
	// 此处修改会影响到实参的值
	cout << "姓名:" << p->name << " 年龄:" << p->age << " 成绩:" << p->score << endl;
}


// 注意tArr[] 传的其实就是指针
void allocateSpace(Teacher tArr[], int len) {
	srand((unsigned int)time(NULL));
	string nameSeed = "ABCDEFG";
	for (int i = 0; i < len; i++)
	{
		tArr[i].name = "老师";
		tArr[i].name += nameSeed[i];
		tArr[i].age = 666 + i;
		for (int j = 0; j < 5; j++)
		{
			tArr[i].stuGroup[j].age = 10 + 5 * i + j;
			tArr[i].stuGroup[j].name = "学生";
			tArr[i].stuGroup[j].name += nameSeed[i];
			tArr[i].stuGroup[j].name += nameSeed[j];
			tArr[i].stuGroup[j].score = rand() % 61 + 40; // 40-100分
		}
	}

}


void printTeacherAndStudent(Teacher tArr[], int len) {
	for (int i = 0; i < len; i++)
	{
		cout << tArr[i].name << "\t年龄"<< tArr[i].age << endl;
		cout << tArr[i].name << "学生们：" << endl;

		for (int j = 0; j < 5; j++)
		{
			Student s = tArr[i].stuGroup[j];
			cout << '\t' << j + 1 << '.' << s.name << "\t年龄:" << s.age << "\t成绩:" << s.score <<endl;
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
	s1.name = "哈哈哈";
	Student s2 = { "姓名", 1 }; //struct关键字可省略
	cout << s2.name << endl;

	// 可以创造Student类型的数组
	Student arr[] = {
		{"小明", 1, 2},
		{"小红", 1}
	};

	arr[0].score = 123;

	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]) ; i++)
	{
		cout << "姓名:" << arr[i].name << " 年龄:" << arr[i].age << " 成绩:" << arr[i].score << endl;
	}


	// 通过指针访问 使用->访问属性
	Student * p = &arr[1];
	p->name = "测试";
	cout << "姓名:" << p->name << " 年龄:" << p->age << " 成绩:" << p->score << endl;


	// 结构体嵌套
	Teacher t;
	t.age = 666;
	t.name = "老师";
	t.stu = *p; //套了一个学生的结构体
	cout << "老师的姓名为:" << t.stu.name << endl;

	cout << "老师学生的姓名为:" << t.stu.name <<endl;


	// 结构体作为函数参数，可以值传递，也可以地址传递
	printStudent1(arr[0]);
	printStudent1(*p);


	// 为了减少内存空间占用，使用地址传递（值传递需要复制一遍所有属性，不仅慢，而且占用内存空间）

	// 若函数定义的形参指针 加上const关键字
	// 可以避免函数中对指针内容进行修改（但是用二级指针还是能改的）

	Teacher teachers[6];
	int len = sizeof(teachers) / sizeof(teachers[0]);
	allocateSpace(teachers, len);
	for (int i = 0; i < len ; i++)
	{
		studentBubbleSort(teachers[i].stuGroup, 5); // 学生成绩排序
	}
	printTeacherAndStudent(teachers, len);
}



