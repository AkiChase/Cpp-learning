#include <iostream>
using namespace std;


// ���� ��Ϊ��������
void mySwap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}


// ��Ҫ���ؾֲ����������ã��ᱻ�ͷţ�
int& ref_01() {
	int* a = new int(10);
	return *a;
}

// ���ⷵ�����õĺ�����������Ϊ��ֵ
int& ref_02() {
	static int a = 10;
	return a;
}

void func_06() {
	//����
	// b��a�ı�����ָ��ͬһ����ַ
	int a = 10;
	int& b = a;

	//���ñ����ʼ��ֵ�����Ҳ��ɸ��ģ���b�����ٸ���Ϊ���������ı���
	int a1 = 1, a2 = 2;
	cout << a1 << "  " << a2 << endl;
	mySwap(a1, a2);
	cout << a1 << "  " << a2 << endl;

	int& t = ref_01();
	cout << t << endl;

	// ��ʱt2һֱָ�����е�static a
	int& t2 = ref_02();
	cout << t2 << endl;

	ref_02() = 666;
	cout << t2 << endl;



	// ���õı����� ָ�� ������ ���ɸ��ĵ�ָ��
	int& ref = a;
	// �������Զ�ת��Ϊ int* const ref = &a;
	ref = 666;
	// �������Զ�ת��Ϊ *ref = 666;


	// �������ã�һ�������βΣ���ֹ�����������
	const int& ref2 = 10; // �˴���ͬ�� int temp = 10; const int& ref2 = temp; ����constʱ����

}