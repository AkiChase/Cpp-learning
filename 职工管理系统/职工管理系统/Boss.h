#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "Worker.h"

class Boss :
	public Worker
{
public:
	Boss(int id, string name, int dId);
	void showInfo();
	string getDeptName();
};

