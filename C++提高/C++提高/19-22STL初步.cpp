// STL 标准 模板 库
// 容器 算法 迭代器 仿函数 适配器 空间配置器
// 算法通过迭代器访问容器

#include <iostream>
using namespace std;

#include <algorithm> //算法
#include <vector>

void printFunc(int val) {
	cout << val << endl;
}

void func_19() {

	//最常用的容器为 Vector 可以理解为数组
	vector<int> v; // 也可以存自定义类型的数据，当然包括自定义数据指针
	v.push_back(666);
	v.push_back(20);

	//通过迭代器访问容器的数据
	vector<int>::iterator firstItem = v.begin(); //指向第一个位置的指针，称为起始迭代器
	vector<int>::iterator endItem = v.end(); //结束迭代器，指向容器最后一个元素的下一个位置（所以访问这个是无意义的）

	//但是衍生出遍历方法
	// 第一种
	while (firstItem != endItem)
	{
		cout << *firstItem++ << endl;
	}

	cout << "-------------" << endl;

	// 第二种遍历方式
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	cout << "-------------" << endl;
	//第三种 使用STL的遍历算法 需要包含 algorithm头文件
	for_each(v.begin(), v.end(), printFunc); // 遍历时作为回调调用printFunc(*it)


	cout << "-------------" << endl;

	vector<vector<int>> vv; // 二维数组 嵌套的int数组
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	v1.push_back(1);
	v2.push_back(1);
	v2.push_back(2);
	v3.push_back(1);
	v3.push_back(2);
	v3.push_back(3);
	vv.push_back(v1);
	vv.push_back(v2);
	vv.push_back(v3);

	for (vector<vector<int>>::iterator it = vv.begin(); it != vv.end(); it++)
	{
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << *vit << " ";
		}
		cout << endl;
	}
}