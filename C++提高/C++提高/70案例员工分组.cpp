#include <iostream>
using namespace std;
#include <ctime>
#include <string>
#include <map>
#include <vector>

#define CHEHUA 1
#define MEISHU 2
#define YANFA 3


class Worker {
public:
	Worker(string name, int no, int salary) :m_Name(name), m_DptNo(no), m_Salary(salary) {}
	string m_Name;
	int m_DptNo;
	int m_Salary;
};

void createWorker(string name, vector<Worker>& v) {
	int no = rand() % 3 + 1; // 1-3
	int salary = rand() % 501 + 1000; // 1000 - 1500
	v.push_back(Worker(name, no, salary)); // 是拷贝
	// 注意开辟到堆区的话要写好自定义类型的拷贝构造
}

void workersInit(vector<Worker>& v) {
	for (int i = 0; i < 10; i++)
	{
		createWorker(string("员工") + char(65 + i), v);
	}
}

void setGroup(vector<Worker>& v, multimap<int, Worker>& m) {
	for (auto it = v.begin(); it != v.end(); it++)
	{
		m.insert(make_pair(it->m_DptNo, *it));
	}
}

void showWorkersByGroup(multimap<int, Worker>& m) {
	int count;
	multimap<int, Worker>::const_iterator it;

	cout << "策划部门:" << endl;
	it = m.find(CHEHUA);
	count = m.count(CHEHUA);
	for (int index = 0; it != m.end() && index < count; it++, index++)
	{
		cout << "姓名:" << it->second.m_Name << "\t部门编号:" << it->second.m_DptNo
			<< "\t工资:" << it->second.m_Salary << endl;
	}
	cout << "--------------------" << endl;

	cout << "美术部门:" << endl;
	it = m.find(MEISHU);
	count = m.count(MEISHU);
	for (int index = 0; it != m.end() && index < count; it++, index++)
	{
		cout << "姓名:" << it->second.m_Name << "\t部门编号:" << it->second.m_DptNo
			<< "\t工资:" << it->second.m_Salary << endl;
	}
	cout << "--------------------" << endl;

	cout << "研发部门:" << endl;
	it = m.find(YANFA);
	count = m.count(YANFA);
	for (int index = 0; it != m.end() && index < count; it++, index++)
	{
		cout << "姓名:" << it->second.m_Name << "\t部门编号:" << it->second.m_DptNo
			<< "\t工资:" << it->second.m_Salary << endl;
	}
}

void func_70() {
	srand((unsigned int)time(NULL));
	vector<Worker> vWorkers;
	vWorkers.reserve(10);
	workersInit(vWorkers);

	multimap<int, Worker> mWorkers;
	setGroup(vWorkers, mWorkers);
	showWorkersByGroup(mWorkers);

}
