#include <iostream>
using namespace std;

#include <map>

/*
map/multimap���ڹ���ʽ������������ʵ��
map������Ԫ�ض���pair<key, val> ��ֵ��
����Ԫ�ض������keyֵ����
���Ը���keyֵ�����ҵ�valueֵ

map�в��������ظ��ļ�
��multimap������ظ�
*/

template <typename T1, typename T2>
void printMap(map<T1, T2>m) {
	for (auto it = m.begin(); it != m.end(); it++)
	{
		cout << "key= " << it->first << "\tval= " << it->second << endl;
	}
	cout << endl;
}


class MapCompare
{
public:
	bool operator()(int k1, int k2) {
		return k1 > k2; //����
	}
};

void func_65() {
	map<int, int> m1;
	m1.insert(pair<int, int>(1, 10)); // ������������ , pair�е����ͻᱻǿ��ת��Ϊmap�е�����
	m1.insert(pair<int, int>(5, 50)); //���Զ�����key����
	m1.insert(pair<int, int>(6, 60));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(4, 40));
	printMap(m1);

	map<int, int>m2(m1); //��������
	printMap(m2);
	map<int, int>m3 = m1; //��ֵ
	printMap(m3);

	cout << "---------------------" << endl;
	// ��С�ͽ���
	cout << "�Ƿ�Ϊ��" << m1.empty() << endl;
	cout << "��С" << m1.size() << endl;
	m2.clear();
	m2.insert(pair<int, int>(6, 60));
	m2.insert(pair<int, int>(3, 30));
	m2.insert(pair<int, int>(2, 20));
	cout << "����ǰ" << endl;
	printMap(m1);
	printMap(m2);

	m1.swap(m2);
	cout << "������" << endl;
	printMap(m1);
	printMap(m2);

	cout << "---------------------" << endl;
	//���� ɾ��
	// ��4�ֲ��뷽ʽ
	m3.clear(); // ���
	m3.insert(pair<int, int>(1, 123));
	m3.insert(make_pair(2, 223)); //�Ƚϼ�
	m3.insert(map<int, int>::value_type(3, 333));
	m3[4] = 444; // ע�����ַ�ʽ��m[key] ��key����������ȳ�ʼ��һ��m[key] = 0;
	// һ�㲻ʹ�����ַ�ʽ���룬������֪key���������ַ�ʽ����
	printMap(m3);

	//ɾ��
	m3.erase(m3.begin()); //��������ɾ��
	m3.erase(4); // ����ɾ�������޴�key��ɾ��
	printMap(m3);

	cout << "---------------------" << endl;
	//���� ͳ��
	auto mit = m1.find(2); // ����key�Ƿ���ڣ����ڷ�����������������ڷ���map.end()
	if (mit != m1.end())
	{
		cout << "�ҵ�Ԫ��--key=" << mit->first << "\tval=" << mit->second << endl;
	}
	else
	{
		cout << "δ�ҵ�Ԫ��" << endl;
	}
	cout << "����:" << m1.count(2) << endl;

	cout << "---------------------" << endl;
	//���� �����÷º���
	map<int, int, MapCompare> m4;
	m4.insert(make_pair(1, 1));
	m4.insert(make_pair(2, 2));
	m4.insert(make_pair(3, 3));
	for (auto it=m4.begin();it!=m4.end();it++)
	{
		cout << "key= " << it->first << "\tval= " << it->second << endl;
	}
}