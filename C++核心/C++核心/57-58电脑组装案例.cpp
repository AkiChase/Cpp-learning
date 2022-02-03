// 多态使用时，如果子类中存在开辟堆区，并在子类析构函数中释放的流程
// 那么在多态中 delete 父类指针时，无法调用到子类的析构函数
// 解决方式：将父类的析构函数改为虚析构或者纯虚析构
// 虚析构会用多态的方式调用到子类的析构，最后还是会调用父类的析构
// 纯虚析构能让子类必须重写析构(父类会抽象化)，注意父类必须补上纯虚析构的实现，多态调用完子类析构然后调用父类析构
// 即纯虚析构既需要=0的“声明”，还需要“实现”

#include <iostream>
using namespace std;

//三种零件的抽象类
class CPU
{
public:
	virtual void calculate() = 0;
};

class VedioCard
{
public:
	virtual void display() = 0;
};

class Memory
{
public:
	virtual void storage() = 0;
};

// 电脑类
class Computer
{
public:
	Computer(CPU* _cpu, VedioCard* _vc, Memory* _mem) : m_cpu(_cpu), m_vc(_vc), m_mem(_mem) {}
	void work() {
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}

	~Computer() {
		if (m_cpu!=NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_vc != NULL)
		{
			delete m_vc;
			m_vc = NULL;
		}
		if (m_mem != NULL)
		{
			delete m_mem;
			m_mem = NULL;
		}
	}

private:
	CPU* m_cpu;
	VedioCard* m_vc;
	Memory* m_mem;
};


//具体厂商的零件
class IntelCPU :public CPU
{
public:
	void calculate() {
		cout << "Intel的CPU开始计算了！" << endl;
	}
};

class IntelVC :public VedioCard
{
public:
	void display() {
		cout << "Intel的显卡开始显示了！" << endl;
	}
};

class IntelMEM :public Memory
{
public:
	void storage() {
		cout << "Intel的内存条开始储存了！" << endl;
	}
};


class LenoveCPU :public CPU
{
public:
	void calculate() {
		cout << "Lenove的CPU开始计算了！" << endl;
	}
};

class LenoveVC :public VedioCard
{
public:
	void display() {
		cout << "Lenove的显卡开始显示了！" << endl;
	}
};

class LenoveMEM :public Memory
{
public:
	void storage() {
		cout << "Lenove的内存条开始储存了！" << endl;
	}
};


void func_57() {
	CPU* intelCPU = new IntelCPU;
	VedioCard* lenoveVC = new LenoveVC;
	Memory* intelMEM = new IntelMEM;

	Computer* cp = new Computer(intelCPU, lenoveVC, intelMEM);
	cp->work();
	delete cp;
}




