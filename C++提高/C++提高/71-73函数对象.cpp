#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

/*
重载了()运算符的对象，称为函数对象（因为调用（）运算符重载方法时和函数类似也称为仿函数）
但其不是函数，仍然是一个类
但功能比普通的函数强大很多
*/
class MyPrint
{
public:
	MyPrint() {
		this->count = 0;
	}

	int operator ()(string s) {
		cout << s << endl;
		return ++(this->count);
	}

	void showCount() {
		cout << "本函数调用了：" << this->count << "次" << endl;
	}
private:
	int count;
};
/*
对于函数对象（仿函数）
若其返回值是bool类型，那么称其为谓词
接收一个参数的仿函数为一元谓词，两个参数的为二元谓词(在之前的自定义排序中用到过)
*/
class GreaterThanFive {
public:
	bool operator()(int v) {
		return v > 5;
	}
};

class DesVector {
public:
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};


void func_71() {
	MyPrint mp;
	mp("测试1");
	int c = mp("测试2");
	cout << c << endl;
	mp("测试3");
	mp("测试4");
	mp.showCount();

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);

	// 使用算法 find_if(迭代器左, 迭代器右, 一元谓词) 返回迭代器
	auto it = find_if(v.begin(), v.end(), GreaterThanFive()); //使用匿名函数对象 GreaterThanFive()

	if (it != v.end())
	{
		cout << "找到!" << *it << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	sort(v.begin(), v.end(), DesVector()); //使用二元谓词 进行自定义排序
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}