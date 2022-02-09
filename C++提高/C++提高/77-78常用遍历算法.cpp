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

	// for_each ����
	for_each(v.begin(), v.end(), print01); //��������ͨ������Ҳ�����÷º��� 
	cout << endl;

	// transform(Դ��ʼ������, Դ����������, Ŀ�꿪ʼ, ������������) ��һ������������ת������һ������
	vector<int> vt;
	vt.resize(v.size()); // ע��Ҫ�ȳ�ʼ������Ȼ����Ӧλ�õĵ�����
	transform(v.begin(), v.end(), vt.begin(), transFunc);
	for_each(vt.begin(), vt.end(), print01);
}