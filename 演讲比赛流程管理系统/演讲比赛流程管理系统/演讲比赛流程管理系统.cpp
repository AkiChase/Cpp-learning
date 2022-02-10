#include <iostream>
using namespace std;
#include <ctime>
#include "SpeechManager.h"

int main() {
	srand((unsigned int)time(NULL));
	SpeechManager sm;
	int choice;

	while (true)
	{
		sm.showMenu();
		cout << "ÇëÊäÈëÑ¡Ïî£º" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			sm.exitSystem();
			break;
		case 1:
			sm.startMatch();
			break;
		case 2:
			sm.showRecords();
			break;
		case 3:
			sm.clearRecords();
			break;
		}
		system("pause");
		system("cls");
	}

	system("pause");
	return 0;
}