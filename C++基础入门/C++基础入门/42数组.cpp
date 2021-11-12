#include <iostream>
using namespace std;

void func_42()
{
	char ch[5] = {'a'}; //其他值初始化为0 若不写赋值则是乱码
	cout << (int)ch[1] << endl;
	
	//获取数组长度（定义长度）
	cout << (sizeof(ch) / sizeof(ch[0])) << endl;
	//数组名 对应的是首个元素所在的地址


	// 动态数组需要 p = new int[3] 定义指针进行操作 ，之后再研究

}