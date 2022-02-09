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

	// sort(iterator beg, iterator end, 谓词)   谓词不填则使用内置的升序

	//random_shuffle 打乱顺序 注意设置随机数种子
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

	// merge() 合并两个容器到第三个容器中：要求两个容器一定要先排序！而且排序方向相同
	vector<int> v3;
	v3.resize(v1.size() + v2.size()); // 注意提前调整容器大小

	// 注意对两个容器进行排序
	sort(v2.begin(), v2.end());
	sort(v1.begin(), v1.end());

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for (auto it = v3.begin(); it != v3.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;


	// reverse 元素反序
	reverse(v3.begin(), v3.end()); //元素反序
	for (auto it = v3.begin(); it != v3.end(); it++)
	{
		cout << *it << " ";
	}
}