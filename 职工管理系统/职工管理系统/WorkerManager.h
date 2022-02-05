#pragma once
#include <iostream>
#include "Worker.h"
using namespace std;

class WorkerManager
{
public:
	WorkerManager();

	~WorkerManager();

	void showMenu();
	void exitSystem();
	void addEmp();
	void save();
	int getEmpNum();
	void initEmp();
	void showEmp();
	int getEmpIndex(int id);
	void delEmp();

	int m_empNum;
	Worker** m_empArr;
	bool m_FileIsEmpty;
};

