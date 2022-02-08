#include <iostream>
using namespace std;

#include <list>

//list ����
//�Ƿ������ķ�ʽ����ģ�˫��ѭ������
//ÿ���ڵ��������֣�һ�����Ǵ����������һ������ָ���ϡ��¸��ڵ��ָ������λ��ָ����������
// �ŵ㣺���Զ�����λ�ý��п��ٲ����ɾ��
// ȱ�㣺 ���������ٶ�û������죨ÿ�ζ�Ҫͨ��ָ���������һ�ڵ㣩
//		  ռ�ÿռ�������

//list�еĵ�����ֻ֧��ǰ�ƺͺ��ƣ�����˫�������������������ʣ�

template <typename T>
void printList(list<T>& l) {
	for (auto it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

bool mySort(int v1, int v2) {
	return v1 > v2; //����
}

void func_49() {
	//���캯��
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	printList(l1);

	list<int> l2(++l1.begin(), --l1.end()); // ��Ϊ��˫������� ������Ծ���� ֻ��ǰ���ƶ�
	printList(l2);

	list<int> l3(l1); //��������
	printList(l3);

	list<int> l4(5, 666);
	printList(l4);


	cout << "------------------------" << endl;
	// ��ֵ ����
	l2 = l1;
	printList(l2);
	
	l2.assign(++l1.begin(), l1.end());
	printList(l2);

	l2.assign(5, 666);
	printList(l2);

	cout << "����ǰ" << endl;
	printList(l1);
	printList(l2);
	l2.swap(l1);

	cout << "������" << endl;
	printList(l1);
	printList(l2);

	cout << "------------------------" << endl;
	// ��С����
	cout << l1.size() << endl;;
	cout << l1.empty() << endl;;
	l1.resize(3);
	printList(l1);
	l1.resize(10, 6);
	printList(l1);

	cout << "------------------------" << endl;
	// ���� ɾ�� ͬvector
	// ���Ƕ���һ�� remove
	l1.remove(666); //ɾ���ʹ���ֵ��ȵ�����Ԫ��
	printList(l1);

	cout << "------------------------" << endl;
	// ���ݴ�ȡ ������font() back() �������һ��������
	cout << l2.front() << " " << l2.back() << endl;

	cout << "------------------------" << endl;
	// ��ת ����
	l2.push_back(2);
	printList(l2);
	l2.reverse();
	printList(l2);
	l2.sort(); // ע�����sort��list�ṩ�ģ������㷨���ṩ��
	printList(l2);
	l2.sort(mySort); // �Զ����������,�����Զ�������ͬ��
	printList(l2);

}