#include"PortGate.h"
PortGate::PortGate(int color, int posx, int posy) {
	deque<int>x;
	deque<int>y;
	x.push_back(posx);
	y.push_back(posy);
	m_Position.push_back(x);
	m_Position.push_back(y);
	m_Color = color;
	m_Length = 1;
}

PortGate::PortGate(){
	deque<int>x;
	deque<int>y;
	x.push_back(0);
	y.push_back(0);
	m_Position.push_back(x);
	m_Position.push_back(y);
	m_Color = RED;
	m_Length = 1;
}

int PortGate::getColor() {
	return this->m_Color;
}


bool PortGate::BeHit(Snake& s) {
	pair<int, int> sp = s.getPositon(0);
	for (int i = 0; i < this->m_Length; ++i) {
		pair<int, int> wp = this->getPositon(i);
		if (wp == sp) {
			return true;
		}
	}
	return false;
}

void PortGate::Draw() {
	int x, y;
	pair<int, int> p = this->getPositon(0);
	x = p.first;
	y = p.second;
	setfillcolor(WHITE);
	solidrectangle(x * CELL_SIZE + 1, y * CELL_SIZE + (CELL_SIZE)-1, x * CELL_SIZE + CELL_SIZE - 1, y * CELL_SIZE + 1); // 绘制墙体

	setlinestyle(PS_SOLID, 4);
	setlinecolor(this->m_Color);
	rectangle(x * CELL_SIZE + 1, y * CELL_SIZE + (CELL_SIZE)-1, x * CELL_SIZE + CELL_SIZE - 1, y * CELL_SIZE + 1); // 绘制墙体
}

void PortGate::setPos(pair<int, int>p) {
	assert(p.first < COL && p.second < ROW);
	m_Position[0].pop_back();
	m_Position[1].pop_back();
	m_Position[0].push_back(p.first);
	m_Position[1].push_back(p.second);
}