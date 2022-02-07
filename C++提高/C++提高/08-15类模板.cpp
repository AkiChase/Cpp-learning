#include <iostream>
#include <string>
#include "MyData3.hpp"
using namespace std;

//��ģ�壺���г�Ա��������ͨ�����ʹ���
//ע����ģ��û���Զ������Ƶ�����ֻ����ʾָ������
//��ģ���п�����ģ������б�����дĬ������

//��ģ���еĳ�Ա�����ڵ���ʱ�Ŵ���
template <class StrType, class NumType = int>
class MyData2
{
public:
	MyData2(StrType name, NumType age) : m_name(name), m_age(age) {
		cout << "MyData2���캯��" << endl;
	}

	StrType m_name;
	NumType m_age;
};


// ����ģ�������Ϊ��������ʱ
//1.ָ���������ͣ����ã��������ֶ��Ǻ���ģ�������ģ�壬�����ã�
void printData1(MyData2<string, int>& d) {
	cout << d.m_name << endl;
	cout << d.m_age << endl;
}

//2.����ģ�廯
// typeid(����).name(); ���Բ鿴���͵�����
template<typename T1, typename T2>
void printData2(MyData2<T1, T2>& d) {
	cout << d.m_name << endl;
	cout << d.m_age << endl;
	cout << "T1������:" << typeid(T1).name() << endl;
	cout << "T2������:" << typeid(T2).name() << endl;
}

//3.������ģ�廯
template<class T>
void printData3(T& d) {
	cout << d.m_name << endl;
	cout << d.m_age << endl;
	cout << "T������:" << typeid(T).name() << endl;
}


//��ģ��ļ̳У�
//����̳�ʱ��Ҫָ���������õ���ͨ��������ʲô
class Son1 : public MyData2<string> // ��Ȼ����Ĭ�ϲ���Ҳ����ʡ��
{};


template <class T>
class Base
{
public:
	T foo;
};


//������Ҫ������Ҳд����ģ��
template <class T1, class T2>
class Son2 : public Base<T1>
{
public:
	Son2();
	T2 bar; // ������Ҫ�µ�ͨ�����͵�Ȼ���Բ���ҪT2
};

// ����дʵ�ֵķ�ʽ����Ҫ����template T1 T2 ���ں������������ϱ�����Ҫ������T1,T2
template <class T1, class T2>
Son2<T1, T2>::Son2()
{
	cout << "T1������:" << typeid(T1).name() << endl;
	cout << "T2������:" << typeid(T2).name() << endl;
}



template <class T> class MyDate4; // ��ǰ����MyDate4��

// ��Ҫ��ǰ�ñ�����֪�����������������Ϊ��Ԫ
template <class T>
void myFPrint(MyDate4<T> d) {
	cout << "˽�����ԣ�a=" << d.a << endl;
}

template <class T>
class MyDate4
{
	friend void myFPrint<>(MyDate4<T> d);  // ��Ԫ ȫ�ֺ�������ʵ����Ҫ���Ͽյ�ģ���б�<>������Ҫһϵ�в���
	// ��ȫ�ֺ�������ʵ������Ҫ<>ֱ��������д�ú���������ʵ�ּ��ɣ��Ƽ�����������鷳��


public:
	MyDate4(T t) {
		this->a = t;
	}

private:
	T a;
};




void func_08() {
	MyData2<string> d("����", 666); // ��double��ʽת��Ϊ��int
	printData1(d);
	cout << "-----------" << endl;
	printData2(d);
	cout << "-----------" << endl;
	printData3(d);
	cout << "-----------" << endl;
	Son2<string, int> s;
	cout << "-----------" << endl;

	//��ģ����ļ���дʱ��������Ӳ������������⣬�����
	//1. include cpp�ļ�������h�ļ�����Ȼh�ļ�ҲҪ����д��
	//��������2. ��h�ļ���cpp�ļ����ݺϲ�Ϊhpp�ļ���hpp����Ӳ��Ҫ�󣬵�����Լ���׳�,һ����Ҿ�֪������ģ�壩
	MyData3<string, int> d3("����", 666);
	d3.showInfo();

	cout << "-----------" << endl;
	MyDate4<double>d4(3.14);
	myFPrint(d4);

}