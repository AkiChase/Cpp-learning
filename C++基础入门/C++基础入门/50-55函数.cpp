#include <iostream>
#include "my_func.h"
using namespace std;

void func_50() {
	// 值传递、地址传递
	// 函数可以声明多次，但只能定义一次
	
	/*
	函数的分文件编写
	1.头文件
	2.源文件
	*/
	int arr[] = { 1,2,3,4,5 };
	print_int_arr(arr, 5);
}

