#include <iostream>
using namespace std;
#include <set>


/*
set/multiset ���ڹ���ʽ�������������ݻ��Զ����򣩣��ײ�ṹ���ö�����ʵ��
set�����в��������ظ�Ԫ��
multiset���������ظ�Ԫ��
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
		return v1 > v2;//����
	}
};


void func_57() {
	// ���캯��

	set<int> s1;
	s1.insert(4);
	s1.insert(1);
	s1.insert(2);
	s1.insert(1); // �ظ�Ԫ�ػ���ʧ
	s1.insert(3);
	printSet(s1);

	set<int> s2(s1); // ��������
	printSet(s2);

	set<int> s3;
	s3 = s2; // ��ֵ
	printSet(s3);

	cout << "----------------------" << endl;
	// ��С����
	cout << "�Ƿ�Ϊ��:" << s1.empty() << endl;
	cout << "��С:" << s1.size() << endl;
	// ����
	s2.insert(666);
	cout << "����ǰ" << endl;
	printSet(s1);
	printSet(s2);
	s1.swap(s2);
	cout << "������" << endl;
	printSet(s1);
	printSet(s2);

	cout << "----------------------" << endl;
	// ���� ɾ��
	s3.clear(); // ���
	for (int i = 0; i < 5; i++)
	{
		s3.insert(i);
	}
	printSet(s3);

	s3.erase(s3.begin()); // ɾ��ָ��λ��
	printSet(s3);
	s3.erase(++s3.begin(), --s3.end()); //ɾ��ָ������
	printSet(s3);
	s3.erase(4); //ɾ��ָ��Ԫ��
	printSet(s3);

	cout << "----------------------" << endl;
	// ���� ͳ��
	for (int i = 0; i < 10; i++)
	{
		s3.insert(i);
	}

	auto it = s3.find(5);//����Ԫ�� ��������������������ڷ���set.end()
	if (it != s3.end())
	{
		cout << "�ҵ�Ԫ��:" << *it << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}

	cout << s3.count(4) << endl; // ͳ��ָ��Ԫ�صĸ�����set��ֻ������0��1����multiset�����ж����


	pair<set<int>::iterator, bool> res = s3.insert(4); //set����᷵��һ�����飬��������������ֵ��
	if (res.second)
	{
		cout << "����ɹ�:" << *res.first << endl;
	}
	else
	{
		cout << "����ʧ��:" << *res.first << endl;
	}


	multiset<int> ms1;
	multiset<int>::const_iterator msit = ms1.insert(666); //multisetֻ�᷵�ص�����
	cout << *msit << endl;

	cout << "----------------------" << endl;
	//���� �ɶԳ��ֵ�����
	pair<int, double> p1(123, 3.1415);
	pair<int, double> p2 = p1;
	p2.first = 666;
	pair<int, double> p3 = make_pair(223, 3.1415);
	cout << p1.first << "\t" << p1.second << endl;
	cout << p2.first << "\t" << p2.second << endl;
	cout << p3.first << "\t" << p3.second << endl;

	cout << "----------------------" << endl;
	// set��������
	// ���÷º��������Ըı�ԭ���������,����ֻ���ڶ����ʱ���ָ���������
	// ע�⣺�����Զ������ݣ�set��֪����ô�������Ա���ָ���Զ���������򣬷��򱨴�

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