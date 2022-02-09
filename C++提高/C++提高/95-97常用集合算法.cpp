#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

template <typename T>
void printVector(vector<T>& s);

void func_95() {
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	printVector(v1); printVector(v2);

	// 取两个容器的交集
	vector<int> v3;
	v3.resize(min(v1.size(), v2.size())); //先初始化大小为两者中更小的一个

	// set_inersection  获取交集 返回交集范围的end() 因为交集的实际v.end()>= 交集的end
	auto itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for (auto it = v3.begin(); it != itEnd;it++)
	{
		cout << *it << " ";
	}
	cout << endl;


	// 取两个容器的并集
	v3.resize(v1.size()+ v2.size()); //先初始化大小为两者之和

	// set_union 同上
	itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for (auto it = v3.begin(); it != itEnd; it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// 取两个容器的差集
	// 有两种情况  v1和v2的，是在v1不在v2的；v2和v1的，是在v2不在v1的
	v3.resize(max(v1.size(),v2.size())); //先初始化大小更大的

	cout << "v1和v2的差集：" << endl;
	itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for (auto it = v3.begin(); it != itEnd; it++)
	{
		cout << *it << " ";
	}
	cout << endl;


	cout << "v2和v1的差集：" << endl;
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), v3.begin());
	for (auto it = v3.begin(); it != itEnd; it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}