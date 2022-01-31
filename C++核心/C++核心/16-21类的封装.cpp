#include <iostream>
#include <string>
using namespace std;
#define PI 3.1415926


// struct 和 class 基本一样，都能写成类
// 只是默认的权限不同，前者默认为公共，后者默认为私有


// 定义一个圆的类
class Circle
{
	//访问权限：公开的部分
public:
	//类中的属性和行为都称为 成员 如成员属性，成员变量，成员函数，成员方法
	int r; // 半径
	double getZC() {
		return 2 * PI * r;
	}

	string getName() { //私有成员可以用这种方式具体的设置读或写的权限
		// 可以写逻辑，对name进行初始化
		return name;
	}

	bool setName(string newName) {
		if (newName.length() > 6) // 对写的条件进行深入判断(判断传入数据是否有效)
		{
			return false;
		}
		else
		{
			name = newName;
			return true;
		}
	}

	//public等等可以多次书写
public:
	string name = "圆";

	//保护成员：内部可以访问，外部不能访问 但是！！子类可以访问！！（继承的时候用）
protected:
	string son = "儿咂";

	// 私有成员：内部可以访问，外部不能访问 子类也不能访问
private:
	string secret = "私人";
};

void func_16() {
	// 实例化为对象c
	Circle c;
	c.r = 5;
	cout << "圆的周长为=" << c.getZC() << endl;

	cout << c.getName() << endl;
	c.setName("一二三四五"); // 注意一个汉字2个长度
	cout << c.getName() << endl;
	c.setName("三个字"); // 注意一个汉字2个长度
	cout << c.getName() << endl;

}
