#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <ctime>
void func_85() {
	vector<int> v1;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
	}

	// sort(iterator beg, iterator end, ν��)   ν�ʲ�����ʹ�����õ�����

	//random_shuffle ����˳�� ע���������������
	srand((unsigned int)time(NULL));
	random_shuffle(v1.begin(), v1.end());
	for (auto it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	vector<int> v2;
	for (int i = 9; i >= 0; i--)
	{
		v2.push_back(i);
	}

	// merge() �ϲ����������������������У�Ҫ����������һ��Ҫ�����򣡶�����������ͬ
	vector<int> v3;
	v3.resize(v1.size() + v2.size()); // ע����ǰ����������С

	// ע�������������������
	sort(v2.begin(), v2.end());
	sort(v1.begin(), v1.end());

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for (auto it = v3.begin(); it != v3.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;


	// reverse Ԫ�ط���
	reverse(v3.begin(), v3.end()); //Ԫ�ط���
	for (auto it = v3.begin(); it != v3.end(); it++)
	{
		cout << *it << " ";
	}
}