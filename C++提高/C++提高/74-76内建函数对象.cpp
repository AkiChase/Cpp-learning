#include <iostream>
using namespace std;

#include <functional>
#include <vector>
#include <algorithm>
/*
STL�ڽ���һЩ�������� functionalͷ�ļ���
�����º���
��ϵ�º���
�߼��º���
*/

void func_74() {
	//����
	negate<int> ne; //ȡ���º���
	cout << ne(666) << endl;
	cout << plus<int>()(1, 2) << endl; // ʹ��������plus<int>()

	//��ϵ
	// greater<T> return v1>v2 �Ķ�Ԫν�� ���Կ���������������
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	sort(v.begin(), v.end(), greater<int>()); //ʹ��������������
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//�߼� �ǡ�����
	vector<bool> vv;
	vv.push_back(false);
	vv.push_back(false);
	vv.push_back(true);
	vv.push_back(true);

	logical_not<bool> l_not;
	vector<bool> vvv;
	vvv.resize(vv.size());
	transform(vv.begin(), vv.end(), vvv.begin(), l_not); // ����ÿ��ִ��not
	for (auto it = vvv.begin(); it != vvv.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}