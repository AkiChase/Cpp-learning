#include <iostream>
using namespace std;
#include <algorithm>
#include <deque>
#include <numeric>
#include <fstream>
#include "SpeechManager.h"


SpeechManager::SpeechManager() {
	this->initSpeech();
	this->createSpeakers();
}

SpeechManager::~SpeechManager() {

}

void SpeechManager::initSpeech() {
	this->vSpeakers.clear();
	this->mSpeakers.clear();
	this->m_Index = 1;
}

void SpeechManager::createSpeakers() {
	for (int i = 0; i < 12; i++)
	{
		Speaker sp;
		sp.m_Name = string("ѡ��") + char(65 + i);
		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}
		this->vSpeakers.push_back(1001 + i);
		this->mSpeakers.insert(make_pair(1001 + i, sp));
	}
}

void SpeechManager::showMenu() {
	cout << "********************************" << endl;
	cout << "********��ӭ�μ��ݽ�����********" << endl;
	cout << "*********1.��ʼ�ݽ�����*********" << endl;
	cout << "*********2.�鿴�����¼*********" << endl;
	cout << "*********3.��ձ�����¼*********" << endl;
	cout << "*********0.�˳���������*********" << endl;
	cout << "********************************" << endl;
	cout << endl;
}

void SpeechManager::exitSystem() {
	cout << "��ӭ�´�ʹ��~" << endl;
	system("pause");
	exit(0);
}

void SpeechManager::speechDrew() {
	cout << "�� " << this->m_Index << " �ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "--------------------" << endl;
	cout << "��ǩ���˳������" << endl;
	random_shuffle(this->vSpeakers.begin(), this->vSpeakers.end());
	for (auto it = this->vSpeakers.begin(); it != this->vSpeakers.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "--------------------" << endl;
	system("pause");
	cout << endl;
}

void SpeechManager::speechContest() {
	cout << "------------ �� " << this->m_Index << " �ֱ�����ʽ��ʼ ------------" << endl;

	multimap<double, int, greater<double>>groupScore; //����6���˵ķ������������С������
	vector<int> vv; //��ʱ���������ں�vSpeaker����

	int index = 1;
	for (auto it = this->vSpeakers.begin(); it != this->vSpeakers.end(); it++, index++)
	{
		deque<double> d; //10λ��ί���
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f; // ����10.f����ȡС��
			d.push_back(score);
		}
		sort(d.begin(), d.end(), greater<double>());
		d.pop_back(); d.pop_front();

		double avg = accumulate(d.begin(), d.end(), 0.0) / d.size();
		this->mSpeakers[*it].m_Score[this->m_Index - 1] = avg;
		groupScore.insert(make_pair(avg, *it));

		if (index % 6 == 0) //6���ˣ�һ�������
		{
			cout << index / 6 << "�����������" << endl;

			int index = 1;
			for (auto it = groupScore.begin(); it != groupScore.end(); it++, index++)
			{
				Speaker& sp = this->mSpeakers[it->second];
				cout << "���:" << it->second << "\t����:" << sp.m_Name << "\t�ɼ�:" << sp.m_Score[this->m_Index - 1] << endl;
				if (index <= 3)
				{
					vv.push_back(it->second);
				}
			}
			cout << endl;
			groupScore.clear();
		}
	}

	this->vSpeakers.swap(vv); //��һ�ֱ����ĳ�Ա
	cout << "-------------- �� " << this->m_Index << " �ֱ������� --------------" << endl;
	system("pause");
	system("cls");
}

void SpeechManager::showScore() {
	cout << "----------- �� " << this->m_Index << " �ֱ�������ѡ������ -----------" << endl;
	for (auto it = this->vSpeakers.begin(); it != this->vSpeakers.end(); it++)
	{
		Speaker& sp = this->mSpeakers[*it];
		cout << "���:" << *it << "\t����:" << sp.m_Name << "\t�ɼ�:" << sp.m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
}

void SpeechManager::saveScore() {
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);
	for (auto it = this->vSpeakers.begin(); it != this->vSpeakers.end(); it++)
	{
		ofs << *it << ","
			<< this->mSpeakers[*it].m_Score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "��¼�ѱ���" << endl;
}

void SpeechManager::startMatch() {
	for (int i = 1; i < 3; i++)
	{
		this->m_Index = i;
		//1.��ǩ
		this->speechDrew();
		//2.����
		this->speechContest();
		//3.��ʾ�������
		this->showScore();
	}
	// �������ս��
	this->saveScore();
	cout << "�����ݽ�������ʽ��������ӭ���Ĳ���" << endl;

	//���³�ʼ��
	this->initSpeech();
	this->createSpeakers();
}

void SpeechManager::loadRecords() {
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		this->fileEmpty = true;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->fileEmpty = true;
		ifs.close();
		return;
	}

	ifs.putback(ch); //�Ѹոն�ȡ��1���ַ��Ż�

	int lineNo = 1;
	int pos;
	int startPos;
	vector<string> v;
	string line;
	while (getline(ifs, line))
	{
		startPos = 0;
		pos = line.find(",", startPos);
		if (pos == -1) //δ�ҵ� "," ��������
		{
			break;
		}

		v.push_back(line.substr(startPos, pos - startPos));  //�����ȡ����
		startPos = pos + 1;
		for (int i = 0; i < 5; i++)
		{
			pos = line.find(",", startPos);
			v.push_back(line.substr(startPos, pos - startPos));
			startPos = pos + 1;// +1 ������������λ��
		}

		this->m_Records.insert(make_pair(lineNo, v));
		this->fileEmpty = false;
		++lineNo;
	}

	ifs.close();
}

void SpeechManager::showRecords() {
	this->loadRecords();
	if (this->fileEmpty)
	{
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
		return;
	}
	for (auto it = this->m_Records.begin();it!= this->m_Records.end();it++)
	{
		cout << "��" << it->first << "��:" << endl;
		cout << "�ھ����:" << it->second[0] << "\t�÷�:" << it->second[1] << endl;
		cout << "�Ǿ����:" << it->second[2] << "\t�÷�:" << it->second[3] << endl;
		cout << "�������:" << it->second[4] << "\t�÷�:" << it->second[5] << endl;
		cout << endl;
	}
}

void SpeechManager::clearRecords() {
	ofstream ofs("speech.csv", ios::trunc);
	ofs.close();
	this->m_Records.clear();
	cout << "��¼����գ�" << endl;
}
