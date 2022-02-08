#include <iostream>
using namespace std;
#include <deque>
#include <algorithm>

//deque是双端数组
//vecotor对头部插入删除元素对效率低，数据量越大越低（只有尾部插入删除快速）
//而deque头尾插入删除效率都快速,但是访问元素对速度比vector慢

template<typename T>
void printDeque(deque<T>& d) {
	// it迭代器可以加上const修饰，变成只读的 deque<int>::const_iterator it
	for (auto it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


void func_38() {
	//构造函数
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	deque<int> d2(10, 6);
	printDeque(d2);

	deque<int> d3(d1.begin() + 1, d1.begin() + 5);
	printDeque(d3);

	deque<int> d4(d1);
	printDeque(d4);

	cout << "-------------------" << endl;
	//赋值
	d2 = d1;
	printDeque(d2);

	d2.assign(d1.begin(), d1.begin() + 5);
	printDeque(d2);

	d2.assign(3, 666);
	printDeque(d2);

	cout << "-------------------" << endl;
	// 容器大小操作（没有容量操作）
	cout << "是否为空:" << d1.empty() << endl;
	// 注意 deque容器没有容量限制，因为每次都是开辟一个缓冲区！！！只有size
	cout << "大小:" << d1.size() << endl;
	printDeque(d1);
	d1.resize(6);
	printDeque(d1);

	cout << "-------------------" << endl;
	// 插入和删除

	d1.push_back(123); // 头尾插
	d1.push_front(123);
	printDeque(d1);
	d1.pop_back();	// 头尾删
	d1.pop_front();
	printDeque(d1);

	d1.insert(d1.begin() + 1, 456); //返回新元素的位置
	printDeque(d1);
	d1.insert(d1.begin() + 2, 2, 666); // 在迭代器指向位置插入n个ele
	printDeque(d1);
	d1.insert(d1.end() - 1, d2.begin(), d2.begin() + 3); //在迭代器指向位置插入 [n,m)迭代器之间的数据
	printDeque(d1);

	auto it = d1.begin();
	it = d1.erase(it); //返回下一个元素的位置迭代器
	//注意迭代器是指针，原来的迭代器指针很可能是野指针，所以数组发生插入和删除时最好重新获取
	d1.insert(it, 999);
	printDeque(d1);

	d1.erase(d1.begin() + 5, d1.end());
	printDeque(d1);

	cout << "-------------------" << endl;
	// 数据存取 和vector一样
	d1[2] = 123;
	d1.at(3) = 223;
	d1.front() = 333;
	d1.back() = 666;
	printDeque(d1);

	cout << "-------------------" << endl;
	//sort 排序 需要使用算法
	// 对于支持随机访问迭代器的容器都可以使用sort 如vector
	sort(d1.begin(), d1.end()); // 对区间[n,m)内的元素进行排序，默认升序（其他的算法先不提）
	printDeque(d1);
}