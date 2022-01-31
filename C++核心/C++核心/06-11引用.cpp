#include <iostream>
using namespace std;


// 引用 作为函数参数
void mySwap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}


// 不要返回局部变量的引用（会被释放）
int& ref_01() {
	int* a = new int(10);
	return *a;
}

// 此外返回引用的函数，可以作为左值
int& ref_02() {
	static int a = 10;
	return a;
}

void func_06() {
	//引用
	// b即a的别名，指向同一个地址
	int a = 10;
	int& b = a;

	//引用必须初始化值，而且不可更改，即b不能再更改为其他变量的别名
	int a1 = 1, a2 = 2;
	cout << a1 << "  " << a2 << endl;
	mySwap(a1, a2);
	cout << a1 << "  " << a2 << endl;

	int& t = ref_01();
	cout << t << endl;

	// 此时t2一直指向函数中的static a
	int& t2 = ref_02();
	cout << t2 << endl;

	ref_02() = 666;
	cout << t2 << endl;



	// 引用的本质是 指针 常量， 不可更改的指针
	int& ref = a;
	// 编译器自动转化为 int* const ref = &a;
	ref = 666;
	// 编译器自动转化为 *ref = 666;


	// 常量引用，一般用在形参，防止函数内误操作
	const int& ref2 = 10; // 此处等同于 int temp = 10; const int& ref2 = temp; 不加const时错误

}