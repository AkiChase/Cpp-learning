#include <iostream>
using namespace std;

#include <list>

//list 链表
//是非连续的方式储存的，双向循环链表
//每个节点有两部分，一部分是储存的数据另一部分是指向上、下个节点的指针域（首位的指针域相连）
// 优点：可以对任意位置进行快速插入或删除
// 缺点： 容器遍历速度没有数组快（每次都要通过指针域访问下一节点）
//		  占用空间比数组大

//list中的迭代器只支持前移和后移，属于双向迭代器（不能随机访问）

template <typename T>
void printList(list<T>& l) {
	for (auto it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

bool mySort(int v1, int v2) {
	return v1 > v2; //降序
}

void func_49() {
	//构造函数
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	printList(l1);

	list<int> l2(++l1.begin(), --l1.end()); // 因为是双相迭代器 不能跳跃访问 只能前后移动
	printList(l2);

	list<int> l3(l1); //拷贝构造
	printList(l3);

	list<int> l4(5, 666);
	printList(l4);


	cout << "------------------------" << endl;
	// 赋值 交换
	l2 = l1;
	printList(l2);
	
	l2.assign(++l1.begin(), l1.end());
	printList(l2);

	l2.assign(5, 666);
	printList(l2);

	cout << "交换前" << endl;
	printList(l1);
	printList(l2);
	l2.swap(l1);

	cout << "交换后" << endl;
	printList(l1);
	printList(l2);

	cout << "------------------------" << endl;
	// 大小操作
	cout << l1.size() << endl;;
	cout << l1.empty() << endl;;
	l1.resize(3);
	printList(l1);
	l1.resize(10, 6);
	printList(l1);

	cout << "------------------------" << endl;
	// 插入 删除 同vector
	// 但是多了一种 remove
	l1.remove(666); //删除和传入值相等的所有元素
	printList(l1);

	cout << "------------------------" << endl;
	// 数据存取 仅能用font() back() 或迭代器一个个访问
	cout << l2.front() << " " << l2.back() << endl;

	cout << "------------------------" << endl;
	// 反转 排序
	l2.push_back(2);
	printList(l2);
	l2.reverse();
	printList(l2);
	l2.sort(); // 注意这个sort是list提供的，不是算法中提供的
	printList(l2);
	l2.sort(mySort); // 自定义排序规则,对于自定义数据同理
	printList(l2);

}