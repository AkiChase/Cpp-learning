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

	// accumulate 累加
	int sum = accumulate(v1.begin(), v1.end(), 0); // 0为起始累加值
	cout << sum << endl;

	// fill 填充 将范围内填充为指定元素
	fill(v1.begin(), v1.end(), 666);
	for (auto it=v1.begin();it!=v1.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}