#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class GameScore {
public:
    int time;
    int length;
    int score;
    GameScore();
    GameScore(int t, int l);
    void CalculateScore(int t, int l);
    bool operator<(const GameScore& other) const;
};