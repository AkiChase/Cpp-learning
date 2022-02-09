#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

template <typename T>
void printVector(vector<T>& v);

class EqualTo666
{
public:
	bool operator()(int val) {
		return val == 666;
	}
};

void func_89() {
	vector<int> v1;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	vector<int> v2;
	v2.resize(v1.size() - 1); //注意提前调整大小

	// copy 拷贝
	copy(v1.begin() + 1, v1.end(), v2.begin());
	printVector(v2);


	v2.push_back(1);
	v2.push_back(1);
	v2.push_back(1);
	printVector(v2);
	// replace 将区间内的某值的旧元素替换为新元素
	replace(v2.begin(), v2.end(), 1, 666);
	printVector(v2);

	// replace_if 要提供一个谓词（条件） 满足谓词的替换为新元素
	replace_if(v2.begin(), v2.end(), EqualTo666(), 123);
	printVector(v2);

	// swap 互换两个容器,其实就是交换了指针的指向：要求两个容器同数据类型
	cout << "互换前" << endl; printVector(v1); printVector(v2);
	swap(v1, v2);
	cout << "互换后" << endl; printVector(v1); printVector(v2);
}