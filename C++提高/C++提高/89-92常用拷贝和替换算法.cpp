#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

template <typename T>
void printVector(vector<T>& v);

class EqualTo666
{
public:
	bool operator()(int val) {
		return val == 666;
	}
};

void func_89() {
	vector<int> v1;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	vector<int> v2;
	v2.resize(v1.size() - 1); //ע����ǰ������С

	// copy ����
	copy(v1.begin() + 1, v1.end(), v2.begin());
	printVector(v2);


	v2.push_back(1);
	v2.push_back(1);
	v2.push_back(1);
	printVector(v2);
	// replace �������ڵ�ĳֵ�ľ�Ԫ���滻Ϊ��Ԫ��
	replace(v2.begin(), v2.end(), 1, 666);
	printVector(v2);

	// replace_if Ҫ�ṩһ��ν�ʣ������� ����ν�ʵ��滻Ϊ��Ԫ��
	replace_if(v2.begin(), v2.end(), EqualTo666(), 123);
	printVector(v2);

	// swap ������������,��ʵ���ǽ�����ָ���ָ��Ҫ����������ͬ��������
	cout << "����ǰ" << endl; printVector(v1); printVector(v2);
	swap(v1, v2);
	cout << "������" << endl; printVector(v1); printVector(v2);
}