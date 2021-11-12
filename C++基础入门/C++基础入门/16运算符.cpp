#include <iostream>
using namespace std;

void func_16()
{
	int a = 3;
	int b = 20;
	//整数相除 得到还是整数，小数部分被移除（直接移除）
	cout << b / a << endl;

	float f1 = 0.5;
	float f2 = 0.25;
	// 可以整除就是整数，否则仍是小数
	cout << f1 / f2 << endl;

	/*
	%取模： 10 % 3 = 1
	小数不可以参与取模

	a++  ++a a-- --a
	*/

	// 赋值运算符
	// +=  -=  *=  /= %=

	//比较运算符
	// == != < > <= >=
	//注意运算优先级
	cout << (f1 != f2) << endl;


	//逻辑运算符
	//!非  &&与  ||或
}