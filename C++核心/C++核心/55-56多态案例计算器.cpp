#include <iostream>
#include <string>
using namespace std;

class AbstractCalculator
{
public:
	// 定义纯虚函数 之后在子类中重写（作为一种抽象的函数，为了让子类必须重写它）
	// 定义了纯虚函数的类称为抽象类：无法实例化，且其子类若不对纯虚函数进行重写，则也会变成抽象类
	virtual int getResult() = 0;

	AbstractCalculator(int n1, int n2) :num_1(n1), num_2(n2) {}

	void printResult() {
		cout << num_1 << " " << opera << " " << num_2 << " = " << getResult() << endl;
	}


	int num_1, num_2;
	string opera;
};

class AddCalculator : public AbstractCalculator
{
public:
	AddCalculator(int n1, int n2) :AbstractCalculator(n1, n2) {
		opera = "+";
	};
	int getResult()
	{
		return num_1 + num_2;
	}
};

class SubCalculator : public AbstractCalculator
{
public:
	SubCalculator(int n1, int n2) :AbstractCalculator(n1, n2) {
		opera = "-";
	};
	int getResult()
	{
		return num_1 - num_2;
	}
};

class MulCalculator : public AbstractCalculator
{
public:
	MulCalculator(int n1, int n2) :AbstractCalculator(n1, n2) {
		opera = "*";
	};
	int getResult()
	{
		return num_1 * num_2;
	}
};

void doCalculation(AbstractCalculator* calculator) {
	calculator->printResult();
	delete calculator;  // 防止内存泄漏
}

void func_55() {
	doCalculation(new MulCalculator(2, 5));
}