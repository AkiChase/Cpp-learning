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

	// ȡ���������Ľ���
	vector<int> v3;
	v3.resize(min(v1.size(), v2.size())); //�ȳ�ʼ����СΪ�����и�С��һ��

	// set_inersection  ��ȡ���� ���ؽ�����Χ��end() ��Ϊ������ʵ��v.end()>= ������end
	auto itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for (auto it = v3.begin(); it != itEnd;it++)
	{
		cout << *it << " ";
	}
	cout << endl;


	// ȡ���������Ĳ���
	v3.resize(v1.size()+ v2.size()); //�ȳ�ʼ����СΪ����֮��

	// set_union ͬ��
	itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for (auto it = v3.begin(); it != itEnd; it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// ȡ���������Ĳ
	// ���������  v1��v2�ģ�����v1����v2�ģ�v2��v1�ģ�����v2����v1��
	v3.resize(max(v1.size(),v2.size())); //�ȳ�ʼ����С�����

	cout << "v1��v2�Ĳ��" << endl;
	itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for (auto it = v3.begin(); it != itEnd; it++)
	{
		cout << *it << " ";
	}
	cout << endl;


	cout << "v2��v1�Ĳ��" << endl;
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), v3.begin());
	for (auto it = v3.begin(); it != itEnd; it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}