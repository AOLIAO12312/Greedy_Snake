#pragma once
#include <graphics.h>
#include <time.h>
#include <conio.h>
#include<stdio.h>
#include"game.h"
#include"General.h"
#define MAXSTAR 200	// ÐÇÐÇ×ÜÊý
void Interface();
void Text_rule();
void Text_return();
void Text_rank();
void InitStar(int i);
void MoveStar(int i);
void get_bk();
void Rank(General& general);
void Level_selection(int n);
void Level_display();
int choose_level(General& general);