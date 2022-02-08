#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <ctime>

class Player {
public:
	Player(string name, int score) :m_Name(name), m_Score(score) {}

	string m_Name;
	int m_Score; // 平均分
};


void createPlayer(vector<Player>& v) {
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		// 注意！"xxxx"是const char[]类型，没有重载+运算符
		v.push_back(Player(string("玩家") + nameSeed[i], 0));
	}
}

void printPlayers(vector<Player>& v) {
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名:" << it->m_Name << "\t平均分:" << it->m_Score << endl;
	}
}

void setScore(vector<Player>& v) {
	for (auto it = v.begin(); it != v.end(); it++)
	{
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			d.push_back(score);
		}

		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();

		int sumScore = 0;
		for (auto dit = d.begin(); dit != d.end(); dit++)
		{
			sumScore += *dit;
		}
		int avgScore = sumScore / d.size();
		it->m_Score = avgScore;
	}
}

void func_44() {
	srand((unsigned int)time(NULL));

	vector<Player> v;
	createPlayer(v);
	printPlayers(v);
	setScore(v);
	cout << "评分后：" << endl;
	printPlayers(v);

}