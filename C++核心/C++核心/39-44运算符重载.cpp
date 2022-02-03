#include <iostream>
#include <string>
using namespace std;

//对于自定义类（结构体）的+-*/运算，需要定义（即运算符重载）
//内置的类型运算符是无法重载的
//不要滥用运算符重载，浅显易懂，方便为主

class Date1
{
public:
	Date1(int a, int b);
	// 通过成员函数重载
	Date1 operator + (Date1& d1); //operator符号
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


//通过全局函数重载运算符,当然返回值类型不一定要Date2
Date2 operator + (Date2& d1, Date2& d2) {
	int a = d1.a + d2.a;
	int b = d1.b + d2.b;
	return Date2(a, b);
}

//不同类别重载，总之都是需要自己定义，此外使用&引用对象会节省空间和时间
Date2 operator + (Date2& d1, int n) {
	int a = d1.a + n;
	int b = d1.b + n;
	return Date2(a, b);
}


//左移运算符重载，一般用全局函数来重载，用于cout << 对象(若是成员函数重载只能 对象 << cout)
//cout 是标准输出流对象 ostream cout 全局只有一个 所以输入和返回都要用&
//再配合友元还能访问私友属性
ostream& operator <<(ostream& cout, Date1& d) {
	return (cout << "c = " << d.c << " " << "d = " << d.d);
}

// 这样写比较好看
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
	// 注意返回引用！
	//使用 ++xxx 前置递增时触发
	Myint& operator++ () {
		num++;
		return *this;
	}

	// 使用int占位符（只能用int），编译器将识别为后置递增
	// 使用 xxx++ 后置递增时触发
	Myint& operator++ (int) {
		//先记录原数据
		Myint tmp = *this;
		// 递增
		num++;
		// 返回记录值
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



//类新建的时候编译器还会自动创建operator+ 即赋值运算符
//默认的赋值运算仅仅会将对象的每个属性浅拷贝一次
//当对象的某个属性是指针时就会出现深浅拷贝的问题
class MyInt2
{
public:
	MyInt2(int n) {
		numPtr = new int(n);
	}
	int* numPtr;

	MyInt2& operator=(MyInt2& foo) {
		// 先判断自己是否已有存放在堆区的属性
		if (numPtr != NULL)
		{
			// 有的话要把旧数据先释放
			delete numPtr;
			numPtr = NULL;
		}
		// 再新建
		numPtr = new int(*foo.numPtr);

		// 要返回对象自身，为了能链式调用赋值
		return *this;
	}

	bool operator==(int n) {
		return (*this->numPtr) == n;
	}

	// 注意使用引用！！！！
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
	//此外函数调用符()也能重载
	//非常灵活，没有固定写法
	//也称为仿函数
	void operator()(string txt) {
		cout << txt << endl;
	}
};

void func_39() {
	Date1 d11(1, 2);
	Date1 d12(3, 4);
	Date1 d13 = d11 + d12;
	//等同于 Date1 d13 = d11.operator+(d12);
	cout << d13.c << "\t" << d13.d << endl;

	Date2 d21(3, 4);
	Date2 d22(7, 8);
	Date2 d23 = d21 + d22;
	//等同于 Date2 d23 = operator+(d21,d22);
	cout << d23.a << "\t" << d23.b << endl;


	Date2 d24 = d21 + 100;
	cout << d24 << endl;
	//Date2 d25 = 100 + d21; 报错因为没有定义 int + Date2 只定义了Date2 + int

	Myint num(0);
	cout << "后置递增：" << num++ << endl;
	cout << "前置递增：" << ++num << endl;
	cout << "最终结果" << num << endl;


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
	myPrint("测试一下");
	// 也可以临时创建一个匿名对象MyPrint()来调用
	MyPrint()("测试匿名函数对象");
}