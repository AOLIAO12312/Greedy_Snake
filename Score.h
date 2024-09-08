#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<string>
#include <mysql.h>
using namespace std;
class Score {
private:
	string  m_UserID;
	size_t m_ScoreID;
	unsigned int m_Score;
	int m_level;
public:
	Score();
	Score(unsigned ScoreID, string UserID, int level, unsigned int score);
	void insertScore(string id);
	void ID(string id);
	void ScoreID(int m_ScoreID);
	void theScore(int Score);
	void level(int level);
};
