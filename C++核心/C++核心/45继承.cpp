#include <iostream>
using namespace std;

// 使用继承，减少代码重复
class Base
{
public:
	void header() {
		cout << "头部================头部" << endl;
	}
	void footer() {
		cout << "尾部================尾部" << endl;
	}
	int n = 666;
};

// content1称为父类Base（基类）的子类（派生类）
/*
公有继承（public）：基类的公有成员也是派生类的公有成员，基类的保护成员也是派生类的保护成员
保护继承（protected）：基类的公有和保护成员将成为派生类的保护成员。
私有继承（private）：基类的公有和保护成员将成为派生类的私有成员。
*/

//基类中所有非静态的成员，都会被继承（不论其是否私有）即类的sizeof是全部的属性+派生类中写的属性
//在派生类中访问不到是因为编译器隐藏了

//派生类实例化时，会先调用基类的构造函数，再调用派生类的构造函数
//派生类对象销毁时，会先调用派生类的析构函数，再调用基类的析构函数

class content1 : public Base
{
public:
	void print() {
		cout << "内容1" << endl;
	}

};

class content2 : public Base
{
public:
	void print() {
		cout << "内容2" << endl;
	}

	void header() {
		cout << "content2的头=======" << endl;
	}

	int n = 777;
};

void func_45() {
	content1 c1;
	c1.header();
	c1.print();
	c1.footer();

	content2 c2;
	c2.header(); // 存在同名成员时，优先访问子类中的成员
	// 注意！子类拥有同名的函数就会隐藏掉父类中所有的同名函数，包括重载的，只能通过作用域来访问
	c2.Base::header(); // 若想访问父类的，需要加 父类:: 的作用域
	// 属性同理
	cout << c2.n << "\t" << c2.Base::n << endl;
	c2.print();
	c2.footer();
}