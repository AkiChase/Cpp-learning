#include <iostream>
#include "my_func.h"

using namespace std;

void print_int_arr(int *arr, int len) {
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}