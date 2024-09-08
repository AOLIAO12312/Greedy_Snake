#include"Level.h"

void Level1(vector<Snake*>& v_Snake, vector<Food*>& v_Food, vector<Wall*>& v_Wall, vector<pair<PortGate*, PortGate*>>& v_PortGate) {
	Snake* snake1 = new Snake(DOWN, 5, 14, 5);
	v_Snake.push_back(snake1);
	Food* food1 = new Food(SMALL, FOOD_COLOR, 12, 12);
	Food* food2 = new Food(SMALL, FOOD_COLOR, 25, 25);
	Food* food3 = new Food(SMALL, FOOD_COLOR, 27, 29);
	Food* food4 = new Food(SMALL, FOOD_COLOR, 29, 31);
	v_Food.push_back(food1);
	v_Food.push_back(food2);
	v_Food.push_back(food3);
	v_Food.push_back(food4);
	PortGate* p1 = new PortGate(RED, COL - 1, 0);
	PortGate* p2 = new PortGate(RED, 0, ROW - 1);
	pair<PortGate*, PortGate*> gate1(p1, p2);
	PortGate* p3 = new PortGate(BLUE, 0, 0);
	PortGate* p4 = new PortGate(BLUE, COL - 1, ROW - 1);
	pair<PortGate*, PortGate*> gate2(p3, p4);
	v_PortGate.push_back(gate1);
	v_PortGate.push_back(gate2);
}

void Level2(vector<Snake*>& v_Snake, vector<Food*>& v_Food, vector<Wall*>& v_Wall, vector<pair<PortGate*, PortGate*>>& v_PortGate) {
	Snake* snake1 = new Snake(DOWN, 5, 5, 5);
	v_Snake.push_back(snake1);
	Food* food1 = new Food(SMALL, FOOD_COLOR, 12, 12);
	Food* food2 = new Food(SMALL, FOOD_COLOR, 25, 25);
	Food* food3 = new Food(SMALL, FOOD_COLOR, 27, 29);
	Food* food4 = new Food(SMALL, FOOD_COLOR, 29, 31);
	v_Food.push_back(food1);
	v_Food.push_back(food2);
	v_Food.push_back(food3);
	v_Food.push_back(food4);


	Wall* wall1 = new Wall(WALL_COLOR, RIGHT, 25, 7, 14);
	Wall* wall2 = new Wall(WALL_COLOR, DOWN, 23, 19, 3);//中点（14，19）
	v_Wall.push_back(wall1);
	v_Wall.push_back(wall2);

	PortGate* p1 = new PortGate(RED, 18, 13);//中点（19，14）xy反转
	PortGate* p2 = new PortGate(RED, 20, 15);
	pair<PortGate*, PortGate*> gate1(p1, p2);
	PortGate* p3 = new PortGate(BLUE, 20, 13);
	PortGate* p4 = new PortGate(BLUE, 18, 15);
	pair<PortGate*, PortGate*> gate2(p3, p4);
	v_PortGate.push_back(gate1);
	v_PortGate.push_back(gate2);
}



void Level3(vector<Snake*>& v_Snake, vector<Food*>& v_Food, vector<Wall*>& v_Wall, vector<pair<PortGate*, PortGate*>>& v_PortGate) {
	Snake* snake1 = new Snake(DOWN, 5, 14, 5);
	v_Snake.push_back(snake1);
	Wall* wall1 = new Wall(WALL_COLOR, DOWN, 10, 0, 0);
	Wall* wall2 = new Wall(WALL_COLOR, UP, 20, 10, ROW - 1);
	Wall* wall3 = new Wall(WALL_COLOR, DOWN, 20, 30, 0);
	Wall* wall4 = new Wall(WALL_COLOR, UP, 10, COL - 1, ROW - 1);
	Wall* wall5 = new Wall(WALL_COLOR, RIGHT, 5, 1, 0);
	Wall* wall6 = new Wall(WALL_COLOR, LEFT, 5, COL - 2, ROW - 1);
	v_Wall.push_back(wall1);
	v_Wall.push_back(wall2);
	v_Wall.push_back(wall3);
	v_Wall.push_back(wall4);
	v_Wall.push_back(wall5);
	v_Wall.push_back(wall6);
	Food* food1 = new Food(SMALL, FOOD_COLOR, 12, 12);
	Food* food2 = new Food(SMALL, FOOD_COLOR, 25, 25);
	Food* food3 = new Food(SMALL, FOOD_COLOR, 27, 29);
	v_Food.push_back(food1);
	v_Food.push_back(food2);
	v_Food.push_back(food3);
	PortGate* p1 = new PortGate(RED, COL - 1, 0);
	PortGate* p2 = new PortGate(RED, 0, ROW - 1);
	pair<PortGate*, PortGate*> gate1(p1, p2);
	PortGate* p3 = new PortGate(BLUE, 1, 1);
	PortGate* p4 = new PortGate(BLUE, COL - 2, ROW - 2);
	pair<PortGate*, PortGate*> gate2(p3, p4);
	v_PortGate.push_back(gate1);
	v_PortGate.push_back(gate2);
}

void Level4(vector<Snake*>& v_Snake, vector<Food*>& v_Food, vector<Wall*>& v_Wall, vector<pair<PortGate*, PortGate*>>& v_PortGate) {
	Snake* snake1 = new Snake(UP, 4, 10, 10);
	v_Snake.push_back(snake1);
	Food* food1 = new Food(SMALL, FOOD_COLOR, 12, 12);
	Food* food2 = new Food(SMALL, FOOD_COLOR, 25, 25);
	Food* food3 = new Food(SMALL, FOOD_COLOR, 27, 29);
	Food* food4 = new Food(SMALL, FOOD_COLOR, 29, 31);
	v_Food.push_back(food1);
	v_Food.push_back(food2);
	v_Food.push_back(food3);
	v_Food.push_back(food4);


	Wall* wall1 = new Wall(WALL_COLOR, RIGHT, 40, 0, 14);
	Wall* wall2 = new Wall(WALL_COLOR, DOWN, 30, 19, 0);//中点（14，19）
	v_Wall.push_back(wall1);
	v_Wall.push_back(wall2);

	PortGate* p1 = new PortGate(RED, 18, 13);//中点（19，14）xy反转
	PortGate* p2 = new PortGate(RED, 20, 15);
	pair<PortGate*, PortGate*> gate1(p1, p2);
	PortGate* p3 = new PortGate(BLUE, 20, 13);
	PortGate* p4 = new PortGate(BLUE, 18, 15);
	pair<PortGate*, PortGate*> gate2(p3, p4);
	v_PortGate.push_back(gate1);
	v_PortGate.push_back(gate2);
}

void Level5(vector<Snake*>& v_Snake, vector<Food*>& v_Food, vector<Wall*>& v_Wall, vector<pair<PortGate*, PortGate*>>& v_PortGate) {
	Snake* snake1 = new Snake(UP, 4, 10, 10);
	v_Snake.push_back(snake1);
	Food* food1 = new Food(SMALL, FOOD_COLOR, 12, 12);
	Food* food2 = new Food(SMALL, FOOD_COLOR, 25, 25);
	Food* food3 = new Food(SMALL, FOOD_COLOR, 27, 29);
	Food* food4 = new Food(SMALL, FOOD_COLOR, 29, 31);
	v_Food.push_back(food1);
	v_Food.push_back(food2);
	v_Food.push_back(food3);
	v_Food.push_back(food4);


	Wall* wall1 = new Wall(WALL_COLOR, RIGHT, 40, 0, 14);
	Wall* wall2 = new Wall(WALL_COLOR, DOWN, 30, 19, 0);//中点（14，19）
	Wall* wall3 = new Wall(WALL_COLOR, DOWN, 30, 0, 0);
	Wall* wall4 = new Wall(WALL_COLOR, DOWN, 30, 39, 0);
	v_Wall.push_back(wall1);
	v_Wall.push_back(wall2);
	v_Wall.push_back(wall3);
	v_Wall.push_back(wall4);

	PortGate* p1 = new PortGate(RED, 18, 13);//中点（19，14）xy反转
	PortGate* p2 = new PortGate(RED, 20, 15);
	pair<PortGate*, PortGate*> gate1(p1, p2);
	PortGate* p3 = new PortGate(BLUE, 20, 13);
	PortGate* p4 = new PortGate(BLUE, 18, 15);
	pair<PortGate*, PortGate*> gate2(p3, p4);
	v_PortGate.push_back(gate1);
	v_PortGate.push_back(gate2);
}

Level::Level() :m_LevelNum(1) {
	v_LevelFunc.push_back(Level1);
	v_LevelFunc.push_back(Level2);
	v_LevelFunc.push_back(Level3);
	v_LevelFunc.push_back(Level4);
	v_LevelFunc.push_back(Level5);
}

void Level::SetLevel(int num) {
	assert(num > 0 && num <= Max_Level);
	this->m_LevelNum = num;
}
int Level::GetLevel() {
	return this->m_LevelNum;
}
void Level::LoadLevel(vector<Snake*>& v_Snake, vector<Food*>& v_Food, vector<Wall*>& v_Wall, vector<pair<PortGate*, PortGate*>>& v_PortGate) {
	v_LevelFunc[m_LevelNum-1](v_Snake, v_Food, v_Wall, v_PortGate);
}
void Level::LevelUp() {
	if (m_LevelNum < Max_Level) {
		++m_LevelNum;
	}
}
