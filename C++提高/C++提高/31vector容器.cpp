#include <iostream>
using namespace std;
#include <vector>

//vector������ǳ�����
//�Ƕ�̬��չ�ģ�ÿ�����ݶ�Ҫ�½��ռ䣬������ȥ��Ȼ���ͷ�ԭ�пռ䣩

template <typename T>
void printVector(vector<T>& v) {
	for (auto it = v.begin(); it != v.end(); it++) // �������;���auto ʡ��
	{
		cout << *it << " ";
	}
	cout << endl;
}

void func_31() {
	//���캯��
	vector<int> v1; // ����ͨ���޲ι���
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	printVector(v1);

	vector<int>v2(v1.begin() + 1, v1.end() - 1); //ʹ������ķ�ʽ����
	printVector(v2);

	vector<int>v3(5, 6); // n��m 5��6
	printVector(v3);

	vector<int>v4(v3); //��������
	printVector(v4);

	cout << "-------------------" << endl;
	// ��ֵ

	v2 = v1; // ֱ�Ӹ�ֵ
	printVector(v2);

	v2.assign(v1.begin() + 1, v1.end() - 1); // �� n��m֮������ݿ�����ֵ��v2
	printVector(v2);

	v3.assign(10, 6); // ��n��m��ֵ��v3
	printVector(v3);
	cout << "-------------------" << endl;

	// vector �������ʹ�С
	cout << v1.empty() << endl; //�ж��Ƿ�Ϊ��
	cout << v1.capacity() << endl;
	cout << v1.size() << endl;
	v1.resize(10); // ����ָ���������ȣ����䳤�����Ĭ��ֵ(һ����0)��������Ƴ������
	printVector(v1);

	v1.resize(15, 6); //����ָ���������� ��ָ��Ĭ��ֵΪ6
	printVector(v1);
}