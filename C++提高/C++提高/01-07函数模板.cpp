#include <iostream>
using namespace std;

// ����һ��ģ�溯�� typenameҲ��дclass ûʲô���𣬿��Ժ���ģ��дtypename����ģ��дclass������������
template<typename T> //ע���������д��ͬһ��
void mySwap(T&a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}


template<typename T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			mySwap(arr[i], arr[minIndex]);
		}
	}
}


template<typename T>
void myPrint(T arr[], int len) {
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


template<typename numType, typename strType>
void myPrint2(numType num, strType str) {
	cout << "����:" << num << endl;
	cout << "�ı�:" << str << endl;
}

class MyData
{
public:
	MyData(int n): num(n){}
	int num;
};


//ģ��ľ��ޣ��������ܵģ������ض����������ͣ���Ҫ�þ��廯�ķ�ʽ������ʵ��
template <typename T>
void myCompare(T& a, T& b) {
	if (a == b)
	{
		cout << "��ͬ" << endl;
	}
	else
	{
		cout << "��ͬ" << endl;
	}
}

// ���廯T Ϊ MyData����ʱ
template <> void myCompare(MyData& a, MyData& b) {
	if (a.num==b.num)
	{
		cout << "��ͬ" << endl;
	}
	else
	{
		cout << "��ͬ" << endl;
	}
}



void func_01() {
	int a = 1;
	int b = 2;
	// 1.�Զ������Ƶ���Ҫ������Ƶ�����ͬ��T���ͣ������Ƶ�������||���⣬�Զ������Ƶ����ᷢ����ʽ����ת����
	mySwap(a, b);
	cout << a << " " << b << endl;

	//2.��ʾָ������(�ᷢ����ʽ����ת��)
	mySwap<int>(a, b);
	cout << a << " " << b << endl;

	char arr[5] = { 'e', 'a', 'c', 'f' ,'e' };
	myPrint(arr, 5);
	mySort(arr, 5);

	//ʵ�ʿ����У�������ģ�����ͨ����ͬ��

	//��ͨ�����ͺ���ģ�嶼���Ե���ʱ�����ȵ�����ͨ����

	//����ͨ����ģ�������ǿ�Ƶ��ú���ģ��
	myPrint<>(arr, 5);


	//����ģ��Ҳ������(��ͨ��ģ���һ������)

	//�����ͨ�����ͺ���ģ�嶼�ܵ��ã�������ͨ����Ҫ������ʽת����ģ�庯��ֻ��Ҫ�Ƶ����ͣ�����ú���ģ��

	// ѧϰģ�����ҪĿ�ģ�Ϊ����STL������ϵͳ��ģ��

	MyData d1(1);
	MyData d2(1);
	myCompare(d1, d2);


	double num1 = 3.1415926;
	char str1[] = "�����ı�";
	myPrint2(num1, str1);
}