#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include "Speaker.h"

class SpeechManager
{
public:
	SpeechManager();
	~SpeechManager();
	void showMenu();
	void exitSystem();
	void startMatch();
	void showRecords();
	void clearRecords();

	void initSpeech();
	void createSpeakers();
	void speechDrew();
	void speechContest();
	void showScore();
	void saveScore();
	void loadRecords();

	vector<int> vSpeakers;
	map<int, Speaker> mSpeakers;
	int m_Index;
	bool fileEmpty;
	map<int, vector<string>> m_Records;

};

