#include <iostream>
# define T 66
using namespace std;

int* createInt() {
	int* a = new int(10); //����Ϊ�����ó�ʼֵ10
	return a;
}

int* createIntArr() {
	int* arr = new int[10]; //�������ó�ʼֵ
	return arr;
}


void func_01() {
	/*
	��������ǰ��
		����������ź������룬�ǹ���ġ�ֻ����
		ȫ��������ų���(define��)���ַ�����������̬����(static)��������������ϵͳ�ͷš�
	���к�
		ջ�����ɱ�����������ź����Ĳ������ֲ�����
		�������ɳ���Ա�Լ�����(ʹ��new)���ͷ�(delete)������������ͳһ�ͷš�
	*/
	int* p = createInt();
	cout << *p << endl;
	delete p; // �ͷ�ָ���Ӧ���ڴ�

	int* arr = createIntArr();
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
	// �ͷ����� Ҫ��[]
	delete[] arr;


	const int t = 666;
	int tt = 666;
	cout << (int)&t << endl;
	cout << (int)&tt << endl;
}