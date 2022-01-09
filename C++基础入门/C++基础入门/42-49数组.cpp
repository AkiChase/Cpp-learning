#include <iostream>
#include "my_func.h"
using namespace std;

void arr_reverse(int *arr, int len);

void bubble_sort(int *arr, int len);

void func_42()
{
	char ch[5] = {'a'}; //����ֵ��ʼ��Ϊ0 ����д��ֵ��������(�޳�ʼ��)
	cout << (int)ch[1] << endl; //���0
	
	//��ȡ���鳤�ȣ����峤�ȣ�
	cout << (sizeof(ch) / sizeof(ch[0])) << endl;
	//������ ��Ӧ�����׸�Ԫ�����ڵĵ�ַ

	// ��̬������Ҫ p = new int[3] ����ָ����в��� ��֮�����о�


	int test[] = { 5, 2, 3, 1, 4 };
	int len = sizeof(test) / sizeof(test[0]);

	cout << "test���飺" << endl;
	print_int_arr(test, len);

	cout << "test��������" << endl;
	bubble_sort(test, len);
	print_int_arr(test, len);



	//��������
	arr_reverse(test, len);
	cout << "test�������ã�" << endl;
	print_int_arr(test, len);


	int arr2[2][3] = {
		{1,2,3},
		{4,5,6}
	};
	int row = sizeof(arr2)/sizeof(arr2[0]);
	int col = sizeof(arr2[0])/ sizeof(arr2[0][0]);
	cout << "\n��ά���飬������" << row << "��������" << col << endl;
	//��ά�����ڴ�ֲ��� ��1�����������ŵ�2��
}





void bubble_sort(int *arr, int len) {
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j <  len-i-1; j++)
		{
			if (arr[j]>arr[j+1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

void arr_reverse(int *arr, int len) {
	int tmp;
	int start = 0;
	int end = len-1;
	for (int i = 0; i < len; i++)
	{
		if (start < end)
		{
			tmp = arr[start];
			arr[start++] = arr[end];
			arr[end--] = tmp;
		}
	}
}