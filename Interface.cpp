#include "interface.h"
#include<Windows.h>

void Dispaly_level(int n);

void Text_rule() {
	settextstyle(0, 0, "");
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	int top = 40;
	char arr1[] = "^�����PLAY��������Ϸ��";
	outtextxy(60, top + 30, arr1);
	char arr2[] = "^ʹ�á�W������S������A������D�������ߵķ���˫��ģʽ";
	outtextxy(60, top + 30 + 30, arr2);
	char arr3[] = "�����2ʹ�á�I������K������J������L�����Ʒ��򣩡�";
	outtextxy(60, top + 30 + 30 + 30, arr3);
	char arr4[] = "^���ͨ��������ͷ�Ե���ʵ�������ߵĳ��ȣ�����ǽ�ڻ�����";
	outtextxy(60, top + 30 + 30 + 30 + 30, arr4);
	char arr5[] = "��������Ϸ��";
	outtextxy(60, top + 30 + 30 + 30 + 30 + 30, arr5);
	char arr6[] = "^���մ��ʱ��ͳ��Ⱦ�������÷֡�";
	outtextxy(60, top + 30 + 30 + 30 + 30 + 30 + 30, arr6);
	char arr7[] = "^��ҿ�ѡ����ǽ����ǽ����ģʽ����ǽģʽ��ǽ��Ϊ��Ч�˺���";
	outtextxy(60, top + 30 + 30 + 30 + 30 + 30 + 30 + 30, arr7);
	char arr8[] = "�����������Ϸ����ǽģʽ���ߴ�����Ե�ɴ���һ�߳��֡�";
	outtextxy(60, top + 30 + 30 + 30 + 30 + 30 + 30 + 30 + 30, arr8);
	char arr9[] = "^��Ϸ�����˴����ţ��߽����ɴ���ɫ��ͬ����һ���ų�����";
	outtextxy(60, top + 30 + 30 + 30 + 30 + 30 + 30 + 30 + 30 + 30, arr9);
	char arr10[] = "^��ҿ�ѡ���ƶ��ٶȣ�����R�����٣�����E���ָ��ٶȡ�";
	outtextxy(60, top + 30 + 30 + 30 + 30 + 30 + 30 + 30 + 30 + 30 + 30, arr10);
	char arr11[] = "^ף����Ϸ��죡��";
	outtextxy(60, top + 30 + 30 + 30 + 30 + 30 + 30 + 30 + 30 + 30 + 30 + 30, arr11);
	char arr_[] = "����...";
	outtextxy(570, 450, arr_);
}

void Text_return() {
	settextstyle(0, 0, "");
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	char arr_[] = "����...";
	outtextxy(570, 450, arr_);
}

void Text_rank() {
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	char arr__[] = "�鿴����...";
	outtextxy(10, 450, arr__);
}

void Text_tip() {
	settextstyle(0, 0, "");
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	char arr_[] = "��ѡ������Ҫ�鿴�����Ĺؿ�";
	outtextxy(20, 450, arr_);
}

struct STAR//������һ��star�ṹ��
{
	double	x;
	int		y;
	double	step;
	int		color;
};

STAR star[MAXSTAR];//һ���ṹ������

// ��ʼ������
void InitStar(int i) {
	star[i].x = 0;
	star[i].y = rand() % 480;//0-479
	star[i].step = (rand() % 5000) / 1000.0 + 1;//1-5�������
	star[i].color = (int)(star[i].step * 255 / 6.0 + 0.5);
	star[i].color = RGB(star[i].color, star[i].color, star[i].color);//���ƶ���������õ��� �ٶ�Խ�죬��ɫԽ��
}

// �ƶ�����
void MoveStar(int i)
{
	// ����ԭ��������
	putpixel((int)star[i].x, star[i].y, 0);//0Ϊ��ɫ����ʵ���˲������ǵ�Ч��

	// ������λ��
	star[i].x += star[i].step;//�Ӳ���
	if (star[i].x > 640)	InitStar(i);

	// ��������
	putpixel((int)star[i].x, star[i].y, star[i].color);//����λ�û�����
}

void get_bk() {
	IMAGE imgbk;
	loadimage(&imgbk, "./res/imgbk.png", 648, 486);
	putimage(0, 0, &imgbk);
}

void getImg() {
	IMAGE img;
	loadimage(&img, "./res/��ʼ.png", 160, 120);
	putimage(0, 0, &img);
}

void Rank(General& general) {
	IMAGE img_ranking;
	cout << "rank" << endl;
	get_bk();
	general.ShowInfo();
	settextstyle(0, 0, "");
	Text_return();
}

int choose_level(General& general) {
	int j = 0;
	int n = 0;
	while (j != 9) {
		MOUSEMSG msg;
		msg = GetMouseMsg();
		switch (msg.uMsg) {
		case WM_LBUTTONDOWN:
			if (msg.x >= 109 && msg.x <= 197 && msg.y >= 153 && msg.y <= 238) {
				Level_selection(1);
				n = 1;
				while (msg.uMsg != WM_LBUTTONUP) {
					msg = GetMouseMsg();
					if (msg.x >= 109 && msg.x <= 557 && msg.y >= 153 && msg.y <= 358) {
						j = 9;
					}
				}
			}
			if (msg.x >= 199 && msg.x <= 287 && msg.y >= 153 && msg.y <= 238) {
				Level_selection(2);
				n = 2;
				while (msg.uMsg != WM_LBUTTONUP) {
					msg = GetMouseMsg();
					if (msg.x >= 109 && msg.x <= 557 && msg.y >= 153 && msg.y <= 358) {
						j = 9;
					}
				}
			}
			if (msg.x >= 289 && msg.x <= 377 && msg.y >= 153 && msg.y <= 238) {
				Level_selection(3);
				n = 3;
				while (msg.uMsg != WM_LBUTTONUP) {
					msg = GetMouseMsg();
					if (msg.x >= 109 && msg.x <= 557 && msg.y >= 153 && msg.y <= 358) {
						j = 9;
					}
				}
			}
			if (msg.x >= 379 && msg.x <= 467 && msg.y >= 153 && msg.y <= 238) {
				Level_selection(4);
				n = 4;
				while (msg.uMsg != WM_LBUTTONUP) {
					msg = GetMouseMsg();
					if (msg.x >= 109 && msg.x <= 557 && msg.y >= 153 && msg.y <= 358) {
						j = 9;
					}
				}
			}
			if (msg.x >= 469 && msg.x <= 557 && msg.y >= 153 && msg.y <= 238) {
				Level_selection(5);
				n = 5;
				while (msg.uMsg != WM_LBUTTONUP) {
					msg = GetMouseMsg();
					if (msg.x >= 109 && msg.x <= 557 && msg.y >= 153 && msg.y <= 358) {
						j = 9;
					}
				}
			}
			if (msg.x >= 109 && msg.x <= 197 && msg.y >= 273 && msg.y <= 358) {
				Level_selection(6);
				n = 6;;
				while (msg.uMsg != WM_LBUTTONUP) {
					msg = GetMouseMsg();
					if (msg.x >= 109 && msg.x <= 557 && msg.y >= 153 && msg.y <= 358) {
						j = 9;
					}
				}
			}
			if (msg.x >= 199 && msg.x <= 287 && msg.y >= 273 && msg.y <= 358) {
				Level_selection(7);
				n = 7;
				while (msg.uMsg != WM_LBUTTONUP) {
					msg = GetMouseMsg();
					if (msg.x >= 109 && msg.x <= 557 && msg.y >= 153 && msg.y <= 358) {
						j = 9;
					}
				}
			}
			if (msg.x >= 289 && msg.x <= 377 && msg.y >= 273 && msg.y <= 358) {
				Level_selection(8);
				n = 8;
				while (msg.uMsg != WM_LBUTTONUP) {
					msg = GetMouseMsg();
					if (msg.x >= 109 && msg.x <= 557 && msg.y >= 153 && msg.y <= 358) {
						j = 9;
					}
				}
			}
			if (msg.x >= 379 && msg.x <= 467 && msg.y >= 273 && msg.y <= 358) {
				Level_selection(9);
				n = 9;
				while (msg.uMsg != WM_LBUTTONUP) {
					msg = GetMouseMsg();
					if (msg.x >= 109 && msg.x <= 557 && msg.y >= 153 && msg.y <= 358) {
						j = 9;
					}
				}
			}
			if (msg.x >= 469 && msg.x <= 557 && msg.y >= 273 && msg.y <= 358) {
				Level_selection(10);
				n = 10;
				while (msg.uMsg != WM_LBUTTONUP) {
					msg = GetMouseMsg();
					if (msg.x >= 109 && msg.x <= 557 && msg.y >= 153 && msg.y <= 358) {
						j = 9;
					}
				}
			}
			break;
		default:
			break;
		}
	}
	return n;
}

void chooseMode(General& general) {
	cleardevice();
	IMAGE img_one_P, img_two_P, img_mode_P;
	loadimage(&img_one_P, "./res/one.png", 420, 420);
	loadimage(&img_two_P, "./res/two.jpg", 420, 420);
	loadimage(&img_mode_P, "./res/mode_p.jpg", 420, 420);
	putimage(114, 33, &img_mode_P);
	MOUSEMSG msg;
	while (true) {
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 200 && msg.x <= 427 && msg.y >= 230 && msg.y <= 271) {
			putimage(114, 33, &img_one_P);
			getImg();
			general.setPlayerMode(SINGLE);
			Sleep(500);
			cleardevice();
			Level_display();
			int n = choose_level(general);
			Dispaly_level(n);
			general.level.SetLevel(n);
			break;
		}
		if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 200 && msg.x <= 480 && msg.y >= 307 && msg.y <= 343) {
			putimage(114, 33, &img_two_P);
			getImg();
			general.setPlayerMode(TWO_PLAYER);
			Sleep(500);
			cleardevice();
			Level_display();
			int n = choose_level(general);
			Dispaly_level(n);
			general.level.SetLevel(n);
			break;
		}
	}
}

void Start_over(General& general, string filename) {
	IMAGE img_over;
	loadimage(&img_over, "./res/img_over.png", 648, 486);
	chooseMode(general);
	closegraph();// �رջ�ͼ����
	Game(general);//��Ϸ��ʼ
	general.setSpeed(SLOW);//�ٶȸ�λ
	general.SortVgs();
	general.saveScores(filename);
	general.ShowInfo();
	initgraph(648, 486);//��Ϸ����
	putimage(0, 0, &img_over);
	Text_return();
	Text_rank();
}

void Level_display() {
	int d = 27;
	int s1 = 40;
	int s2 = 33;
	int s = s1 + 2 * d;
	int mid1 = 320 - 27;
	int mid2 = 240;
	IMAGE img_1_up, img_2_up, img_3_up, img_4_up, img_5_up, img_6_up, img_7_up, img_8_up, img_9_up, img_10_up;
	loadimage(&img_1_up, "./res/level_1_up.png", 90, 90);
	loadimage(&img_2_up, "./res/level_2_up.png", 90, 90);
	loadimage(&img_3_up, "./res/level_3_up.png", 90, 90);
	loadimage(&img_4_up, "./res/level_4_up.png", 90, 90);
	loadimage(&img_5_up, "./res/level_5_up.png", 90, 90);
	loadimage(&img_6_up, "./res/level_6_up.png", 90, 90);
	loadimage(&img_7_up, "./res/level_7_up.png", 90, 90);
	loadimage(&img_8_up, "./res/level_8_up.png", 90, 90);
	loadimage(&img_9_up, "./res/level_9_up.png", 90, 90);
	loadimage(&img_10_up, "./res/level_10_up.png", 90, 90);
	cleardevice();
	getImg();
	putimage(mid1 - 2 * s, mid2 - s2 - 2 * d, &img_1_up);
	putimage(mid1 - s, mid2 - s2 - 2 * d, &img_2_up);
	putimage(mid1, mid2 - s2 - 2 * d, &img_3_up);
	putimage(mid1 + s, mid2 - s2 - 2 * d, &img_4_up);
	putimage(mid1 + 2 * s, mid2 - s2 - 2 * d, &img_5_up);
	putimage(mid1 - 2 * s, mid2 + s2, &img_6_up);
	putimage(mid1 - s, mid2 + s2, &img_7_up);
	putimage(mid1, mid2 + s2, &img_8_up);
	putimage(mid1 + s, mid2 + s2, &img_9_up);
	putimage(mid1 + 2 * s, mid2 + s2, &img_10_up);
}

void Dispaly_level(int n) {
	IMAGE level_1, level_2, level_3, level_4, level_5, level_6, level_7, level_8, level_9, level_10;
	loadimage(&level_1, "./res/level1.png", 400, 150);
	loadimage(&level_2, "./res/level2.png", 400, 150);
	loadimage(&level_3, "./res/level3.png", 400, 150);
	loadimage(&level_4, "./res/level4.png", 400, 150);
	loadimage(&level_5, "./res/level5.png", 400, 150);
	loadimage(&level_6, "./res/level6.png", 400, 150);
	loadimage(&level_7, "./res/level7.png", 400, 150);
	loadimage(&level_8, "./res/level8.png", 400, 150);
	loadimage(&level_9, "./res/level9.png", 400, 150);
	loadimage(&level_10, "./res/level10.png", 400, 150);
	switch (n) {
	case 1:
		putimage(130, 168, &level_1);
		Sleep(2000);
		break;
	case 2:
		putimage(130, 168, &level_2);
		Sleep(2000);
		break;
	case 3:
		putimage(130, 168, &level_3);
		Sleep(2000);
		break;
	case 4:
		putimage(130, 168, &level_4);
		Sleep(2000);
		break;
	case 5:
		putimage(130, 168, &level_5);
		Sleep(2000);
		break;
	case 6:
		putimage(130, 168, &level_6);
		Sleep(2000);
		break;
	case 7:
		putimage(130, 168, &level_7);
		Sleep(2000);
		break;
	case 8:
		putimage(130, 168, &level_8);
		Sleep(2000);
		break;
	case 9:
		putimage(130, 168, &level_9);
		Sleep(2000);
		break;
	case 10:
		putimage(130, 168, &level_10);
		Sleep(2000);
	default:
		break;
	}
}

void Level_selection(int n) {
	IMAGE img_1_down, img_2_down, img_3_down, img_4_down, img_5_down, img_6_down, img_7_down, img_8_down, img_9_down, img_10_down;
	int d = 27;
	int s1 = 40;
	int s2 = 33;
	int s = s1 + 2 * d;
	int mid1 = 320 - 27;
	int mid2 = 240;
	loadimage(&img_1_down, "./res/level_1_down.png", 90, 90);
	loadimage(&img_2_down, "./res/level_2_down.png", 90, 90);
	loadimage(&img_3_down, "./res/level_3_down.png", 90, 90);
	loadimage(&img_4_down, "./res/level_4_down.png", 90, 90);
	loadimage(&img_5_down, "./res/level_5_down.png", 90, 90);
	loadimage(&img_6_down, "./res/level_6_down.png", 90, 90);
	loadimage(&img_7_down, "./res/level_7_down.png", 90, 90);
	loadimage(&img_8_down, "./res/level_8_down.png", 90, 90);
	loadimage(&img_9_down, "./res/level_9_down.png", 90, 90);
	loadimage(&img_10_down, "./res/level_10_down.png", 90, 90);
	switch (n) {
	case 1:
		putimage(mid1 - 2 * s, mid2 - s2 - 2 * d, &img_1_down);
		Sleep(200);
		cleardevice();
		break;
	case 2:
		putimage(mid1 - s, mid2 - s2 - 2 * d, &img_2_down);
		Sleep(200);
		cleardevice();
		break;
	case 3:
		putimage(mid1, mid2 - s2 - 2 * d, &img_3_down);
		Sleep(200);
		cleardevice();
		break;
	case 4:
		putimage(mid1 + s, mid2 - s2 - 2 * d, &img_4_down);
		Sleep(200);
		cleardevice();
		break;
	case 5:
		putimage(mid1 + 2 * s, mid2 - s2 - 2 * d, &img_5_down);
		Sleep(200);
		cleardevice();
		break;
	case 6:
		putimage(mid1 - 2 * s, mid2 + s2, &img_6_down);
		Sleep(200);
		cleardevice();
		break;
	case 7:
		putimage(mid1 - s, mid2 + s2, &img_7_down);
		Sleep(200);
		cleardevice();
		break;
	case 8:
		putimage(mid1, mid2 + s2, &img_8_down);
		Sleep(200);
		cleardevice();
		break;
	case 9:
		putimage(mid1 + s, mid2 + s2, &img_9_down);
		Sleep(200);
		cleardevice();
		break;
	case 10:
		putimage(mid1 + 2 * s, mid2 + s2, &img_10_down);
		Sleep(200);
		cleardevice();
	default:
		break;
	}
}

void Interface() {
	string filename = "snake_scores.txt";
	General general;//������Ϸ ����

	general.loadScores(filename);//��ȡ����

	initgraph(648, 486);			// ������ͼ����
	IMAGE img_whole, img_start, img_rule, img_mode, img_choose, img_single_wall, img_single_noWall, img_double_wall, img_double_noWall, img_ranking, imgbk, img_over, img, img_level_2_up, img_button2;
	loadimage(&img_whole, "./res/����.png", 648, 486);
	loadimage(&img_start, "./res/��ʼ��Ϸ.png", 648, 486);
	loadimage(&img_rule, "./res/��Ϸ����.png", 648, 486);
	loadimage(&img_mode, "./res/ģʽ.png", 648, 486);
	loadimage(&img_single_wall, "./res/single_wall.jpg", 648, 486);
	loadimage(&img_single_noWall, "./res/single_nowall.jpg", 648, 486);
	loadimage(&img_double_wall, "./res/double_wall.jpg", 648, 486);
	loadimage(&img_double_noWall, "./res/double_nowall.jpg", 648, 486);
	loadimage(&img_ranking, "./res/ranking.png", 648, 486);
	loadimage(&imgbk, "./res/imgbk.png", 648, 486);
	loadimage(&img_over, "./res/img_over.png", 648, 486);
	loadimage(&img, "./res/��ʼ.png", 160, 120);//108 81 
	loadimage(&img_level_2_up, "./res/level_2_up.png", 108, 93);
Start:
	putimage(0, 0, &img_whole); // ���á���ʼ��Ϸ��ͼ��
	MOUSEMSG msg;
	while (true)
	{
		msg = GetMouseMsg();//ͨ�� GetMouseMsg ��ȡ�����Ϣ�������������λ�õĲ�ͬ��ִ����Ӧ�Ĳ�����
		switch (msg.uMsg) {
		case WM_LBUTTONDOWN:
			if (msg.x >= 250 && msg.x <= 397 && msg.y >= 406 && msg.y <= 455) {
				putimage(0, 0, &img_start);//��ʼͼ�갴��״̬
			}
			if (msg.x >= 433 && msg.x <= 482 && msg.y >= 406 && msg.y <= 455) {
				putimage(0, 0, &img_rule);//��Ϸ����ͼ�갴��
			}
			if (msg.x >= 174 && msg.x <= 215 && msg.y >= 406 && msg.y <= 455) {
				putimage(0, 0, &img_mode);//��Ϸģʽͼ�갴��
			}
			break;
		case WM_LBUTTONUP:
			if (msg.x >= 250 && msg.x <= 397 && msg.y >= 406 && msg.y <= 455) {//��ʼ��Ϸ
				Start_over(general, filename);
				while (true) {
					msg = GetMouseMsg();
					if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 570 && msg.x <= 648 && msg.y >= 446 && msg.y <= 472) {//����
						goto Start;
					}
					if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 0 && msg.x <= 100 && msg.y >= 446 && msg.y <= 472) {//����
						Rank(general);
						while (true) {
							msg = GetMouseMsg();
							if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 570 && msg.x <= 648 && msg.y >= 446 && msg.y <= 472) {//����
								goto Start;
							}
						}
					}
				}
			}
			if (msg.x >= 433 && msg.x <= 482 && msg.y >= 406 && msg.y <= 455) {
				cleardevice();
				//��ʼ����������
				for (int i = 0; i < MAXSTAR; i++)
				{
					InitStar(i);
					star[i].x = rand() % 640;
				}
				// �����ǿգ���������˳�
				while (!_kbhit())
				{
					for (int i = 0; i < MAXSTAR; i++)
						MoveStar(i);
					Text_rule();
					Sleep(20);
					msg = GetMouseMsg();
					if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 570 && msg.x <= 648 && msg.y >= 446 && msg.y <= 472) {
						goto Start;//�ص���ʼ����
					}
				}
			}
			if (msg.x >= 174 && msg.x <= 215 && msg.y >= 406 && msg.y <= 455) {//ѡ��
				/*	if (general.getWallMode() == WALL) {
						if (general.getPlayerMode()==SINGLE)
							putimage(0, 0, &img_single_wall);
						else
							putimage(0, 0, &img_double_wall);
					}
					else {
						if (general.getPlayerMode() == SINGLE)
							putimage(0, 0, &img_single_noWall);
						else
							putimage(0, 0, &img_double_noWall);
					}
					Text_return();*/
				Level_display();
				Text_tip();
				Text_return();
				choose_level(general);
			}
			break;
		default:
			break;
		}
	}
	getchar();
	closegraph();// �رջ�ͼ����
}
