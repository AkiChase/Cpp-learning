#include <iostream>
using namespace std;

#include <stack>


// stack��һ��	�Ƚ����������ȳ���  �����ݽṹ��ֻ��һ�����ڣ�ֻ��ջ����Ԫ�ؿ��Գ��ͷ��ʣ������������
// ������ջ һ���ѵ� ��ջֻ�ܴ��������һ�㿪ʼ��

void func_45() {
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	while (!s.empty())
	{
		cout << "ջ��Ԫ��:" << s.top()<< "\t��С:"<< s.size() << endl;
		s.pop();
	}
}