#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

/*
������()������Ķ��󣬳�Ϊ����������Ϊ���ã�����������ط���ʱ�ͺ�������Ҳ��Ϊ�º�����
���䲻�Ǻ�������Ȼ��һ����
�����ܱ���ͨ�ĺ���ǿ��ܶ�
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
		cout << "�����������ˣ�" << this->count << "��" << endl;
	}
private:
	int count;
};
/*
���ں������󣨷º�����
���䷵��ֵ��bool���ͣ���ô����Ϊν��
����һ�������ķº���ΪһԪν�ʣ�����������Ϊ��Ԫν��(��֮ǰ���Զ����������õ���)
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
	mp("����1");
	int c = mp("����2");
	cout << c << endl;
	mp("����3");
	mp("����4");
	mp.showCount();

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);

	// ʹ���㷨 find_if(��������, ��������, һԪν��) ���ص�����
	auto it = find_if(v.begin(), v.end(), GreaterThanFive()); //ʹ�������������� GreaterThanFive()

	if (it != v.end())
	{
		cout << "�ҵ�!" << *it << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}

	sort(v.begin(), v.end(), DesVector()); //ʹ�ö�Ԫν�� �����Զ�������
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}