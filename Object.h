#pragma once
#include<easyx.h>
#include<iostream>
#include<vector>
#include <algorithm>
#include <fstream>
#include<assert.h>
#include<deque>
#define ROW 30//��
#define COL 40//��
#define M_BLACK RGB(10,5,9)
#define LIGHTPURPLE RGB(176,164,227)
#define MIDDLEPURPLE RGB(164,171,214)
#define CELL_SIZE 20
#define Snake_Body_Size 10
#define WALL_COLOR RGB(48,124,140)
#define FOOD_COLOR RGB(239,195,44)
enum { UP, DOWN, LEFT, RIGHT };
using namespace std;
class Object {
public:
	pair<int, int> getPositon(int x);
	int getLength();
	virtual void Draw() = 0;
	bool Occupied(pair<int, int> p);//�жϸ�λ���Ƿ񱻸ö���ռ��
protected:
	void AddNode(int x, int y);//�����Ʒ�����ص����꣨��֤������
	vector<deque<int>>m_Position;
	int m_Length;
};
