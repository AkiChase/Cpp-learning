# include <iostream>
using namespace std;


// Ĭ�ϲ����޷��ض��壬���������ĳ�����Ѿ�д��Ĭ��ֵ����ô�������޷��ٶ����Ӧ������Ĭ��ֵ
void test_func(int a = 5, int b = 10);

void test_func(int a, int b) {
	cout << a << " " << b << endl;
}


// ��Ȼ������ûдĬ��ֵ������ʵ�ֿ��Զ���Ĭ��ֵ
void test_func2(int a, int b);

void test_func2(int a = 6, int b = 66) {
	cout << a << " " << b << endl;
}


// �β��пɼ�ռλ��������Ȼ���岻�󣬵��Ǻ�������ʱ���봫��ռλ����
// ����ռλ�������Լ�Ĭ��ֵ
void test_func3(int a, int=777) {
	cout << a << endl;
}



//�������أ�
//1.��ͬһ�������£�2.������������ͬ�����ǣ�3.����������������ͻ����˳���������������һ����������ֵ���Ͳ��������ڣ�
// int&��const int&Ҳ�������Ͳ�ͬ��func(10)����� const int&��
//��֮���Ǳ����ú�������ʱ�� Ψһ�ԣ�ע��Ĭ�ϲ�����Ӱ�죩
void test() {
	cout << "����1" << endl;
}

void test(int a) {
	cout << "����2" << endl;
}

void test(double a) {
	cout << "����3" << endl;
}

void test(int a, double b) {
	cout << "����4" << endl;
}

void test(double a, int b) {
	cout << "����5" << endl;
}


void func_12() {
	test_func();
	test_func2();
	test_func3(666, 123);

	test();
	test(1);
	test(1.1);
	test(1, 1.1);
	test(1.1, 1);
}