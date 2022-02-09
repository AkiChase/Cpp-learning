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
	//�����Զ������ͣ���Ҫ����==��������ܽ��в���
	bool operator==(const MyData6& d) const
	{
		return d.num == this->num;
	}

	bool operator<(const MyData6& d) const //ע���ں��������const����
	{
		return this->num < d.num;
	}

	int num;

};

class MyData6Sort {
public:
	bool operator()(MyData6& d1, MyData6& d2) {
		return d1.num < d2.num; //���� ע��Ҫ����
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
		cout << "�ҵ�:" << it->num << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}

	// find_if ��Ҫ�º���
	// ��find���Ƿ����ҵ��ĵ�һ��
	it = find_if(v.begin(), v.end(), MyData6FindIF());
	if (it != v.end())
	{
		cout << "�ҵ�:" << it->num << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}

	//ѭ����������find_if
	auto startIt = v.begin();
	cout << "����find_if���:" << endl;
	while ((startIt = find_if(startIt, v.end(), MyData6FindIF())) != v.end())
	{
		cout << startIt->num << " ";
		++startIt;
	}
	cout << endl;

	//adjacent_find ���� ���ڵ� �ظ�Ԫ�� �����򷵻�����Ԫ���е�һ��Ԫ�صĵ�����
	it = adjacent_find(v.begin(), v.end());
	if (it != v.end())
	{
		cout << "�ҵ������ظ�Ԫ��:" << it->num << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}

	//binary_search ���ֲ��ҷ�������Ԫ���Ƿ���� bool����
	//Ҫ�����������ģ��������������׼ȷ����
	// ��Ҫ�������ʹ��sort ����Ҫ�����򣡣�����
	// ע���Զ������� ��Ҫ����< !!

	sort(v.begin(), v.end(), MyData6Sort());
	if (binary_search(v.begin(), v.end(), MyData6(1))) {
		cout << "�ҵ���" << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}

	// count ͳ�� ������find ֻ�ǻ����һ��������
	cout << count(v.begin(), v.end(), MyData6(3)) << endl;

	// count_if ����ͳ�� Ҳ��������find_if
	cout << count_if(v.begin(), v.end(), MyData6FindIF()) << endl;
}