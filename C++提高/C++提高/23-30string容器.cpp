#include <iostream>
using namespace std;
#include <string>

//string��װ��charָ�룬��һ���ַ�����

void func_23() {
	// �ַ�������
	string s1; // Ĭ���޲ι���

	string s2("�����ַ���");

	string s3(s2); // ʹ��string����ʼ��
	string s4(10, 'a'); // ʹ��n���ַ�

	cout << "------------------" << endl;

	//�ַ�����ֵ
	//����= ����չʾ
	s1.assign("һ��������", 4); // assign(s, int n) ǰn���ַ���nʡ���������ַ���
	cout << s1 << endl;

	s1.assign(10, 'k'); // �ظ�n���ַ�
	cout << s1 << endl;

	cout << "------------------" << endl;

	//�ַ���ƴ��
	s1 += "������";
	cout << s1 << endl;

	s1.append("123");
	cout << s1 << endl;

	s1.append("��������������������", 2); //ƴ���ַ�����ǰn���ַ�
	cout << s1 << endl;

	s1.append("12�ٺ�3456789", 2, 4); //ƴ���ַ�����n��ʼ��m���ַ� [n, n+m)
	cout << s1 << endl;

	cout << "------------------" << endl;

	// �ַ�������
	cout << "pos = " << int(s1.find("�ٺ�")) << endl; // δ�ҵ�����-1
	cout << "pos = " << int(s1.rfind("�ٺ�")) << endl; // ���ҿ�ʼ�ң������һ�����ҽ��

	// �ַ����滻
	s1.replace(0, 3, "Ŷ��Ŷ��Ŷ��"); // ��[n, n+m) �滻Ϊ������ַ��������ص��ǵ�ǰ�ַ��������ã����Ḵ��һ�ݣ�
	cout << s1 << endl;

	cout << "------------------" << endl;
	
	// �ַ����Ƚ�
	// stringҲ����ʹ��> < = >=�ȵ������
	// ���ַ���ascii����бȽϣ����αȽ��ַ������ַ��Ĳ�����0��ȫ
	// ��s1 > s2 ����1��s1=s2
	s1 = "abcd";
	s2 = "zb";
	cout << s1.compare(s2) << endl;

	cout << "------------------" << endl;
	//�����ַ��������޸��ַ���
	s1[2] = 'T';
	s1.at(1) = 'A';
	cout << s1 << endl;

	cout << "------------------" << endl;
	// �����ַ���
	s1.insert(1, "��������");
	cout << s1 << endl;

	//ɾ���ַ���
	s1.erase(1, 8); //ɾ����[n,n+m)
	cout << s1 << endl;

	cout << "------------------" << endl;
	// ��ȡ�Ӵ�(�᷵��һ���µ�string��
	cout << s1.substr(1, 2) << endl; //��ȡ[n,n+m)

}