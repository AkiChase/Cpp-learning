#include <iostream>
using namespace std;

void func_24()
{
	//if���
	int score;
	cout << "�����������";
	cin >> score;
	if (score > 0)
	{
		cout << "����>0" << endl;
	}
	else if (score == 0)
	{
		cout << "����=0" << endl;
	}
	else
	{
		cout << "����<0" << endl;
	}

	//��Ŀ����� ע�������ű�֤���ȼ�
	cout << (score > 0 ? "����0" : "С����0") << endl;

	// �䷵�ص��Ǳ��� �ʿ��Լ�����ֵ
	int a = 10;
	int b = 0;
	(a > b ? a : b) = 100;
	cout << a << " " << b << endl;


	// switch���  ע��break
	//ȱ���ж�ֻ���� ���� ���� �ַ�
	//�ŵ�ִ��Ч�ʸ� �ṹ����
	switch (score)
	{
	case 11:
		cout << "����Ϊ10" << endl;
		break;

	case 1:
	case 2:
		cout << "����Ϊ1����2" << endl;
		break;

	default:
		cout << "����Ϊ����" << endl;
		break;
	}

	//ѭ��
	//1.while
	a = 5;
	while (a-- > 0)
	{
		cout << "a=" << a << endl;
	}

	//2. do while
	//3. forѭ��

	for (size_t i = 0; i < 5; i++)
	{
		cout << "i=" << i << endl;
		//ע��˴�i���������ڽ������ѭ������
	}



	//��ת��䣨������ת����䣬����ͷ��
	//goto ���
	//�����ǵ����ƴ��ڣ�ִ�е�gotoʱ����ת����ǵ�λ��
	a = 1;
FLAG:
	cout << "a=" << a << endl;

	if (a-- > 0) {
		goto FLAG;
	}

}