#pragma once
#include"Object.h"
#include"Snake.h"
enum { SMALL, MIDDLE, BIG };
enum{ HIDE,SHOW };
class Food :public Object {
public:
	Food(int size, int color, int posx, int posy);
	bool BeHit(Snake& s);//如果被被蛇头撞上返回true	否则返回false
	int getColor();
	int getSize();
	int getStatus();
	void setStatus(int status);
	void Draw(); // 绘制食物
	void ChangeFlash(int n);
private:
	int m_Status;
	int m_Color;
	int m_Size;//SMALL增长２	MIDDLE增长4	BIG增长6
	int flash = 1;
};