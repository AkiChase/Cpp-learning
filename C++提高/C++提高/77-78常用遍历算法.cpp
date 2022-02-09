#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

void print01(int val) {
	cout << val << " ";
}

int transFunc(int val) {
	return val + 100;
}

void func_77() {

	vector<int> v;
	for (int i = 0; i < 10 ; i++)
	{
		v.push_back(i);
	}

	// for_each 遍历
	for_each(v.begin(), v.end(), print01); //可以用普通函数，也可以用仿函数 
	cout << endl;

	// transform(源开始迭代器, 源结束迭代器, 目标开始, 函数或函数对象) 将一个容器内数据转化到另一个容器
	vector<int> vt;
	vt.resize(v.size()); // 注意要先初始化，不然无相应位置的迭代器
	transform(v.begin(), v.end(), vt.begin(), transFunc);
	for_each(vt.begin(), vt.end(), print01);
}