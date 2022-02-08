#include <iostream>
using namespace std;

#include <stack>


// stack是一种	先进后出（后进先出）  的数据结构，只有一个出口（只有栈顶的元素可以出和访问，不允许遍历）
// 即进入栈 一层层堆叠 出栈只能从最表面那一层开始出

void func_45() {
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	while (!s.empty())
	{
		cout << "栈顶元素:" << s.top()<< "\t大小:"<< s.size() << endl;
		s.pop();
	}
}