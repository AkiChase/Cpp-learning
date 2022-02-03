#include <iostream>
using namespace std;

/*
多态分为静态多态和动态多态
静态多态：函数重载，运算符重载等，复用了函数名
动态多态：派生类和虚函数一起实现动态多态
静态多态时，函数的地址早绑定（编译阶段就绑定），而动态多态晚绑定（运行阶段才绑定地址）

C++ 多态意味着调用成员函数时，会根据调用函数的对象的类型来执行不同的函数。

动态多态的条件：
1.有继承关系
2.派生类重写了基类中的 虚函数 （重写，函数的返回值也要一致）


若有虚函数则类中有以虚函数（表）指针 vfptr ，其指向一个虚函数表vftable，表内记录虚函数的地址
如 &Animal2::speak

而子类继承父类后，其会拷贝一个vftable，保存新vftable的指针
当若子类重写了父类的虚函数，则新的虚函数的地址会覆盖虚函数表中的地址即覆盖为&Cat::speak
每次调用虚函数时，会从对应虚函数表中查找函数地址，因此能找到对应类的函数地址，实现多态


*/

class Animal2
{
public:
	// 加上 virtual关键字（虚函数）
	virtual void speak() {
		cout << "动物在说话" << endl;
	}
};

class Cat : public Animal2
{
public:
	// virtual可加可不加
	void speak() {
		cout << "小猫在说话" << endl;
	}
};

// 此处是父类对象的引用（或者指针）指向的却是子类对象，但是却能根据指向的子类对象不同，执行相应对象中的函数

// 注意c++中子类对象可以转为父类对象，存在赋值兼容，即子类对象中多余的属性不会被添加到父类对象
void doSpeak(Animal2& animal) {
	animal.speak(); // 若Animal2.speak不是虚函数，那么就会调用Animal2.speak() 因为函数地址早绑定了
	// 是虚函数，则会调用传入对象实际的类的speak() 即实现了多态  因为函数地址晚绑定
}

void func_53() {
	Cat c;
	doSpeak(c);
}
