#include <iostream>
using namespace std;
#include "MyArray.hpp"
#include <string>

class Mydata5
{
public:
	Mydata5() {}; //要手动提供默认的无参构造函数
	Mydata5(int age, string name) :m_Age(age), m_Name(name) {}
	int m_Age;
	string m_Name;
};


void func_16() {
	MyArray<int> arr(5);
	for (int i = 0; i < 5; i++)
	{
		arr.pushBack(i + 100);
	}
	arr.printArr();

	arr.popBack();
	arr.printArr();
	cout << arr.getCapacity() << endl;
	cout << arr.getSize() << endl;

	MyArray<Mydata5> arr2(3);
	arr2.pushBack(Mydata5(123, "哈哈哈"));
	arr2.pushBack(Mydata5(223, "aa"));
	arr2.pushBack(Mydata5(333, "学习"));

	for (int i = 0; i < 3 ; i++)
	{
		cout << arr2[i].m_Name << endl;
	}
}