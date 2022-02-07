#include <iostream>
#include <string>
#include "MyData3.hpp"
using namespace std;

//类模板：类中成员的类型用通用类型代替
//注意类模板没有自动类型推导！！只能显示指定类型
//类模板中可以在模板参数列表中填写默认类型

//类模板中的成员函数在调用时才创建
template <class StrType, class NumType = int>
class MyData2
{
public:
	MyData2(StrType name, NumType age) : m_name(name), m_age(age) {
		cout << "MyData2构造函数" << endl;
	}

	StrType m_name;
	NumType m_age;
};


// 当类模板对象作为函数参数时
//1.指定传入类型（常用，其他两种都是函数模板配合类模板，不常用）
void printData1(MyData2<string, int>& d) {
	cout << d.m_name << endl;
	cout << d.m_age << endl;
}

//2.参数模板化
// typeid(类型).name(); 可以查看类型的名称
template<typename T1, typename T2>
void printData2(MyData2<T1, T2>& d) {
	cout << d.m_name << endl;
	cout << d.m_age << endl;
	cout << "T1的类型:" << typeid(T1).name() << endl;
	cout << "T2的类型:" << typeid(T2).name() << endl;
}

//3.整个类模板化
template<class T>
void printData3(T& d) {
	cout << d.m_name << endl;
	cout << d.m_age << endl;
	cout << "T的类型:" << typeid(T).name() << endl;
}


//类模板的继承：
//子类继承时需要指定父类中用到的通用类型是什么
class Son1 : public MyData2<string> // 当然若有默认参数也可以省略
{};


template <class T>
class Base
{
public:
	T foo;
};


//否则需要把子类也写成类模板
template <class T1, class T2>
class Son2 : public Base<T1>
{
public:
	Son2();
	T2 bar; // 若不需要新的通用类型当然可以不需要T2
};

// 类外写实现的方式：需要补上template T1 T2 并在函数的作用域上标明需要的类型T1,T2
template <class T1, class T2>
Son2<T1, T2>::Son2()
{
	cout << "T1的类型:" << typeid(T1).name() << endl;
	cout << "T2的类型:" << typeid(T2).name() << endl;
}



template <class T> class MyDate4; // 提前声明MyDate4类

// 需要提前让编译器知道有这个函数才能作为友元
template <class T>
void myFPrint(MyDate4<T> d) {
	cout << "私有属性：a=" << d.a << endl;
}

template <class T>
class MyDate4
{
	friend void myFPrint<>(MyDate4<T> d);  // 友元 全局函数类外实现需要加上空的模板列表<>，还需要一系列操作
	// 若全局函数类内实现则不需要<>直接在类内写好函数声明和实现即可（推荐！类外过于麻烦）


public:
	MyDate4(T t) {
		this->a = t;
	}

private:
	T a;
};




void func_08() {
	MyData2<string> d("测试", 666); // 把double隐式转化为了int
	printData1(d);
	cout << "-----------" << endl;
	printData2(d);
	cout << "-----------" << endl;
	printData3(d);
	cout << "-----------" << endl;
	Son2<string, int> s;
	cout << "-----------" << endl;

	//类模板分文件编写时会出现链接不到函数的问题，解决：
	//1. include cpp文件而不是h文件（当然h文件也要正常写）
	//（主流）2. 把h文件和cpp文件内容合并为hpp文件（hpp不是硬性要求，但是是约定俗成,一看大家就知道是类模板）
	MyData3<string, int> d3("姓名", 666);
	d3.showInfo();

	cout << "-----------" << endl;
	MyDate4<double>d4(3.14);
	myFPrint(d4);

}