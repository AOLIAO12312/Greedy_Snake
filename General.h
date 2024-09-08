#pragma once
#include<assert.h>
#include "GameScore.h"
#include "Level.h"
#include "User.h"
#include "Score.h"
#include "Time.h"
#include<conio.h>
enum { SINGLE, TWO_PLAYER };
enum { WALL, NO_WALL };
enum { SLOW, FAST, PAUSE };
class General {
public:
	General();
	int getPlayerMode();
	void setPlayerMode(int Mode);
	int getWallMode();
	void setWallMode(int Mode);
	void loadScores(const string& filename);
	void saveScores(const string& filename);
	void SortVgs();
	void AddGameScore(int time, int length);
	void ShowInfo();
	void setSpeed(int speed);
	int getSpeed();
	void LoadData();
	Time& TimeControl();

	void DeleteUser(string name, string password);

	vector<User> v_User;
	vector<Score> v_Score;
	Level level;
	vector<GameScore> vgs;
	Time m_time;

private:
	int m_Speed;
	int m_PlayerMode;
	int m_WallMode;
};