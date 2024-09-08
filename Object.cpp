#include"Object.h"
void Object::AddNode(int x, int y) {//一个x对应一个y
	assert(x >= 0 && x < COL);
	assert(y >= 0 && y < ROW);
	m_Position[0].push_front(x);
	m_Position[1].push_front(y);
	++m_Length;
}

pair<int, int> Object::getPositon(int Seq) {
	assert(Seq < m_Length);
	return pair<int, int>(m_Position[0][Seq], m_Position[1][Seq]);
}

int Object::getLength() {
	return this->m_Length;
}

bool Object::Occupied(pair<int,int>p) {
	for (int i = 0; i < this->getLength(); ++i) {
		if (p == this->getPositon(i)) {
			return true;
		}
	}
	return false;
}

