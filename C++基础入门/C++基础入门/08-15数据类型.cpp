#include <iostream>
#include <string>
using namespace std;

void func_08()
{
	//可能超出上限
	short num1 = 10; //2 byte = 16bit
	int num2 = 10;	//4 byte
	long num3 = 10; // 4 或 8
	long long num4 = 10; // 8
	cout << "long类型size：" << sizeof(long) << endl;


	//实型（浮点型）
	float f1 = 3.1415926f; 
	double f2 = 3e-8; //科学记数法
	double f3 = 4; //默认就是double
	//float 4byte  double 8byte
	//cout默认输出保留6位小数

	//字符型占用1byte (存的是acsii)
	char ch1 = 'a';
	char ch2 = 98;
	cout << ch2 << endl;

/*
	转义字符
	  \r 表示返回到当行的最开始位置
	  \t 补全8个字符
*/


	//字符串
	//1.C风格
	char s1[] = "C风格字符串";

	//2.C++风格 注意头文件
	//#include <string>

	string s2 = "C++风格字符串";
	cout << s1 << s2 << endl;


	/*
	布尔值
	1byte
	*/
	bool flag = true;


	//数据的输入
	//cin
	int a;
	cout << "输入a=?";
	cin >> a;
	cout << "输出a =" << a << endl;

	/*
	cin 会根据变量定义的类型对输入的数据进行读取
	如此时输入12.3
	则只读取到12 (.3被遗留在输入缓冲区，若还有cin则会进入下一个cin)
	
	涉及具体要求输入数据类型正确时
	需要使用cin.clear() cin.fail()等等
	*/
}