#include "Snake.h"
void Snake::DeleteBackNode() {
	m_Position[0].pop_back();
	m_Position[1].pop_back();
	--m_Length;
}

Snake::Snake(int Orientation, int Length, int beginx, int beginy) {
	m_Length = Length;
	deque<int>x;
	deque<int>y;
	if (Orientation == UP) {
		assert(beginy - Length >= 0);
		for (int i = Length - 1; i >= 0 ; --i) {
			x.push_back(beginx);
			y.push_back(beginy - i);
		}
	}
	else if (Orientation == DOWN) {
		assert(beginy + Length < ROW);
		for (int i = Length - 1; i >= 0; --i) {
			x.push_back(beginx);
			y.push_back(beginy + i);
		}
	}
	else if (Orientation == RIGHT) {
		assert(beginx + Length < COL);
		for (int i = Length-1; i >= 0; --i) {
			x.push_back(beginx + i);
			y.push_back(beginy);
		}
	}
	else if (Orientation == LEFT) {
		assert(beginx - Length >= 0);
		for (int i = Length - 1; i >= 0; --i) {
			x.push_back(beginx - i);
			y.push_back(beginy);
		}
	}
	m_Position.push_back(x);
	m_Position.push_back(y);
	m_Orientation = Orientation;
	m_PortFlag = false;
	m_LengthAddRemain = 0;
}

//void Snake::PrintPositon() {
//	deque<int>::const_iterator itx = m_Position[0].begin();
//	deque<int>::const_iterator ity = m_Position[1].begin();
//	for (;itx != m_Position[0].end() && ity != m_Position[1].end(); itx++, ity++)//遍历坐标	打印坐标
//		cout << *itx << "," << *ity << endl;
//}

void Snake::Move() {
	if (m_PortFlag == true) {
		AddNode(m_NextNode.first, m_NextNode.second);
		m_PortFlag = false;
	}
	else {
		switch (m_Orientation)
		{
		case UP:
			if (*(m_Position[1].begin()) == 0) {
				AddNode(*(m_Position[0].begin()), ROW - 1);
			}
			else {
				AddNode(*(m_Position[0].begin()), *(m_Position[1].begin()) - 1);
			}
			break;
		case DOWN:
			if (*(m_Position[1].begin()) == ROW - 1) {
				AddNode(*(m_Position[0].begin()), 0);
			}
			else {
				AddNode(*(m_Position[0].begin()), *(m_Position[1].begin()) + 1);
			}
			break;
		case LEFT:
			if (*(m_Position[0].begin()) == 0) {
				AddNode(COL - 1, *(m_Position[1].begin()));
			}
			else {
				AddNode(*(m_Position[0].begin()) - 1, *(m_Position[1].begin()));
			}
			break;
		case RIGHT:
			if (*(m_Position[0].begin()) == COL - 1) {
				AddNode(0, *(m_Position[1].begin()));
			}
			else {
				AddNode(*(m_Position[0].begin()) + 1, *(m_Position[1].begin()));
			}
			break;
		}
	}
	m_LastNode = this->getPositon(m_Length - 1);
	DeleteBackNode();
}

void Snake::ChangeOrientation(int orientation) {
	assert(orientation <= RIGHT && orientation >= UP);
	if (orientation == UP && this->m_Orientation != DOWN) {
		m_Orientation = UP;
	}
	else if (orientation == DOWN && this->m_Orientation != UP) {
		m_Orientation = DOWN;
	}
	else if (orientation == LEFT && this->m_Orientation != RIGHT) {
		m_Orientation = LEFT;
	}
	else if (orientation == RIGHT && this->m_Orientation != LEFT) {
		m_Orientation = RIGHT;
	}
}

//void Snake::ShowSnakeInMap() {
//	for (int i = 0; i < ROW; ++i) {
//		for (int j = 0; j < COL; ++j) {
//			if (SnakeOccupied(j, i)) {
//				cout << "#";
//			}
//			else {
//				cout << "-";
//			}
//		}
//		cout  << i << endl;
//	}
//}

bool Snake::SnakeOccupied(int x, int y) {
	deque<int>::const_iterator itx = m_Position[0].begin();
	deque<int>::const_iterator ity = m_Position[1].begin();
	for (; itx != m_Position[0].end() && ity != m_Position[1].end(); itx++, ity++) {
		if (x == *itx && y == *ity) {
			return true;
		}
	}
	return false;
}

void Snake::DrawSnakeBody(int x,int y) {
	fillcircle(x * CELL_SIZE + CELL_SIZE / 2, y * CELL_SIZE + CELL_SIZE / 2, Snake_Body_Size);
}

void Snake::Draw() {
	setfillcolor(MIDDLEPURPLE);	
	setlinestyle(0);
	setlinecolor(WHITE);
	for (int i = 0; i < m_Length; i++) {//遍历蛇身花圆
		pair<int, int>p;
		p = this->getPositon(i);
		DrawSnakeBody(p.first, p.second);
		if (!i) {
			setfillcolor(LIGHTPURPLE);
		}
	}
}

bool Snake::BeHit(Snake& s) {
	pair<int, int> sp = s.getPositon(0);
	for (int i = 1; i < this->m_Length; ++i) {
		pair<int, int> wp = this->getPositon(i);
		if (wp == sp) {
			return true;
		}
	}
	return false;
}

void Snake::AddLength(pair<int,int> p) {
	m_Position[0].push_back(p.first);
	m_Position[1].push_back(p.second);
	m_Length++;
}

int Snake::getLengthAddRemain() {
	return m_LengthAddRemain;
}

void Snake::setLengthAddRemain(int x) {
	assert(x >= 0);
	m_LengthAddRemain = x;
}

pair<int, int> Snake::getLastNode() {
	return m_LastNode;
}

void Snake::PortTo(pair<int,int>pos) {
	switch (m_Orientation)
	{
	case UP:
		pos.second--;
		m_NextNode = pos;
		break;
	case DOWN:
		pos.second++;
		m_NextNode = pos;
		break;
	case LEFT:
		pos.first--;
		m_NextNode = pos;
		break;
	case RIGHT:
		pos.first++;
		m_NextNode = pos;
		break;
	}
	m_PortFlag = true;
}