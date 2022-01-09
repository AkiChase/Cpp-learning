#include <iostream>
#include "my_func.h"
using namespace std;

void arr_reverse(int *arr, int len);

void bubble_sort(int *arr, int len);

void func_42()
{
	char ch[5] = {'a'}; //其他值初始化为0 若不写赋值则是乱码(无初始化)
	cout << (int)ch[1] << endl; //输出0
	
	//获取数组长度（定义长度）
	cout << (sizeof(ch) / sizeof(ch[0])) << endl;
	//数组名 对应的是首个元素所在的地址

	// 动态数组需要 p = new int[3] 定义指针进行操作 ，之后再研究


	int test[] = { 5, 2, 3, 1, 4 };
	int len = sizeof(test) / sizeof(test[0]);

	cout << "test数组：" << endl;
	print_int_arr(test, len);

	cout << "test数组排序：" << endl;
	bubble_sort(test, len);
	print_int_arr(test, len);



	//数组逆置
	arr_reverse(test, len);
	cout << "test数组逆置：" << endl;
	print_int_arr(test, len);


	int arr2[2][3] = {
		{1,2,3},
		{4,5,6}
	};
	int row = sizeof(arr2)/sizeof(arr2[0]);
	int col = sizeof(arr2[0])/ sizeof(arr2[0][0]);
	cout << "\n二维数组，行数：" << row << "，列数：" << col << endl;
	//二维数组内存分布是 第1行排完后紧接着第2行
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