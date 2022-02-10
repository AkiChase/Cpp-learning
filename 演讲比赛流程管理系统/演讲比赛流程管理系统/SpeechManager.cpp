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
		sp.m_Name = string("选手") + char(65 + i);
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
	cout << "********欢迎参加演讲比赛********" << endl;
	cout << "*********1.开始演讲比赛*********" << endl;
	cout << "*********2.查看往届记录*********" << endl;
	cout << "*********3.清空比赛记录*********" << endl;
	cout << "*********0.退出比赛程序*********" << endl;
	cout << "********************************" << endl;
	cout << endl;
}

void SpeechManager::exitSystem() {
	cout << "欢迎下次使用~" << endl;
	system("pause");
	exit(0);
}

void SpeechManager::speechDrew() {
	cout << "第 " << this->m_Index << " 轮比赛选手正在抽签" << endl;
	cout << "--------------------" << endl;
	cout << "抽签结果顺序如下" << endl;
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
	cout << "------------ 第 " << this->m_Index << " 轮比赛正式开始 ------------" << endl;

	multimap<double, int, greater<double>>groupScore; //保存6个人的分数，用于输出小组排名
	vector<int> vv; //临时容器，用于和vSpeaker交换

	int index = 1;
	for (auto it = this->vSpeakers.begin(); it != this->vSpeakers.end(); it++, index++)
	{
		deque<double> d; //10位评委打分
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f; // 除以10.f来获取小数
			d.push_back(score);
		}
		sort(d.begin(), d.end(), greater<double>());
		d.pop_back(); d.pop_front();

		double avg = accumulate(d.begin(), d.end(), 0.0) / d.size();
		this->mSpeakers[*it].m_Score[this->m_Index - 1] = avg;
		groupScore.insert(make_pair(avg, *it));

		if (index % 6 == 0) //6个人，一组完成了
		{
			cout << index / 6 << "组比赛排名：" << endl;

			int index = 1;
			for (auto it = groupScore.begin(); it != groupScore.end(); it++, index++)
			{
				Speaker& sp = this->mSpeakers[it->second];
				cout << "编号:" << it->second << "\t姓名:" << sp.m_Name << "\t成绩:" << sp.m_Score[this->m_Index - 1] << endl;
				if (index <= 3)
				{
					vv.push_back(it->second);
				}
			}
			cout << endl;
			groupScore.clear();
		}
	}

	this->vSpeakers.swap(vv); //下一轮比赛的成员
	cout << "-------------- 第 " << this->m_Index << " 轮比赛结束 --------------" << endl;
	system("pause");
	system("cls");
}

void SpeechManager::showScore() {
	cout << "----------- 第 " << this->m_Index << " 轮比赛晋级选手如下 -----------" << endl;
	for (auto it = this->vSpeakers.begin(); it != this->vSpeakers.end(); it++)
	{
		Speaker& sp = this->mSpeakers[*it];
		cout << "编号:" << *it << "\t姓名:" << sp.m_Name << "\t成绩:" << sp.m_Score[this->m_Index - 1] << endl;
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
	cout << "记录已保存" << endl;
}

void SpeechManager::startMatch() {
	for (int i = 1; i < 3; i++)
	{
		this->m_Index = i;
		//1.抽签
		this->speechDrew();
		//2.比赛
		this->speechContest();
		//3.显示晋级结果
		this->showScore();
	}
	// 保存最终结果
	this->saveScore();
	cout << "本届演讲比赛正式结束！欢迎您的参与" << endl;

	//重新初始化
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

	ifs.putback(ch); //把刚刚读取的1个字符放回

	int lineNo = 1;
	int pos;
	int startPos;
	vector<string> v;
	string line;
	while (getline(ifs, line))
	{
		startPos = 0;
		pos = line.find(",", startPos);
		if (pos == -1) //未找到 "," 此行跳过
		{
			break;
		}

		v.push_back(line.substr(startPos, pos - startPos));  //插入截取内容
		startPos = pos + 1;
		for (int i = 0; i < 5; i++)
		{
			pos = line.find(",", startPos);
			v.push_back(line.substr(startPos, pos - startPos));
			startPos = pos + 1;// +1 跳过逗号所在位置
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
		cout << "文件为空或不存在" << endl;
		return;
	}
	for (auto it = this->m_Records.begin();it!= this->m_Records.end();it++)
	{
		cout << "第" << it->first << "届:" << endl;
		cout << "冠军编号:" << it->second[0] << "\t得分:" << it->second[1] << endl;
		cout << "亚军编号:" << it->second[2] << "\t得分:" << it->second[3] << endl;
		cout << "季军编号:" << it->second[4] << "\t得分:" << it->second[5] << endl;
		cout << endl;
	}
}

void SpeechManager::clearRecords() {
	ofstream ofs("speech.csv", ios::trunc);
	ofs.close();
	this->m_Records.clear();
	cout << "记录已清空！" << endl;
}
