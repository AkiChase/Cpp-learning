#include <iostream>
using namespace std;
#include <deque>
#include <algorithm>

//deque��˫������
//vecotor��ͷ������ɾ��Ԫ�ض�Ч�ʵͣ�������Խ��Խ�ͣ�ֻ��β������ɾ�����٣�
//��dequeͷβ����ɾ��Ч�ʶ�����,���Ƿ���Ԫ�ض��ٶȱ�vector��

template<typename T>
void printDeque(deque<T>& d) {
	// it���������Լ���const���Σ����ֻ���� deque<int>::const_iterator it
	for (auto it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


void func_38() {
	//���캯��
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
	//��ֵ
	d2 = d1;
	printDeque(d2);

	d2.assign(d1.begin(), d1.begin() + 5);
	printDeque(d2);

	d2.assign(3, 666);
	printDeque(d2);

	cout << "-------------------" << endl;
	// ������С������û������������
	cout << "�Ƿ�Ϊ��:" << d1.empty() << endl;
	// ע�� deque����û���������ƣ���Ϊÿ�ζ��ǿ���һ��������������ֻ��size
	cout << "��С:" << d1.size() << endl;
	printDeque(d1);
	d1.resize(6);
	printDeque(d1);

	cout << "-------------------" << endl;
	// �����ɾ��

	d1.push_back(123); // ͷβ��
	d1.push_front(123);
	printDeque(d1);
	d1.pop_back();	// ͷβɾ
	d1.pop_front();
	printDeque(d1);

	d1.insert(d1.begin() + 1, 456); //������Ԫ�ص�λ��
	printDeque(d1);
	d1.insert(d1.begin() + 2, 2, 666); // �ڵ�����ָ��λ�ò���n��ele
	printDeque(d1);
	d1.insert(d1.end() - 1, d2.begin(), d2.begin() + 3); //�ڵ�����ָ��λ�ò��� [n,m)������֮�������
	printDeque(d1);

	auto it = d1.begin();
	it = d1.erase(it); //������һ��Ԫ�ص�λ�õ�����
	//ע���������ָ�룬ԭ���ĵ�����ָ��ܿ�����Ұָ�룬�������鷢�������ɾ��ʱ������»�ȡ
	d1.insert(it, 999);
	printDeque(d1);

	d1.erase(d1.begin() + 5, d1.end());
	printDeque(d1);

	cout << "-------------------" << endl;
	// ���ݴ�ȡ ��vectorһ��
	d1[2] = 123;
	d1.at(3) = 223;
	d1.front() = 333;
	d1.back() = 666;
	printDeque(d1);

	cout << "-------------------" << endl;
	//sort ���� ��Ҫʹ���㷨
	// ����֧��������ʵ�����������������ʹ��sort ��vector
	sort(d1.begin(), d1.end()); // ������[n,m)�ڵ�Ԫ�ؽ�������Ĭ�������������㷨�Ȳ��ᣩ
	printDeque(d1);
}