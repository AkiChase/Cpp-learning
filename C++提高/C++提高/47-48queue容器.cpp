#include <iostream>
using namespace std;

#include <queue>

// queue 一种队列容器 先进先出，有两个口，队尾只能进数据（入队），队头只能出数据（出队）
// 可以访问队头和队位

void func_47() {
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);


	while (!q.empty())
	{
		cout << "队头:" << q.front() << endl;
		cout << "队尾:" << q.back() << endl;
		cout << "大小:" << q.size() << endl;
		cout << "--------------------" << endl;
		q.pop(); // 队头出
	}
	cout << endl;
}