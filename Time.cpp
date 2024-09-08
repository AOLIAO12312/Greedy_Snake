#include"Time.h"
Time::Time():m_s(0),m_min(0){}//无参初始化

int Time::getMin() {
	return m_min;
}

double Time::getSecond() {
	return m_s;
}

void Time::TimeGrowth(double ds) {
	m_s += ds;
	if (m_s >= 60) {
		m_s = 0;
		++m_min;
	}
}

void Time::Reset() {
	m_min = 0;
	m_s = 0;
}