#include <iostream>
#include <string>

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

	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]) ; i++)
	{
		cout << "姓名:" << arr[i].name << " 年龄:" << arr[i].age << " 成绩:" << arr[i].score << endl;
	}

}



