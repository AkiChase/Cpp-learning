#include <iostream>
using namespace std;
#include <string>
#include "WorkerManager.h"


int main() {
	WorkerManager wm;
	int choice;

	while (true)
	{
		system("cls");
		wm.showMenu();
		cin >> choice;

		switch (choice)
		{
		case 0:
			wm.exitSystem();
			break;
		case 1:
			wm.addEmp();
			break;
		case 2:
			wm.showEmp();
			break;
		case 3:
			wm.delEmp();
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			cout << "ÇëÊäÈë0-7µÄÐòºÅ£¡" << endl;
		}
		system("pause");
	}
	system("pause");
	return 0;
}