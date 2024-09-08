#pragma once
using namespace std;
class Time {
private:
	double m_s;
	int m_min;
public:
	Time();
	double getSecond();
	int getMin();
	void TimeGrowth(double ds);//增长的秒数
	void Reset();
};