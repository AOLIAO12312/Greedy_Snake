#pragma once
#include"Object.h"
#include"Snake.h"
class Wall : public Object{
public:
	Wall(int Color, int Orientation, int Length, int x, int y);
	bool BeHit(Snake& s);//���������ͷײ�Ϸ���true	���򷵻�false
	int getColor();
	void Draw();
	static void DrawWallBody(int x, int y);
private:
	int m_Color;
};