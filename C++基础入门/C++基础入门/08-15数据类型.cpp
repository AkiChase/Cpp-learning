#include <iostream>
#include <string>
using namespace std;

void func_08()
{
	//���ܳ�������
	short num1 = 10; //2 byte = 16bit
	int num2 = 10;	//4 byte
	long num3 = 10; // 4 �� 8
	long long num4 = 10; // 8
	cout << "long����size��" << sizeof(long) << endl;


	//ʵ�ͣ������ͣ�
	float f1 = 3.1415926f; 
	double f2 = 3e-8; //��ѧ������
	double f3 = 4; //Ĭ�Ͼ���double
	//float 4byte  double 8byte
	//coutĬ���������6λС��

	//�ַ���ռ��1byte (�����acsii)
	char ch1 = 'a';
	char ch2 = 98;
	cout << ch2 << endl;

/*
	ת���ַ�
	  \r ��ʾ���ص����е��ʼλ��
	  \t ��ȫ8���ַ�
*/


	//�ַ���
	//1.C���
	char s1[] = "C����ַ���";

	//2.C++��� ע��ͷ�ļ�
	//#include <string>

	string s2 = "C++����ַ���";
	cout << s1 << s2 << endl;


	/*
	����ֵ
	1byte
	*/
	bool flag = true;


	//���ݵ�����
	//cin
	int a;
	cout << "����a=?";
	cin >> a;
	cout << "���a =" << a << endl;

	/*
	cin ����ݱ�����������Ͷ���������ݽ��ж�ȡ
	���ʱ����12.3
	��ֻ��ȡ��12 (.3�����������뻺������������cin��������һ��cin)
	
	�漰����Ҫ����������������ȷʱ
	��Ҫʹ��cin.clear() cin.fail()�ȵ�
	*/
}