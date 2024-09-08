#pragma once
#define Max_Level 9
#include<assert.h>
#include<vector>
#include"Snake.h"
#include"Wall.h"
#include"Food.h"
#include"PortGate.h"
using namespace std;
typedef void (*LevelFunc)(vector<Snake*>&, vector<Food*>&, vector<Wall*>&, vector<pair<PortGate*, PortGate*>>&);
class Level {
private:
	int m_LevelNum;
	vector<LevelFunc>v_LevelFunc;
public:
	Level();
	void SetLevel(int Num);
	int GetLevel();
	void LoadLevel(vector<Snake*>& v_Snake, vector<Food*>& v_Food, vector<Wall*>& v_Wall, vector<pair<PortGate*, PortGate*>>& v_PortGate);
	void LevelUp();
};