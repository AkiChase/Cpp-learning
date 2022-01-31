# include <iostream>
using namespace std;


// 默认参数无法重定义，即声明如果某参数已经写了默认值，那么函数内无法再定义对应参数的默认值
void test_func(int a = 5, int b = 10);

void test_func(int a, int b) {
	cout << a << " " << b << endl;
}


// 当然若声明没写默认值，函数实现可以定义默认值
void test_func2(int a, int b);

void test_func2(int a = 6, int b = 66) {
	cout << a << " " << b << endl;
}


// 形参中可加占位参数，虽然意义不大，但是函数调用时必须传入占位参数
// 甚至占位参数可以加默认值
void test_func3(int a, int=777) {
	cout << a << endl;
}



//函数重载：
//1.在同一作用域下，2.函数名可以相同，但是，3.参数个数或参数类型或参数顺序必须至少满足其一（函数返回值类型不包括在内）
// int&和const int&也属于类型不同，func(10)会调用 const int&的
//总之就是必须让函数调用时有 唯一性（注意默认参数的影响）
void test() {
	cout << "测试1" << endl;
}

void test(int a) {
	cout << "测试2" << endl;
}

void test(double a) {
	cout << "测试3" << endl;
}

void test(int a, double b) {
	cout << "测试4" << endl;
}

void test(double a, int b) {
	cout << "测试5" << endl;
}


void func_12() {
	test_func();
	test_func2();
	test_func3(666, 123);

	test();
	test(1);
	test(1.1);
	test(1, 1.1);
	test(1.1, 1);
}