#include <iostream>
using namespace std;

// ��ĳ�Ա�����ͳ�Ա�����Ƿֿ������
// ֻ�зǾ�̬��Ա ����  ���������ض���һ�����󣬿�����sizeof��ȡ��С���ն���sizeofΪ1��ֻ��һ��int��Ϊ4
// �����;�̬�������ǹ����

class Test2;
class Temp
{
public:
	void visit(Test2& t2);
};

class Test2
{
public:
	// this������Ĭ�ϵĶ��� ָ�룬ָ�򱻵��õĳ�Ա���������Ķ���
	// this �ǲ����޸�ָ��ĳ���ָ��,��ÿ����Ա�������൱�� Test2 * const this;
	// ���Խ���þ�̬��Ա�������ʵ���Ӧ����ķǾ�̬��Ա
	Test2(int n) {
		this->n = n;
	}

	// ����ʹ��*this�����ض�����ʵ����ʽ����  ע��Ҫ����"����"��������ֵ�޷��ﵽԤ��Ч��
	Test2& add(Test2 t) {
		this->n += t.n;
		return *this;
	}

	void showWord() {
		cout << "��ָ��Ҳ�ܵ���" << endl;
	}

	void showN() {
		if (this == NULL)
		{
			return;
		}
		cout << n << endl;
	}

	//�������������ڲ������޸ĳ�Ա���ԣ����Ǹ���������ʱ������ mutable  ע��const��λ�ã�
	void showConst() const {
		m = 1; // �����޸�mutable���εı���(�;�̬����)
		s = 77;
		cout << s << endl;
		cout << "������" << endl;

		//this->n = 666;  Ҳ����ͨ��thisָ�����޸�
		// ��Ϊ�������൱�� const Test2 * const this;
	}

	static void ttt() {
		cout << "��̬" << endl;
	}


	int n;
	mutable int m;
	static int s;

private:
	int pv = 123;
	// ������Ԫ����ȫ�ֺ������Է��ʱ����ڵ�˽�г�Ա
	friend void friendGet(Test2& t);
	// ��Ԫ������г�Ա����Ҳ�ܷ��ʱ����˽�г�Ա
	friend class Test;
	// ��Ա��������Ԫ������һ�����е�ĳһ����Ա�����ܷ��ʱ����˽�г�Ա
	friend void Temp::visit(Test2& t2);
};
int Test2::s = 123;


void Temp::visit(Test2& t2) {
	cout << "��Ԫ����˽�����ԣ�" << t2.pv << endl;
}



void friendGet(Test2& t) {
	cout << "��Ԫ����˽�����ԣ�" << t.pv << endl;
}


void func_32() {
	Test2 t(1);
	Test2 t2(2);
	t.add(t2).add(t2).add(t2); //��ʽ����


	Test2* nulll_ptr = NULL;
	nulll_ptr->showWord(); // ��ָ��Ҳ�ܵ��÷�����Ҫ��֤���в�����ʵ�δ���ٿռ�����ԣ�
	nulll_ptr->showN(); // ͨ����this==NULL�жϣ������˷��ʵ�δ���ٿռ������

	// ��������������ǰ����const �����ܵ��ó�����(�;�̬����)���������ܷ��ʣ����ǲ����޸ģ������Ǿ�̬��mutabel��
	const Test2 tt(123);
	tt.s = 666;
	tt.showConst(); //���ܵ��ó�����

	friendGet(t);

	Temp tmp;
	tmp.visit(t);
}