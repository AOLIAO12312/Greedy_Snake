#pragma once
#include"Object.h"
#include"Snake.h"
class PortGate :public Object {
public:
	PortGate(int color, int posx, int posy);
	PortGate();
	bool BeHit(Snake& s);//���������ͷײ�Ϸ���true	���򷵻�false
	int getColor();
	void Draw(); // ���ƴ�����
	void setPos(pair<int, int>p);
private:
	int m_Color;
};