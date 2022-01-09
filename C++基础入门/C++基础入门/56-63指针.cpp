#include <iostream>;
using namespace std;

void func_56() {
	// 通过指针保存地址
	int a = 10;
	int *p = &a;
	cout << "访问内存：a=" << *p << endl;
	cout << "指针大小：" << sizeof(p) << endl;

	//32位下所有指针都占用4byte (64位则8byte)

	//空指针 指向编号为0的，不可访问，常用于初始化。
	int *pn = NULL;
	
	//野指针 指向非程序申请的内存空间


	// 常量指针,此时该指针无法用于修改指向内存的值*p1，但其指向p可变  如*p1 = 20; 报错，但p1 = &a; 正确
	int b = 1;
	const int *p1 = &b;

	// 指针常量 此时指向的值*p2可以改，但指向p2不能改
	int * const p2 = &a;
	
	// *p3 p3都不可变
	const int * const p3 = &a;


	//指针作为函数的参数时即 地址传参，可以修改实参的值
}