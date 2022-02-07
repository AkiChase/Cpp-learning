#include <iostream>
using namespace std;
#include <vector>

//vector和数组非常相似
//是动态扩展的（每次扩容都要新建空间，拷贝过去，然后释放原有空间）

template <typename T>
void printVector(vector<T>& v) {
	for (auto it = v.begin(); it != v.end(); it++) // 长的类型就用auto 省事
	{
		cout << *it << " ";
	}
	cout << endl;
}

void func_31() {
	//构造函数
	vector<int> v1; // 最普通的无参构造
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	printVector(v1);

	vector<int>v2(v1.begin() + 1, v1.end() - 1); //使用区间的方式构造
	printVector(v2);

	vector<int>v3(5, 6); // n个m 5个6
	printVector(v3);

	vector<int>v4(v3); //拷贝构造
	printVector(v4);

	cout << "-------------------" << endl;
	// 赋值

	v2 = v1; // 直接赋值
	printVector(v2);

	v2.assign(v1.begin() + 1, v1.end() - 1); // 将 n到m之间的数据拷贝赋值给v2
	printVector(v2);

	v3.assign(10, 6); // 将n个m赋值给v3
	printVector(v3);
	cout << "-------------------" << endl;

	// vector 的容量和大小
	cout << v1.empty() << endl; //判断是否为空
	cout << v1.capacity() << endl;
	cout << v1.size() << endl;
	v1.resize(10); // 重新指定容器长度，若变长则填充默认值(一般是0)，变短则移除多余的
	printVector(v1);

	v1.resize(15, 6); //重新指定容器长度 并指定默认值为6
	printVector(v1);
}