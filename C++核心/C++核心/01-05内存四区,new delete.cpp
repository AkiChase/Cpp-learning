#include <iostream>
# define T 66
using namespace std;

int* createInt() {
	int* a = new int(10); //可以为其设置初始值10
	return a;
}

int* createIntArr() {
	int* arr = new int[10]; //不可设置初始值
	return arr;
}


void func_01() {
	/*
	程序运行前：
		代码区：存放函数代码，是共享的、只读的
		全局区：存放常量(define的)、字符串常量、静态变量(static)。程序结束后操作系统释放。
	运行后：
		栈区：由编译器管理，存放函数的参数，局部变量
		堆区：由程序员自己创建(使用new)、释放(delete)。程序结束后会统一释放。
	*/
	int* p = createInt();
	cout << *p << endl;
	delete p; // 释放指针对应的内存

	int* arr = createIntArr();
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
	// 释放数组 要加[]
	delete[] arr;


	const int t = 666;
	int tt = 666;
	cout << (int)&t << endl;
	cout << (int)&tt << endl;
}