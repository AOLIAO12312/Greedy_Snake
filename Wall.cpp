#include"Wall.h"
Wall::Wall(int Color, int Orientation, int Length, int beginx, int beginy) {
	m_Color = Color;
	deque<int>x;
	deque<int>y;
	if (Orientation == UP) {
		assert(beginy - Length >= 0);
		for (int i = 0; i < Length; ++i) {
			x.push_back(beginx);
			y.push_back(beginy - i);
		}
	}
	else if (Orientation == DOWN) {
		assert(beginy + Length <= ROW);
		for (int i = 0; i < Length; ++i) {
			x.push_back(beginx);
			y.push_back(beginy + i);
		}
	}
	else if (Orientation == RIGHT) {
		assert(beginx + Length <= COL);
		for (int i = 0; i < Length; ++i) {
			x.push_back(beginx + i);
			y.push_back(beginy);
		}
	}
	else if (Orientation == LEFT) {
		assert(beginx - Length >= 0);
		for (int i = 0; i < Length; ++i) {
			x.push_back(beginx - i);
			y.push_back(beginy);
		}
	}
	m_Position.push_back(x);
	m_Position.push_back(y);
	m_Length = Length;
}

int Wall::getColor() {
	return this->m_Color;
}

bool Wall::BeHit(Snake& s) {
	pair<int, int> sp = s.getPositon(0);
	for (int i = 0; i < this->m_Length; ++i) {
		pair<int, int> wp = this->getPositon(i);
		if (wp == sp) {
			return true;
		}
	}
	return false;
}

void Wall::DrawWallBody(int x,int y) {
	solidrectangle(x * CELL_SIZE + 1, y * CELL_SIZE + (CELL_SIZE)-1, x * CELL_SIZE + CELL_SIZE - 1, y * CELL_SIZE + 1); // »æÖÆÇ½Ìå
}

void Wall::Draw() {
	setfillcolor(this->m_Color);//Ç½ÑÕÉ«
	for (int i = 0; i < this->m_Length; ++i) {
		pair<int, int>p;
		p = this->getPositon(i);
		DrawWallBody(p.first, p.second);
	}
}



