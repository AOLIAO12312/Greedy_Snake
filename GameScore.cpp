#include"GameScore.h"

GameScore::GameScore(int t, int l) : time(t), length(l) {
    score = time * 10 + length * 20;
}

GameScore::GameScore(){}

bool GameScore::operator<(const GameScore& other) const {
    return score > other.score; // Ωµ–Ú≈≈–Ú
}

void GameScore::CalculateScore(int t, int l) {
    score = time * 10 + length * 20;
    time = t;
    length = l;
}
