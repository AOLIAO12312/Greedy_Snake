#include"game.h"

void DetectPressTwo(vector<Snake*>& v_Snake,General& general) {
	if (_kbhit()) {
		switch (_getch()) {
		case 'A':
		case 'a':
			v_Snake[0]->ChangeOrientation(LEFT);
			break;
		case 'S':
		case 's':
			v_Snake[0]->ChangeOrientation(DOWN);
			break;
		case 'D':
		case 'd':
			v_Snake[0]->ChangeOrientation(RIGHT);
			break;
		case 'W':
		case 'w':
			v_Snake[0]->ChangeOrientation(UP);
			break;
		case 'J':
		case 'j':
			v_Snake[1]->ChangeOrientation(LEFT);
			break;
		case 'K':
		case 'k':
			v_Snake[1]->ChangeOrientation(DOWN);
			break;
		case 'L':
		case 'l':
			v_Snake[1]->ChangeOrientation(RIGHT);
			break;
		case 'I':
		case 'i':
			v_Snake[1]->ChangeOrientation(UP);
			break;
		case 'R':
		case 'r':
			general.setSpeed(FAST);
			break;
		case 'E':
		case 'e':
			general.setSpeed(SLOW);
			break;
		case 27:
			general.setSpeed(PAUSE);
		default:
			break;
		}
	}
}
void DetectPressSingle(vector<Snake*>& v_Snake, General& general) {
	if (_kbhit()) {
		switch (_getch()) {
		case 'A':
		case 'a':
			v_Snake[0]->ChangeOrientation(LEFT);
			break;
		case 'S':
		case 's':
			v_Snake[0]->ChangeOrientation(DOWN);
			break;
		case 'D':
		case 'd':
			v_Snake[0]->ChangeOrientation(RIGHT);
			break;
		case 'W':
		case 'w':
			v_Snake[0]->ChangeOrientation(UP);
			break;
		case 'R':
		case 'r':
			general.setSpeed(FAST);
			break;
		case 'E':
		case 'e':
			general.setSpeed(SLOW);
		case 27:
			general.setSpeed(PAUSE);
		default:
			break;
		}
	}
}

bool JudgeSnakeAndWall(const vector<Snake*>& v_Snake, const vector<Wall*>& v_Wall) {
	for (vector<Snake*>::const_iterator sit = v_Snake.begin(); sit != v_Snake.end(); ++sit) {
		for (vector<Wall*>::const_iterator wit = v_Wall.begin(); wit != v_Wall.end(); ++wit) {
			if ((*wit)->BeHit(**sit)) {
				return true;
			}
		}
	}
	return false;
}//����ߺ�ǽ�Ƿ���ײ

bool VerifyPosValidity(vector<Snake*>& v_Snake, vector<Food*>& v_Food, vector<Wall*>& v_Wall,pair<int,int>p) {
	for (vector<Snake*>::iterator sit = v_Snake.begin(); sit != v_Snake.end(); ++sit) {
		if ((*sit)->Occupied(p)) {
			return true;
		}
	}
	for (vector<Food*>::iterator fit = v_Food.begin(); fit != v_Food.end(); ++fit) {
		if ((*fit)->Occupied(p)) {
			return true;
		}
	}
	for (vector<Wall*>::const_iterator wit = v_Wall.begin(); wit != v_Wall.end(); ++wit) {
		if ((*wit)->Occupied(p)) {
			return true;
		}
	}
	return false;
}//��֤�������λ��p����Ч��	�����������ʳ��

void JudgeSnakeAndFood(vector<Snake*>& v_Snake, vector<Food*>& v_Food, vector<Wall*>& v_Wall) {
	Rejudge:
	for (vector<Snake*>::iterator sit = v_Snake.begin(); sit != v_Snake.end(); ++sit) {
		for (vector<Food*>::iterator fit = v_Food.begin(); fit != v_Food.end();) {
			if ((*fit)->BeHit(**sit)) {
				switch ((*fit)->getSize()) {
				case SMALL:
					(*sit)->setLengthAddRemain(2);
					break;
				case MIDDLE:
					(*sit)->setLengthAddRemain(4);
					break;
				case BIG:
					(*sit)->setLengthAddRemain(6);
					break;//ͨ��food�Ĵ�С��������
				default:
					break;
				}
				delete(*fit);//ɾ����ʳ��Ԫ��
				v_Food.erase(fit);//�Ե�֮��ֱ��ָ����һ������������ֹδ֪����
				pair<int, int> p;
				do {
					p = pair<int, int>(rand() % COL, rand() % ROW);
				} while (VerifyPosValidity(v_Snake, v_Food, v_Wall, p));
				Food* food = new Food(BIG, FOOD_COLOR, p.first, p.second);
				v_Food.push_back(food);
				goto Rejudge;
			}
			else {
				++fit;//û�гԵ���ʱ��ֱ������
			}
		}
	}
}

void DetermineFood(vector<Food*>& v_Food) {
	for (vector<Food*>::iterator fit = v_Food.begin(); fit != v_Food.end();++fit) {
		if ((*fit)->getStatus() == SHOW) {
			(*fit)->Draw();
		}
		else if ((*fit)->getStatus() == HIDE) {
			if (rand() % 100 <= 5) {//ͨ�������������food���ֵ�ʱ��
				(*fit)->setStatus(SHOW);
			}
		}
	}
}//�趨��food֮��	ȷ��food���ֵ�ʱ��

bool JudgeSnakeAndSnake(vector<Snake*>& v_Snake) {
	for (vector<Snake*>::const_iterator sit1 = v_Snake.begin(); sit1 != v_Snake.end(); ++sit1) {
		for (vector<Snake*>::const_iterator sit2 = v_Snake.begin(); sit2 != v_Snake.end(); ++sit2) {
			if ((*sit2)->BeHit(**sit1)) {
				return true;
			}
		}
	}
	return false;
}

void DrawAllContent(vector<Snake*>& v_Snake, vector<Food*>& v_Food, vector<Wall*>& v_Wall, vector<pair<PortGate*, PortGate*>>& v_PortGate) {
	for (vector<Snake*>::iterator sit = v_Snake.begin(); sit != v_Snake.end(); ++sit) {
		(*sit)->Draw();
	}
	for (vector<Wall*>::iterator wit = v_Wall.begin(); wit != v_Wall.end(); ++wit) {
		(*wit)->Draw();
	}
	for (vector<pair<PortGate*, PortGate*>>::iterator pit = v_PortGate.begin(); pit != v_PortGate.end(); ++pit) {
		pit->first->Draw();
		pit->second->Draw();
	}
	DetermineFood(v_Food);
}

void MoveAndAdd(vector<Snake*>& v_Snake) {
	for (vector<Snake*>::const_iterator sit = v_Snake.begin(); sit != v_Snake.end(); ++sit) {
		(*sit)->Move();
		if ((*sit)->getLengthAddRemain() > 0) {
			(*sit)->AddLength((*sit)->getLastNode());//����ϴ����ɾ���Ľڵ㣨�������ȣ�
			(*sit)->setLengthAddRemain((*sit)->getLengthAddRemain() - 1);
		}
	}
}

void JudgeSnakeAndPortGate(vector<Snake*>& v_Snake,vector<pair<PortGate*, PortGate*>>& v_PortGate) {
	for (vector<Snake*>::iterator sit = v_Snake.begin(); sit != v_Snake.end(); ++sit) {
		for (vector<pair<PortGate*, PortGate*>>::iterator pit = v_PortGate.begin(); pit != v_PortGate.end(); ++pit) {
			if (pit->first->BeHit(**sit)) {
				(*sit)->PortTo(pit->second->getPositon(0));
				//����һ�������ų��֣�snake������
			}else if (pit->second->BeHit(**sit)) {
				(*sit)->PortTo(pit->first->getPositon(0));
			}
		}
	}
}//����ߺ�ǽ�Ƿ���ײ

void FreeMemo(vector<Snake*>& v_Snake, vector<Food*>& v_Food, vector<Wall*>& v_Wall, vector<pair<PortGate*, PortGate*>>& v_PortGate) {
	for (vector<Snake*>::iterator sit = v_Snake.begin(); sit != v_Snake.end(); ++sit) {
		delete (*sit);
	}
	for (vector<Wall*>::iterator wit = v_Wall.begin(); wit != v_Wall.end(); ++wit) {
		delete (*wit);
	}
	for (vector<pair<PortGate*, PortGate*>>::iterator pit = v_PortGate.begin(); pit != v_PortGate.end(); ++pit) {
		delete pit->first;
		delete pit->second;
	}
}

void Game(General& general) {
	IMAGE img;
	loadimage(&img, "./res/imgbk.png", 800, 600);

	vector<Snake*> v_Snake;
	vector<Wall*> v_Wall;
	vector<Food*> v_Food;
	vector<pair<PortGate*, PortGate*>> v_PortGate;

	general.level.LoadLevel(v_Snake, v_Food, v_Wall, v_PortGate);//���عؿ�����
	if (general.getPlayerMode() == TWO_PLAYER) {
		Snake* snake = new Snake(UP, 5, 9, 10);
		v_Snake.push_back(snake);
	}

	initgraph(800, 600, 1);//���ڴ�С
	setbkcolor(M_BLACK);//��Ϸ����ɫ
	double time = 0;
	while (true) {
		if (JudgeSnakeAndWall(v_Snake,v_Wall)) {
			break;
		}
		if (JudgeSnakeAndSnake(v_Snake)) {
			break;
		}
		JudgeSnakeAndFood(v_Snake, v_Food, v_Wall);
		JudgeSnakeAndPortGate(v_Snake, v_PortGate);
		general.TimeControl();
		if (general.getPlayerMode() == SINGLE)
			DetectPressSingle(v_Snake,general);
		else
			DetectPressTwo(v_Snake,general);
		MoveAndAdd(v_Snake);
		cleardevice();//������
		putimage(0, 0, &img);//������ͼ
		DrawAllContent(v_Snake, v_Food, v_Wall,v_PortGate);
	}
	FreeMemo(v_Snake, v_Food, v_Wall, v_PortGate);//�ͷ��ڴ�
	cout << "��Ϸ����" << endl;
	general.m_time.Reset();
	general.level.LevelUp();
	general.AddGameScore((int)time, v_Snake[0]->getLength());
	closegraph();
}