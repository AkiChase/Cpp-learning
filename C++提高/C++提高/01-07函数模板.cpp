#include <iostream>
using namespace std;

// 声明一个模版函数 typename也能写class 没什么区别，可以函数模板写typename，类模板写class更容容易区分
template<typename T> //注意这里可以写在同一行
void mySwap(T&a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}


template<typename T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			mySwap(arr[i], arr[minIndex]);
		}
	}
}


template<typename T>
void myPrint(T arr[], int len) {
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


template<typename numType, typename strType>
void myPrint2(numType num, strType str) {
	cout << "数字:" << num << endl;
	cout << "文本:" << str << endl;
}

class MyData
{
public:
	MyData(int n): num(n){}
	int num;
};


//模板的局限：不是万能的，对于特定的数据类型，需要用具体化的方式做特殊实现
template <typename T>
void myCompare(T& a, T& b) {
	if (a == b)
	{
		cout << "相同" << endl;
	}
	else
	{
		cout << "不同" << endl;
	}
}

// 具体化T 为 MyData类型时
template <> void myCompare(MyData& a, MyData& b) {
	if (a.num==b.num)
	{
		cout << "相同" << endl;
	}
	else
	{
		cout << "不同" << endl;
	}
}



void func_01() {
	int a = 1;
	int b = 2;
	// 1.自动类型推导（要求必须推导出相同的T类型，或能推导出类型||此外，自动类型推导不会发生隐式类型转换）
	mySwap(a, b);
	cout << a << " " << b << endl;

	//2.显示指定类型(会发生隐式类型转换)
	mySwap<int>(a, b);
	cout << a << " " << b << endl;

	char arr[5] = { 'e', 'a', 'c', 'f' ,'e' };
	myPrint(arr, 5);
	mySort(arr, 5);

	//实际开发中，不建议模板和普通函数同名

	//普通函数和函数模板都可以调用时，优先调用普通函数

	//可以通过空模板参数来强制调用函数模板
	myPrint<>(arr, 5);


	//函数模板也能重载(普通和模板会一起重载)

	//如果普通函数和函数模板都能调用，但是普通函数要发生隐式转换，模板函数只需要推导类型，则调用函数模板

	// 学习模板的主要目的：为了在STL中运用系统的模板

	MyData d1(1);
	MyData d2(1);
	myCompare(d1, d2);


	double num1 = 3.1415926;
	char str1[] = "这是文本";
	myPrint2(num1, str1);
}