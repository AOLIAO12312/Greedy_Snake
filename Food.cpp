#include"Food.h"
Food::Food(int size,int color,int posx,int posy) {
	deque<int>x;
	deque<int>y;
	x.push_back(posx);
	y.push_back(posy);
	m_Size = size;
	m_Position.push_back(x);
	m_Position.push_back(y);
	m_Color = color;
	m_Length = 1;
	m_Status = HIDE;
}

int Food::getColor() {
	return this->m_Color;
}

int Food::getSize() {
	return this->m_Size;
}

bool Food::BeHit(Snake& s) {
	pair<int, int> sp = s.getPositon(0);
	for (int i = 0; i < this->m_Length; ++i) {
		pair<int, int> wp = this->getPositon(i);
		if (wp == sp) {
			return true;
		}
	}
	return false;
}

void Food::Draw() {
	int x, y;
	pair<int, int> p = this->getPositon(0);
	x = p.first;
	y = p.second;
	setfillcolor(this->m_Color);
	switch (flash) {
	case 1:
		solidcircle(x * CELL_SIZE + (CELL_SIZE / 2), y * CELL_SIZE + (CELL_SIZE / 2), 7);
		ChangeFlash(2);
		break;
	case 2:
		solidcircle(x * CELL_SIZE + (CELL_SIZE / 2), y * CELL_SIZE + (CELL_SIZE / 2), 10);
		ChangeFlash(1);
		break;
	default:
		break;
	}
}

void Food::ChangeFlash(int num) {
	flash = num;
}

int Food::getStatus() {
	return m_Status;
}

void Food::setStatus(int status) {
	assert(status == SHOW || status == HIDE);
	m_Status = status;
}