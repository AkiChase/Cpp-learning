#include <iostream>
using namespace std;
#include <set>


/*
set/multiset 属于关联式容器（插入数据会自动排序），底层结构是用二叉树实现
set容器中不允许有重复元素
multiset中允许有重复元素
*/

template <typename T>
void printSet(set<T>& s) {
	for (auto it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

class MyCompare
{
public:
	bool operator () (int v1, int v2) {
		return v1 > v2;//降序
	}
};


void func_57() {
	// 构造函数

	set<int> s1;
	s1.insert(4);
	s1.insert(1);
	s1.insert(2);
	s1.insert(1); // 重复元素会消失
	s1.insert(3);
	printSet(s1);

	set<int> s2(s1); // 拷贝构造
	printSet(s2);

	set<int> s3;
	s3 = s2; // 赋值
	printSet(s3);

	cout << "----------------------" << endl;
	// 大小操作
	cout << "是否为空:" << s1.empty() << endl;
	cout << "大小:" << s1.size() << endl;
	// 交换
	s2.insert(666);
	cout << "交换前" << endl;
	printSet(s1);
	printSet(s2);
	s1.swap(s2);
	cout << "交换后" << endl;
	printSet(s1);
	printSet(s2);

	cout << "----------------------" << endl;
	// 插入 删除
	s3.clear(); // 清空
	for (int i = 0; i < 5; i++)
	{
		s3.insert(i);
	}
	printSet(s3);

	s3.erase(s3.begin()); // 删除指向位置
	printSet(s3);
	s3.erase(++s3.begin(), --s3.end()); //删除指向区间
	printSet(s3);
	s3.erase(4); //删除指定元素
	printSet(s3);

	cout << "----------------------" << endl;
	// 查找 统计
	for (int i = 0; i < 10; i++)
	{
		s3.insert(i);
	}

	auto it = s3.find(5);//查找元素 返回其迭代器，若不存在返回set.end()
	if (it != s3.end())
	{
		cout << "找到元素:" << *it << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	cout << s3.count(4) << endl; // 统计指定元素的个数（set中只可能是0或1，但multiset可能有多个）


	pair<set<int>::iterator, bool> res = s3.insert(4); //set插入会返回一个对组，（迭代器，布尔值）
	if (res.second)
	{
		cout << "插入成功:" << *res.first << endl;
	}
	else
	{
		cout << "插入失败:" << *res.first << endl;
	}


	multiset<int> ms1;
	multiset<int>::const_iterator msit = ms1.insert(666); //multiset只会返回迭代器
	cout << *msit << endl;

	cout << "----------------------" << endl;
	//对组 成对出现的数据
	pair<int, double> p1(123, 3.1415);
	pair<int, double> p2 = p1;
	p2.first = 666;
	pair<int, double> p3 = make_pair(223, 3.1415);
	cout << p1.first << "\t" << p1.second << endl;
	cout << p2.first << "\t" << p2.second << endl;
	cout << p3.first << "\t" << p3.second << endl;

	cout << "----------------------" << endl;
	// set容器排序
	// 利用仿函数，可以改变原有排序规则,但是只能在定义的时候就指定排序规则
	// 注意：对于自定义数据，set不知道怎么排序，所以必须指定自定义排序规则，否则报错

	set<int, MyCompare> s4;
	s4.insert(1);
	s4.insert(2);
	s4.insert(3);
	s4.insert(4);
	for (auto it = s4.begin(); it != s4.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;


}