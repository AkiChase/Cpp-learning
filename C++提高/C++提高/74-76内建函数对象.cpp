#include <iostream>
using namespace std;

#include <functional>
#include <vector>
#include <algorithm>
/*
STL内建了一些函数对象 functional头文件中
算数仿函数
关系仿函数
逻辑仿函数
*/

void func_74() {
	//算数
	negate<int> ne; //取反仿函数
	cout << ne(666) << endl;
	cout << plus<int>()(1, 2) << endl; // 使用匿名的plus<int>()

	//关系
	// greater<T> return v1>v2 的二元谓词 所以可以用在数组排序
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	sort(v.begin(), v.end(), greater<int>()); //使用匿名函数对象
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//逻辑 非、或、与
	vector<bool> vv;
	vv.push_back(false);
	vv.push_back(false);
	vv.push_back(true);
	vv.push_back(true);

	logical_not<bool> l_not;
	vector<bool> vvv;
	vvv.resize(vv.size());
	transform(vv.begin(), vv.end(), vvv.begin(), l_not); // 即对每个执行not
	for (auto it = vvv.begin(); it != vvv.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}