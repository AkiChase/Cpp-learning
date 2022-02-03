// ��̬ʹ��ʱ����������д��ڿ��ٶ������������������������ͷŵ�����
// ��ô�ڶ�̬�� delete ����ָ��ʱ���޷����õ��������������
// �����ʽ�������������������Ϊ���������ߴ�������
// ���������ö�̬�ķ�ʽ���õ����������������ǻ���ø��������
// ���������������������д����(��������)��ע�⸸����벹�ϴ���������ʵ�֣���̬��������������Ȼ����ø�������
// ��������������Ҫ=0�ġ�������������Ҫ��ʵ�֡�

#include <iostream>
using namespace std;

//��������ĳ�����
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

// ������
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


//���峧�̵����
class IntelCPU :public CPU
{
public:
	void calculate() {
		cout << "Intel��CPU��ʼ�����ˣ�" << endl;
	}
};

class IntelVC :public VedioCard
{
public:
	void display() {
		cout << "Intel���Կ���ʼ��ʾ�ˣ�" << endl;
	}
};

class IntelMEM :public Memory
{
public:
	void storage() {
		cout << "Intel���ڴ�����ʼ�����ˣ�" << endl;
	}
};


class LenoveCPU :public CPU
{
public:
	void calculate() {
		cout << "Lenove��CPU��ʼ�����ˣ�" << endl;
	}
};

class LenoveVC :public VedioCard
{
public:
	void display() {
		cout << "Lenove���Կ���ʼ��ʾ�ˣ�" << endl;
	}
};

class LenoveMEM :public Memory
{
public:
	void storage() {
		cout << "Lenove���ڴ�����ʼ�����ˣ�" << endl;
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




