#include <iostream>
#include <string>
using namespace std;
#define PI 3.1415926


// struct �� class ����һ��������д����
// ֻ��Ĭ�ϵ�Ȩ�޲�ͬ��ǰ��Ĭ��Ϊ����������Ĭ��Ϊ˽��


// ����һ��Բ����
class Circle
{
	//����Ȩ�ޣ������Ĳ���
public:
	//���е����Ժ���Ϊ����Ϊ ��Ա ���Ա���ԣ���Ա��������Ա��������Ա����
	int r; // �뾶
	double getZC() {
		return 2 * PI * r;
	}

	string getName() { //˽�г�Ա���������ַ�ʽ��������ö���д��Ȩ��
		// ����д�߼�����name���г�ʼ��
		return name;
	}

	bool setName(string newName) {
		if (newName.length() > 6) // ��д���������������ж�(�жϴ��������Ƿ���Ч)
		{
			return false;
		}
		else
		{
			name = newName;
			return true;
		}
	}

	//public�ȵȿ��Զ����д
public:
	string name = "Բ";

	//������Ա���ڲ����Է��ʣ��ⲿ���ܷ��� ���ǣ���������Է��ʣ������̳е�ʱ���ã�
protected:
	string son = "����";

	// ˽�г�Ա���ڲ����Է��ʣ��ⲿ���ܷ��� ����Ҳ���ܷ���
private:
	string secret = "˽��";
};

void func_16() {
	// ʵ����Ϊ����c
	Circle c;
	c.r = 5;
	cout << "Բ���ܳ�Ϊ=" << c.getZC() << endl;

	cout << c.getName() << endl;
	c.setName("һ��������"); // ע��һ������2������
	cout << c.getName() << endl;
	c.setName("������"); // ע��һ������2������
	cout << c.getName() << endl;

}
