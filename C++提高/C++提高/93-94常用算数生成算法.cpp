#include <iostream>
using namespace std;
#include <numeric>
#include <vector>

void func_93() {
	vector<int> v1;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
	}

	// accumulate �ۼ�
	int sum = accumulate(v1.begin(), v1.end(), 0); // 0Ϊ��ʼ�ۼ�ֵ
	cout << sum << endl;

	// fill ��� ����Χ�����Ϊָ��Ԫ��
	fill(v1.begin(), v1.end(), 666);
	for (auto it=v1.begin();it!=v1.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}