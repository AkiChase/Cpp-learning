#include <iostream>
using namespace std;

void func_42()
{
	char ch[5] = {'a'}; //����ֵ��ʼ��Ϊ0 ����д��ֵ��������
	cout << (int)ch[1] << endl;
	
	//��ȡ���鳤�ȣ����峤�ȣ�
	cout << (sizeof(ch) / sizeof(ch[0])) << endl;
	//������ ��Ӧ�����׸�Ԫ�����ڵĵ�ַ


	// ��̬������Ҫ p = new int[3] ����ָ����в��� ��֮�����о�

}