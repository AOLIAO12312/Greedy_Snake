#include "interface.h"
#include<Windows.h>

void Dispaly_level(int n);

void Text_rule() {
	settextstyle(0, 0, "");
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	int top = 40;
	char arr1[] = "^点击“PLAY”进入游戏。";
	outtextxy(60, top + 30, arr1);
	char arr2[] = "^使用“W”，“S”，“A”，“D”控制蛇的方向（双人模式";
	outtextxy(60, top + 30 + 30, arr2);
	char arr3[] = "下玩家2使用“I”，“K”，“J”，“L”控制方向）。";
	outtextxy(60, top + 30 + 30 + 30, arr3);
	char arr4[] = "^玩家通过控制蛇头吃到果实会增加蛇的长度，碰到墙壁或蛇身";
	outtextxy(60, top + 30 + 30 + 30 + 30, arr4);
	char arr5[] = "则会结束游戏。";
	outtextxy(60, top + 30 + 30 + 30 + 30 + 30, arr5);
	char arr6[] = "^最终存活时间和长度均将计入得分。";
	outtextxy(60, top + 30 + 30 + 30 + 30 + 30 + 30, arr6);
	char arr7[] = "^玩家可选择有墙和无墙两种模式。有墙模式下墙视为有效伤害，";
	outtextxy(60, top + 30 + 30 + 30 + 30 + 30 + 30 + 30, arr7);
	char arr8[] = "触碰则结束游戏；无墙模式下蛇穿过边缘可从另一边出现。";
	outtextxy(60, top + 30 + 30 + 30 + 30 + 30 + 30 + 30 + 30, arr8);
	char arr9[] = "^游戏设置了传送门，蛇进入后可从颜色相同的另一个门出来。";
	outtextxy(60, top + 30 + 30 + 30 + 30 + 30 + 30 + 30 + 30 + 30, arr9);
	char arr10[] = "^玩家可选择移动速度：按“R”加速，按“E”恢复速度。";
	outtextxy(60, top + 30 + 30 + 30 + 30 + 30 + 30 + 30 + 30 + 30 + 30, arr10);
	char arr11[] = "^祝您游戏愉快！！";
	outtextxy(60, top + 30 + 30 + 30 + 30 + 30 + 30 + 30 + 30 + 30 + 30 + 30, arr11);
	char arr_[] = "返回...";
	outtextxy(570, 450, arr_);
}

void Text_return() {
	settextstyle(0, 0, "");
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	char arr_[] = "返回...";
	outtextxy(570, 450, arr_);
}

void Text_rank() {
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	char arr__[] = "查看排名...";
	outtextxy(10, 450, arr__);
}

void Text_tip() {
	settextstyle(0, 0, "");
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	char arr_[] = "请选择你想要查看排名的关卡";
	outtextxy(20, 450, arr_);
}

struct STAR//定义了一个star结构体
{
	double	x;
	int		y;
	double	step;
	int		color;
};

STAR star[MAXSTAR];//一个结构体数组

// 初始化星星
void InitStar(int i) {
	star[i].x = 0;
	star[i].y = rand() % 480;//0-479
	star[i].step = (rand() % 5000) / 1000.0 + 1;//1-5的随机数
	star[i].color = (int)(star[i].step * 255 / 6.0 + 0.5);
	star[i].color = RGB(star[i].color, star[i].color, star[i].color);//由移动步长计算得到， 速度越快，颜色越亮
}

// 移动星星
void MoveStar(int i)
{
	// 擦掉原来的星星
	putpixel((int)star[i].x, star[i].y, 0);//0为黑色，就实现了擦除星星的效果

	// 计算新位置
	star[i].x += star[i].step;//加步长
	if (star[i].x > 640)	InitStar(i);

	// 画新星星
	putpixel((int)star[i].x, star[i].y, star[i].color);//在新位置画星星
}

void get_bk() {
	IMAGE imgbk;
	loadimage(&imgbk, "./res/imgbk.png", 648, 486);
	putimage(0, 0, &imgbk);
}

void getImg() {
	IMAGE img;
	loadimage(&img, "./res/开始.png", 160, 120);
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
	closegraph();// 关闭绘图窗口
	Game(general);//游戏开始
	general.setSpeed(SLOW);//速度复位
	general.SortVgs();
	general.saveScores(filename);
	general.ShowInfo();
	initgraph(648, 486);//游戏结束
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
	General general;//总体游戏 设置

	general.loadScores(filename);//读取数据

	initgraph(648, 486);			// 创建绘图窗口
	IMAGE img_whole, img_start, img_rule, img_mode, img_choose, img_single_wall, img_single_noWall, img_double_wall, img_double_noWall, img_ranking, imgbk, img_over, img, img_level_2_up, img_button2;
	loadimage(&img_whole, "./res/总体.png", 648, 486);
	loadimage(&img_start, "./res/开始游戏.png", 648, 486);
	loadimage(&img_rule, "./res/游戏规则.png", 648, 486);
	loadimage(&img_mode, "./res/模式.png", 648, 486);
	loadimage(&img_single_wall, "./res/single_wall.jpg", 648, 486);
	loadimage(&img_single_noWall, "./res/single_nowall.jpg", 648, 486);
	loadimage(&img_double_wall, "./res/double_wall.jpg", 648, 486);
	loadimage(&img_double_noWall, "./res/double_nowall.jpg", 648, 486);
	loadimage(&img_ranking, "./res/ranking.png", 648, 486);
	loadimage(&imgbk, "./res/imgbk.png", 648, 486);
	loadimage(&img_over, "./res/img_over.png", 648, 486);
	loadimage(&img, "./res/开始.png", 160, 120);//108 81 
	loadimage(&img_level_2_up, "./res/level_2_up.png", 108, 93);
Start:
	putimage(0, 0, &img_whole); // 放置“开始游戏”图标
	MOUSEMSG msg;
	while (true)
	{
		msg = GetMouseMsg();//通过 GetMouseMsg 获取鼠标消息，并根据鼠标点击位置的不同，执行相应的操作。
		switch (msg.uMsg) {
		case WM_LBUTTONDOWN:
			if (msg.x >= 250 && msg.x <= 397 && msg.y >= 406 && msg.y <= 455) {
				putimage(0, 0, &img_start);//开始图标按下状态
			}
			if (msg.x >= 433 && msg.x <= 482 && msg.y >= 406 && msg.y <= 455) {
				putimage(0, 0, &img_rule);//游戏规则图标按下
			}
			if (msg.x >= 174 && msg.x <= 215 && msg.y >= 406 && msg.y <= 455) {
				putimage(0, 0, &img_mode);//游戏模式图标按下
			}
			break;
		case WM_LBUTTONUP:
			if (msg.x >= 250 && msg.x <= 397 && msg.y >= 406 && msg.y <= 455) {//开始游戏
				Start_over(general, filename);
				while (true) {
					msg = GetMouseMsg();
					if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 570 && msg.x <= 648 && msg.y >= 446 && msg.y <= 472) {//返回
						goto Start;
					}
					if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 0 && msg.x <= 100 && msg.y >= 446 && msg.y <= 472) {//排名
						Rank(general);
						while (true) {
							msg = GetMouseMsg();
							if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 570 && msg.x <= 648 && msg.y >= 446 && msg.y <= 472) {//返回
								goto Start;
							}
						}
					}
				}
			}
			if (msg.x >= 433 && msg.x <= 482 && msg.y >= 406 && msg.y <= 455) {
				cleardevice();
				//初始化所有星星
				for (int i = 0; i < MAXSTAR; i++)
				{
					InitStar(i);
					star[i].x = rand() % 640;
				}
				// 绘制星空，按任意键退出
				while (!_kbhit())
				{
					for (int i = 0; i < MAXSTAR; i++)
						MoveStar(i);
					Text_rule();
					Sleep(20);
					msg = GetMouseMsg();
					if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 570 && msg.x <= 648 && msg.y >= 446 && msg.y <= 472) {
						goto Start;//回到开始界面
					}
				}
			}
			if (msg.x >= 174 && msg.x <= 215 && msg.y >= 406 && msg.y <= 455) {//选择
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
	closegraph();// 关闭绘图窗口
}
