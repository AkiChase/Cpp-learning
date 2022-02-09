#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

class MyData6
{
public:
	MyData6(int n) {
		this->num = n;
	}
	//对于自定义类型：需要重载==运算符才能进行查找
	bool operator==(const MyData6& d) const
	{
		return d.num == this->num;
	}

	bool operator<(const MyData6& d) const //注意在函数后加上const修饰
	{
		return this->num < d.num;
	}

	int num;

};

class MyData6Sort {
public:
	bool operator()(MyData6& d1, MyData6& d2) {
		return d1.num < d2.num; //升序 注意要升序
	}
};

class MyData6FindIF {
public:
	bool operator()(MyData6& d) {
		return d.num >= 3;
	}
};

void func_79() {
	vector<MyData6> v;
	v.push_back(MyData6(3));
	v.push_back(MyData6(1));
	v.push_back(MyData6(3));
	v.push_back(MyData6(2));
	v.push_back(MyData6(2));
	v.push_back(MyData6(4));

	//find
	auto it = find(v.begin(), v.end(), 2);
	if (it != v.end())
	{
		cout << "找到:" << it->num << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	// find_if 需要仿函数
	// 两find都是返回找到的第一个
	it = find_if(v.begin(), v.end(), MyData6FindIF());
	if (it != v.end())
	{
		cout << "找到:" << it->num << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	//循环查找所有find_if
	auto startIt = v.begin();
	cout << "所有find_if结果:" << endl;
	while ((startIt = find_if(startIt, v.end(), MyData6FindIF())) != v.end())
	{
		cout << startIt->num << " ";
		++startIt;
	}
	cout << endl;

	//adjacent_find 查找 相邻的 重复元素 若有则返回相邻元素中第一个元素的迭代器
	it = adjacent_find(v.begin(), v.end());
	if (it != v.end())
	{
		cout << "找到相邻重复元素:" << it->num << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	//binary_search 二分查找法：返回元素是否存在 bool类型
	//要求必须是有序的，如果非有序结果不准确！！
	// 必要情况下先使用sort 而且要是升序！！！！
	// 注意自定义类型 需要重载< !!

	sort(v.begin(), v.end(), MyData6Sort());
	if (binary_search(v.begin(), v.end(), MyData6(1))) {
		cout << "找到了" << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	// count 统计 类似于find 只是会遍历一遍来计数
	cout << count(v.begin(), v.end(), MyData6(3)) << endl;

	// count_if 条件统计 也是类似于find_if
	cout << count_if(v.begin(), v.end(), MyData6FindIF()) << endl;
}