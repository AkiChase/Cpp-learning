#include <iostream>
using namespace std;

void func_24()
{
	//if语句
	int score;
	cout << "请输入分数：";
	cin >> score;
	if (score > 0)
	{
		cout << "分数>0" << endl;
	}
	else if (score == 0)
	{
		cout << "分数=0" << endl;
	}
	else
	{
		cout << "分数<0" << endl;
	}

	//三目运算符 注意用括号保证优先级
	cout << (score > 0 ? "大于0" : "小等于0") << endl;

	// 其返回的是变量 故可以继续赋值
	int a = 10;
	int b = 0;
	(a > b ? a : b) = 100;
	cout << a << " " << b << endl;


	// switch语句  注意break
	//缺点判断只能是 整型 或者 字符
	//优点执行效率高 结构清晰
	switch (score)
	{
	case 11:
		cout << "分数为10" << endl;
		break;

	case 1:
	case 2:
		cout << "分数为1或者2" << endl;
		break;

	default:
		cout << "分数为其他" << endl;
		break;
	}

	//循环
	//1.while
	a = 5;
	while (a-- > 0)
	{
		cout << "a=" << a << endl;
	}

	//2. do while
	//3. for循环

	for (size_t i = 0; i < 5; i++)
	{
		cout << "i=" << i << endl;
		//注意此处i的生命周期仅在这个循环体中
	}



	//跳转语句（无条件转移语句，不回头）
	//goto 标记
	//如果标记的名称存在，执行到goto时，跳转到标记的位置
	a = 1;
FLAG:
	cout << "a=" << a << endl;

	if (a-- > 0) {
		goto FLAG;
	}

}