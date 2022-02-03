#include <iostream>
#include <string>
using namespace std;

class AbstractCalculator
{
public:
	// ���崿�麯�� ֮������������д����Ϊһ�ֳ���ĺ�����Ϊ�������������д����
	// �����˴��麯�������Ϊ�����ࣺ�޷�ʵ�������������������Դ��麯��������д����Ҳ���ɳ�����
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
	delete calculator;  // ��ֹ�ڴ�й©
}

void func_55() {
	doCalculation(new MulCalculator(2, 5));
}