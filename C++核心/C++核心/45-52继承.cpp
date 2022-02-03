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
	static int s;
};

int Base::s = 123;

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

	static int s;
};
int content1::s = 223;


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

class Base2
{
	void header() {
		cout << "头部2================头部2" << endl;
	}
	void footer() {
		cout << "尾部2================尾部2" << endl;
	}
};

// 多继承
// 多个父类中可能有同名成员，访问时需要加作用域，否则报错
// 实际开发中不建议使用
class content3 : public Base, public Base2
{
public:
	void print() {
		cout << "内容3" << endl;
	}
};


// 菱形继承:即一个基类有两个派生类，而这两个派生类又有一个派生自他们俩的派生类
// 此时两个派生类都有相同的数据，而他们的派生类就会有双份相同的数据，造成浪费，而且访问都要加作用域不方便
// 解决方法：虚继承，即在两个派生类继承方式上加上  virtual关键字 
// 这样他们的派生类只有一份数据，写上不同的作用域也会访问到同一份数据，所以作用域可省略
class Animal
{
public:
	int n = 1;
};

class Sheep : virtual public Animal
{
public:
	int nn = 2;
};
class Tuo : virtual public Animal
{
public:
	int nn = 3;
};

class YangTuo :public Sheep, public Tuo {};

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

	//静态成员通过对象访问通上
	//静态成员通过类名访问,甚至能通过子类访问，总之就是标明作用域
	cout << content1::s << "\t" << Base::s << "\t" << content1::Base::s << endl;

	YangTuo yt;
	cout << yt.n << endl;
	cout << yt.Sheep::nn << "\t" << yt.Tuo::nn << endl;
}