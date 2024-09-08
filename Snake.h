#pragma once
#include"Object.h"
using namespace std;
class Snake : public Object{
public:
	Snake(int Orientation, int Length, int beginx, int beginy);
	void Move();//�ƶ�һ����λ
	void ChangeOrientation(int orientation);//�ı���ǰ������
	bool SnakeOccupied(int x, int y);//����xy���꣬�жϸ������Ƿ�����ռ�ã����򷵻�true�����򷵻�false
	void Draw();
	static void DrawSnakeBody(int x, int y);
	bool BeHit(Snake& s);//���������ͷײ�Ϸ���true	���򷵻�false
	void AddLength(pair<int,int> p);
	int getLengthAddRemain();
	void setLengthAddRemain(int x);
	pair<int, int> getLastNode();
	void PortTo(pair<int, int>pos);
	//void ShowSnakeInMap();//�Ե�ͼ����ʽ��ӡ���ߵ�λ��
	//void PrintPositon();//��������ʽ��ӡ�ߵ�λ��
private:
	void DeleteBackNode();//ɾ���ߵ����һ���ڵ�
	int m_Orientation;//����
	int m_LengthAddRemain;//
	pair<int, int>m_NextNode;//���ڴ�����
	pair<int, int> m_LastNode;//
	bool m_PortFlag;
};