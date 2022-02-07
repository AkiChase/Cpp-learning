// STL ��׼ ģ�� ��
// ���� �㷨 ������ �º��� ������ �ռ�������
// �㷨ͨ����������������

#include <iostream>
using namespace std;

#include <algorithm> //�㷨
#include <vector>

void printFunc(int val) {
	cout << val << endl;
}

void func_19() {

	//��õ�����Ϊ Vector �������Ϊ����
	vector<int> v; // Ҳ���Դ��Զ������͵����ݣ���Ȼ�����Զ�������ָ��
	v.push_back(666);
	v.push_back(20);

	//ͨ����������������������
	vector<int>::iterator firstItem = v.begin(); //ָ���һ��λ�õ�ָ�룬��Ϊ��ʼ������
	vector<int>::iterator endItem = v.end(); //������������ָ���������һ��Ԫ�ص���һ��λ�ã����Է��������������ģ�

	//������������������
	// ��һ��
	while (firstItem != endItem)
	{
		cout << *firstItem++ << endl;
	}

	cout << "-------------" << endl;

	// �ڶ��ֱ�����ʽ
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	cout << "-------------" << endl;
	//������ ʹ��STL�ı����㷨 ��Ҫ���� algorithmͷ�ļ�
	for_each(v.begin(), v.end(), printFunc); // ����ʱ��Ϊ�ص�����printFunc(*it)


	cout << "-------------" << endl;

	vector<vector<int>> vv; // ��ά���� Ƕ�׵�int����
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	v1.push_back(1);
	v2.push_back(1);
	v2.push_back(2);
	v3.push_back(1);
	v3.push_back(2);
	v3.push_back(3);
	vv.push_back(v1);
	vv.push_back(v2);
	vv.push_back(v3);

	for (vector<vector<int>>::iterator it = vv.begin(); it != vv.end(); it++)
	{
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << *vit << " ";
		}
		cout << endl;
	}
}