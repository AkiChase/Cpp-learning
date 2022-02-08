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

	cout << "-------------------" << endl;
	//�����ɾ��

	v1.push_back(3); //β������
	printVector(v1);

	v1.pop_back(); //β��ɾ��
	printVector(v1);

	v1.insert(v1.begin() + 1, 666); //��λ��1���� ע�����λ�ñ����õ�����
	printVector(v1);

	v1.insert(v1.begin() + 1, 2, 223); //��λ��n����m�� ele
	printVector(v1);

	v1.erase(v1.begin() + 1); // ɾ��������ָ��λ�õ�Ԫ��
	printVector(v1);

	v1.erase(v1.begin() + 1, v1.end() - 1); //ɾ��������ָ��λ��֮�������Ԫ��
	printVector(v1);

	v1.clear(); //�������Ԫ��
	cout << "������" << v1.capacity() << "\t��С:" << v1.size() << endl;

	cout << "-------------------" << endl;
	v2.resize(5);
	// vector���ݴ�ȡ
	// ���˿����õ�������������������ʽ
	v2.at(1) = 123;
	v2[2] = 666;
	v2.front() = 456; // ���ص�һ��Ԫ�ص�����
	v2.back() = 789; //�������һ��Ԫ�ص�����
	printVector(v2);

	cout << "-------------------" << endl;
	// ����vector����������ʵ����ָ�򻥻�
	cout << "v2: ";
	printVector(v2);
	cout << "v3: ";
	printVector(v3);

	cout << "������" << endl;
	v2.swap(v3);
	cout << "v2: ";
	printVector(v2);
	cout << "v3: ";
	printVector(v3);

	// ���ú�swap���������ռ䣨ע��resizeֻ���޸�size�����޸�������
	// ��Ϊ��̬��������ʱ������һ���ǲ���һ����������һ�Σ�����Ƶ������Ч�ʵͣ�������ʱ������ǰ���ݸ���ռ�
	// ����������鲻�ٱ仯�ˣ���Щ����Ŀռ���˷���
	// ����ͨ��swap������

	for (int i = 0; i < 1000 ; i++)
	{
		v3.push_back(i);
	}

	cout << "v3������ " << v3.capacity() << endl;
	cout << "v3��С�� " << v3.size() << endl;
	
	vector<int>(v3).swap(v3);  //��һ�������Ķ�����v3���������������죬Ȼ������������v3����
	// ��������ǰ��ִ�к���ͷ�
	
	cout << "������\nv3������ " << v3.capacity() << endl;
	cout << "v3��С�� " << v3.size() << endl;

	cout << "-------------------" << endl;
	// Ԥ���ռ䣬��֪���Լ�������������Ƕ��٣��������ú����Ԥ���ռ䣬��Ч���ٶ�̬���ݵĴ���
	// Ԥ���ռ䲻ͬ��resize�������������������������ʼ��Ĭ��ֵ
	cout << "v4������ " << v4.capacity() << endl;
	cout << "v4��С�� " << v4.size() << endl;
	v4.reserve(100); //����Ԥ���Ŀռ�
	cout << "v4������ " << v4.capacity() << endl;
	cout << "v4��С�� " << v4.size() << endl;


}