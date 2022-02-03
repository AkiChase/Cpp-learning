#include <iostream>
#include <string>
using namespace std;

//�����Զ����ࣨ�ṹ�壩��+-*/���㣬��Ҫ���壨����������أ�
//���õ�������������޷����ص�
//��Ҫ������������أ�ǳ���׶�������Ϊ��

class Date1
{
public:
	Date1(int a, int b);
	// ͨ����Ա��������
	Date1 operator + (Date1& d1); //operator����
	int c, d;
};

class Date2
{
public:
	Date2(int a, int b);
	int a, b;
};

Date1::Date1(int a, int b) : c(a), d(b) {}

Date1 Date1::operator+(Date1& d1) {
	int c = d1.c + this->c;
	int d = d1.d + this->d;
	return Date1(c, d);
}

Date2::Date2(int a, int b) : a(a), b(b) {}


//ͨ��ȫ�ֺ������������,��Ȼ����ֵ���Ͳ�һ��ҪDate2
Date2 operator + (Date2& d1, Date2& d2) {
	int a = d1.a + d2.a;
	int b = d1.b + d2.b;
	return Date2(a, b);
}

//��ͬ������أ���֮������Ҫ�Լ����壬����ʹ��&���ö�����ʡ�ռ��ʱ��
Date2 operator + (Date2& d1, int n) {
	int a = d1.a + n;
	int b = d1.b + n;
	return Date2(a, b);
}


//������������أ�һ����ȫ�ֺ��������أ�����cout << ����(���ǳ�Ա��������ֻ�� ���� << cout)
//cout �Ǳ�׼��������� ostream cout ȫ��ֻ��һ�� ��������ͷ��ض�Ҫ��&
//�������Ԫ���ܷ���˽������
ostream& operator <<(ostream& cout, Date1& d) {
	return (cout << "c = " << d.c << " " << "d = " << d.d);
}

// ����д�ȽϺÿ�
ostream& operator <<(ostream& cout, Date2& d) {
	cout << "a = " << d.a << ", " << "b = " << d.b;
	return cout;
}



class Myint
{

public:
	Myint(int n) {
		this->num = n;
	}
	// ע�ⷵ�����ã�
	//ʹ�� ++xxx ǰ�õ���ʱ����
	Myint& operator++ () {
		num++;
		return *this;
	}

	// ʹ��intռλ����ֻ����int������������ʶ��Ϊ���õ���
	// ʹ�� xxx++ ���õ���ʱ����
	Myint& operator++ (int) {
		//�ȼ�¼ԭ����
		Myint tmp = *this;
		// ����
		num++;
		// ���ؼ�¼ֵ
		return tmp;
	}

private:
	friend ostream& operator<< (ostream& cout, Myint n);
	int num;

};

ostream& operator<< (ostream& cout, Myint n) {
	cout << n.num;
	return cout;
}



//���½���ʱ������������Զ�����operator+ ����ֵ�����
//Ĭ�ϵĸ�ֵ��������Ὣ�����ÿ������ǳ����һ��
//�������ĳ��������ָ��ʱ�ͻ������ǳ����������
class MyInt2
{
public:
	MyInt2(int n) {
		numPtr = new int(n);
	}
	int* numPtr;

	MyInt2& operator=(MyInt2& foo) {
		// ���ж��Լ��Ƿ����д���ڶ���������
		if (numPtr != NULL)
		{
			// �еĻ�Ҫ�Ѿ��������ͷ�
			delete numPtr;
			numPtr = NULL;
		}
		// ���½�
		numPtr = new int(*foo.numPtr);

		// Ҫ���ض�������Ϊ������ʽ���ø�ֵ
		return *this;
	}

	bool operator==(int n) {
		return (*this->numPtr) == n;
	}

	// ע��ʹ�����ã�������
	bool operator==(MyInt2& n) {
		return (*this->numPtr) == (*n.numPtr);
	}

	bool operator>(MyInt2& n) {
		return (*this->numPtr) > (*n.numPtr);
	}


	~MyInt2() {
		if (numPtr != NULL)
		{
			delete numPtr;
			numPtr = NULL;
		}
	}
};



class MyPrint
{
public:
	//���⺯�����÷�()Ҳ������
	//�ǳ���û�й̶�д��
	//Ҳ��Ϊ�º���
	void operator()(string txt) {
		cout << txt << endl;
	}
};

void func_39() {
	Date1 d11(1, 2);
	Date1 d12(3, 4);
	Date1 d13 = d11 + d12;
	//��ͬ�� Date1 d13 = d11.operator+(d12);
	cout << d13.c << "\t" << d13.d << endl;

	Date2 d21(3, 4);
	Date2 d22(7, 8);
	Date2 d23 = d21 + d22;
	//��ͬ�� Date2 d23 = operator+(d21,d22);
	cout << d23.a << "\t" << d23.b << endl;


	Date2 d24 = d21 + 100;
	cout << d24 << endl;
	//Date2 d25 = 100 + d21; ������Ϊû�ж��� int + Date2 ֻ������Date2 + int

	Myint num(0);
	cout << "���õ�����" << num++ << endl;
	cout << "ǰ�õ�����" << ++num << endl;
	cout << "���ս��" << num << endl;


	MyInt2 n1(10);
	MyInt2 n2(15);
	MyInt2 n3(20);

	if (n1 == 15)
	{
		cout << "n1==15:true" << endl;
	}
	else
	{
		cout << "n1==15:false" << endl;
	}

	if (n1 > n2)
	{
		cout << "n1>n2:true" << endl;
	}
	else
	{
		cout << "n1>n2:false" << endl;
	}

	cout << *n1.numPtr << endl;
	cout << *n2.numPtr << endl;
	cout << *n3.numPtr << endl;
	n1 = n2 = n3;
	cout << *n1.numPtr << endl;
	cout << *n2.numPtr << endl;
	cout << *n3.numPtr << endl;

	if (n1 == n2)
	{
		cout << "n1==n2:true" << endl;
	}
	else
	{
		cout << "n1==n2:false" << endl;
	}


	MyPrint myPrint;
	myPrint("����һ��");
	// Ҳ������ʱ����һ����������MyPrint()������
	MyPrint()("����������������");
}