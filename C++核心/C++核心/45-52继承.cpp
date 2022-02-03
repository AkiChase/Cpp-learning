#include <iostream>
using namespace std;

// ʹ�ü̳У����ٴ����ظ�
class Base
{
public:
	void header() {
		cout << "ͷ��================ͷ��" << endl;
	}
	void footer() {
		cout << "β��================β��" << endl;
	}
	int n = 666;
	static int s;
};

int Base::s = 123;

// content1��Ϊ����Base�����ࣩ�����ࣨ�����ࣩ
/*
���м̳У�public��������Ĺ��г�ԱҲ��������Ĺ��г�Ա������ı�����ԱҲ��������ı�����Ա
�����̳У�protected��������Ĺ��кͱ�����Ա����Ϊ������ı�����Ա��
˽�м̳У�private��������Ĺ��кͱ�����Ա����Ϊ�������˽�г�Ա��
*/

//���������зǾ�̬�ĳ�Ա�����ᱻ�̳У��������Ƿ�˽�У������sizeof��ȫ��������+��������д������
//���������з��ʲ�������Ϊ������������

//������ʵ����ʱ�����ȵ��û���Ĺ��캯�����ٵ���������Ĺ��캯��
//�������������ʱ�����ȵ���������������������ٵ��û������������

class content1 : public Base
{
public:
	void print() {
		cout << "����1" << endl;
	}

	static int s;
};
int content1::s = 223;


class content2 : public Base
{
public:
	void print() {
		cout << "����2" << endl;
	}

	void header() {
		cout << "content2��ͷ=======" << endl;
	}

	int n = 777;
};

class Base2
{
	void header() {
		cout << "ͷ��2================ͷ��2" << endl;
	}
	void footer() {
		cout << "β��2================β��2" << endl;
	}
};

// ��̳�
// ��������п�����ͬ����Ա������ʱ��Ҫ�������򣬷��򱨴�
// ʵ�ʿ����в�����ʹ��
class content3 : public Base, public Base2
{
public:
	void print() {
		cout << "����3" << endl;
	}
};


// ���μ̳�:��һ�����������������࣬������������������һ����������������������
// ��ʱ���������඼����ͬ�����ݣ������ǵ�������ͻ���˫����ͬ�����ݣ�����˷ѣ����ҷ��ʶ�Ҫ�������򲻷���
// �����������̳У���������������̳з�ʽ�ϼ���  virtual�ؼ��� 
// �������ǵ�������ֻ��һ�����ݣ�д�ϲ�ͬ��������Ҳ����ʵ�ͬһ�����ݣ������������ʡ��
class Animal
{
public:
	int n = 1;
};

class Sheep : virtual public Animal
{
public:
	int nn = 2;
};
class Tuo : virtual public Animal
{
public:
	int nn = 3;
};

class YangTuo :public Sheep, public Tuo {};

void func_45() {
	content1 c1;
	c1.header();
	c1.print();
	c1.footer();

	content2 c2;
	c2.header(); // ����ͬ����Աʱ�����ȷ��������еĳ�Ա
	// ע�⣡����ӵ��ͬ���ĺ����ͻ����ص����������е�ͬ���������������صģ�ֻ��ͨ��������������
	c2.Base::header(); // ������ʸ���ģ���Ҫ�� ����:: ��������
	// ����ͬ��
	cout << c2.n << "\t" << c2.Base::n << endl;
	c2.print();
	c2.footer();

	//��̬��Աͨ���������ͨ��
	//��̬��Աͨ����������,������ͨ��������ʣ���֮���Ǳ���������
	cout << content1::s << "\t" << Base::s << "\t" << content1::Base::s << endl;

	YangTuo yt;
	cout << yt.n << endl;
	cout << yt.Sheep::nn << "\t" << yt.Tuo::nn << endl;
}