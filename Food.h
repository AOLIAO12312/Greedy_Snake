#pragma once
#include"Object.h"
#include"Snake.h"
enum { SMALL, MIDDLE, BIG };
enum{ HIDE,SHOW };
class Food :public Object {
public:
	Food(int size, int color, int posx, int posy);
	bool BeHit(Snake& s);//���������ͷײ�Ϸ���true	���򷵻�false
	int getColor();
	int getSize();
	int getStatus();
	void setStatus(int status);
	void Draw(); // ����ʳ��
	void ChangeFlash(int n);
private:
	int m_Status;
	int m_Color;
	int m_Size;//SMALL������	MIDDLE����4	BIG����6
	int flash = 1;
};