#include"General.h"
#include <string>
#include <graphics.h>
General::General() {
    m_PlayerMode = SINGLE;
    m_WallMode = NO_WALL;
    m_Speed = SLOW;
}

int General::getPlayerMode() {
    return m_PlayerMode;
}

void General::setPlayerMode(int Mode) {
    assert(Mode == SINGLE || Mode == TWO_PLAYER);
    m_PlayerMode = Mode;
}

int General::getWallMode() {
    return m_WallMode;
}

void General::setWallMode(int Mode) {
    assert(Mode == WALL || Mode == NO_WALL);
    m_WallMode = Mode;
}

void General::loadScores(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        int time, length;
        while (file >> time >> length) {
            vgs.push_back(GameScore(time, length));
        }
        file.close();
    }
    else {
        cerr << "无法打开文件 " << filename << " 进行读取\n";
    }
}

void General::saveScores(const std::string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& score : vgs) {
            file << score.time << " " << score.length << "\n";
        }
        file.close();
    }
    else {
        cerr << "无法打开文件 " << filename << " 进行写入\n";
    }
}

void General::SortVgs() {
    sort(vgs.begin(), vgs.end());
}

void General::AddGameScore(int time, int length) {
    GameScore score(time, length);
    vgs.push_back(score);
}

void General::ShowInfo() {
    setbkmode(TRANSPARENT);
    settextcolor(WHITE);
    settextstyle(26, 0, "");
    char arr_biaoti[] = "排名   生存时间    长度    分数";
    outtextxy(100, 45, arr_biaoti);
    int maxRankWidth = 7; // 
    int maxTimeWidth = 9; // 
    int maxLengthWidth = 6; // 
    int maxScoreWidth = 2; // 
    //// 在窗口上显示信息标题

    for (size_t i = 0; i < vgs.size(); ++i) {
        char buffer[50]; // 用于存储转换后的字符串

        // 格式化General信息为字符串
        sprintf_s(buffer, "%-*d %-*d %-*d %-*d", maxRankWidth, i + 1, maxTimeWidth, vgs[i].time, maxLengthWidth, vgs[i].length, maxScoreWidth, vgs[i].score);

        // 在窗口上显示General信息，并设置对齐方式为左对齐
        outtextxy(120, 90 + i * 40, buffer);
    }
    ////// 在窗口上显示每个General的信息
    //for (size_t i = 0; i < vgs.size(); ++i) {
    //    char buffer[50]; // 用于存储转换后的字符串

    //    // 格式化General信息为字符串
    //    sprintf_s(buffer, "%d           %d           %d       %d", i + 1, vgs[i].time, vgs[i].length, vgs[i].score);
    //    // 在窗口上显示General信息
    //    outtextxy(120, 120 + i * 40, buffer);
    //    //}
}

void General::setSpeed(int speed) {
    m_Speed = speed;
}

int General::getSpeed() {
    return m_Speed;
}



void loadData(std::vector<User>& v_User, std::vector<Score>& v_Score) {
    // 查询 users 表
    MYSQL* connection = mysql_init(nullptr); // 初始化 MySQL 连接
    MYSQL_RES* res;
    if (mysql_query(connection, "SELECT * FROM users")) {
        fprintf(stderr, "Error querying users table: %s\n", mysql_error(connection));
        return;
    }

    MYSQL_RES* result = mysql_store_result(connection);
    if (!result) {
        fprintf(stderr, "Error storing users query result: %s\n", mysql_error(connection));
        return;
    }

    int num_fields = mysql_num_fields(result);

    // 逐行读取查询结果并添加到 v_User 中
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        User user;
        user.ID(row[0]);   // 假设 user_id 是第一个列
        user.Name(row[1]);  // 假设 username 是第二个列
        user.Password(row[2]);  // 假设 password 是第三个列
        v_User.push_back(user);
    }

    mysql_free_result(result);

    // 查询 scores 表
    if (mysql_query(connection, "SELECT * FROM scores")) {
        fprintf(stderr, "Error querying scores table: %s\n", mysql_error(connection));
        return;
    }

    result = mysql_store_result(connection);
    if (!result) {
        fprintf(stderr, "Error storing scores query result: %s\n", mysql_error(connection));
        return;
    }

    // 逐行读取查询结果并添加到 v_Score 中
    while ((row = mysql_fetch_row(result))) {
        Score score;
        score.ID( row[0]);    // 假设 user_id 是第一个列
        score.ScoreID( std::stoi(row[1]));  // 假设 score_id 是第二个列，转换为整数
        score.level (std::stoi(row[2])); // 假设 level 是第三个列，转换为整数
        score.theScore (std::stoi(row[3])); // 假设 score 是第四个列，转换为整数
        v_Score.push_back(score);
    }

    mysql_free_result(result);
}

void General::DeleteUser(string name, string password) {
    for (auto uit = v_User.begin(); uit != v_User.end(); ++uit) {
        if (uit->getName() == name && uit->getPassword() == password) {
            v_User.erase(uit);//只删除一个数据
            return;
        }
    }
}

Time& General::TimeControl() {
    switch (m_Speed) {
    case FAST:
        Sleep(150);
        m_time.TimeGrowth(0.15);
        break;
    case SLOW:
        Sleep(250);
        m_time.TimeGrowth(0.25);
        break;
    case PAUSE:
        while (1) {
            if (_kbhit()) {
                int ch = _getch();
                if (ch == 27) { 
                    break;
                }
            }
        }
        setSpeed(SLOW);
        break;
    default:
        Sleep(250);
        m_time.TimeGrowth(0.25);
        break;
    }
    cout << m_time.getMin() << ":" << m_time.getSecond() << endl;
    return this->m_time;
}


