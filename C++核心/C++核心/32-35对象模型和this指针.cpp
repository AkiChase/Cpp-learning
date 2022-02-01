#include <iostream>
using namespace std;

// 类的成员变量和成员函数是分开储存的
// 只有非静态成员 变量  才属于类特定的一个对象，可以用sizeof获取大小，空对象sizeof为1，只有一个int的为4
// 函数和静态变量都是共享的


class Test2
{
public:
	// this是类中默认的对象 指针，指向被调用的成员函数所属的对象
	// this 是不可修改指向的常量指针,在每个成员函数中相当于 Test2 * const this;
	// 可以借此让静态成员函数访问到对应对象的非静态成员
	Test2(int n) {
		this->n = n;
	}

	// 可以使用*this来返回对象本身，实现链式调用  注意要返回"引用"，若返回值无法达到预期效果
	Test2& add(Test2 t) {
		this->n += t.n;
		return *this;
	}

	void showWord() {
		cout << "空指针也能调用" << endl;
	}

	void showN() {
		if (this == NULL)
		{
			return;
		}
		cout << n << endl;
	}

	//常函数：函数内不可以修改成员属性，除非该属性声明时加上了 mutable  注意const的位置！
	void showConst() const {
		m = 1; // 仅能修改mutable修饰的变量(和静态变量)
		s = 77;
		cout << s << endl;
		cout << "常函数" << endl;

		//this->n = 666;  也不能通过this指针来修改
		// 因为常函数相当于 const Test2 * const this;
	}

	static void ttt() {
		cout << "静态" << endl;
	}


	int n;
	mutable int m;
	static int s;
};
int Test2::s = 123;


void func_32() {
	Test2 t(1);
	Test2 t2(2);
	t.add(t2).add(t2).add(t2); //链式调用


	Test2* nulll_ptr = NULL;
	nulll_ptr->showWord(); // 空指针也能调用方法（要保证其中不会访问到未开辟空间的属性）
	nulll_ptr->showN(); // 通过对this==NULL判断，避免了访问到未开辟空间的属性

	// 常对象：声明对象前加了const 仅仅能调用常函数(和静态函数)，而变量能访问，但是不能修改（除非是静态或mutabel）
	const Test2 tt(123);
	tt.s = 666;
	tt.showConst(); //仅能调用常函数
}