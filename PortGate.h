#pragma once
#include"Object.h"
#include"Snake.h"
class PortGate :public Object {
public:
	PortGate(int color, int posx, int posy);
	PortGate();
	bool BeHit(Snake& s);//如果被被蛇头撞上返回true	否则返回false
	int getColor();
	void Draw(); // 绘制传送门
	void setPos(pair<int, int>p);
private:
	int m_Color;
};