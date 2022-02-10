#pragma once
#include "Identity.h"
class Admin :
	public Identity
{
public:
	Admin();
	Admin(string name, string pwd);

	//�˵�����
	virtual void openMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFile();

	//��ʼ������
	void initVector();

	//����ظ� ����1 ���ѧ��/ְ����  ����2  �������
	bool checkRepeat(int id, int type);
};

