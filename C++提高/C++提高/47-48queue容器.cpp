#include <iostream>
using namespace std;

#include <queue>

// queue һ�ֶ������� �Ƚ��ȳ����������ڣ���βֻ�ܽ����ݣ���ӣ�����ͷֻ�ܳ����ݣ����ӣ�
// ���Է��ʶ�ͷ�Ͷ�λ

void func_47() {
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);


	while (!q.empty())
	{
		cout << "��ͷ:" << q.front() << endl;
		cout << "��β:" << q.back() << endl;
		cout << "��С:" << q.size() << endl;
		cout << "--------------------" << endl;
		q.pop(); // ��ͷ��
	}
	cout << endl;
}