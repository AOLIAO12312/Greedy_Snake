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
        cerr << "�޷����ļ� " << filename << " ���ж�ȡ\n";
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
        cerr << "�޷����ļ� " << filename << " ����д��\n";
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
    char arr_biaoti[] = "����   ����ʱ��    ����    ����";
    outtextxy(100, 45, arr_biaoti);
    int maxRankWidth = 7; // 
    int maxTimeWidth = 9; // 
    int maxLengthWidth = 6; // 
    int maxScoreWidth = 2; // 
    //// �ڴ�������ʾ��Ϣ����

    for (size_t i = 0; i < vgs.size(); ++i) {
        char buffer[50]; // ���ڴ洢ת������ַ���

        // ��ʽ��General��ϢΪ�ַ���
        sprintf_s(buffer, "%-*d %-*d %-*d %-*d", maxRankWidth, i + 1, maxTimeWidth, vgs[i].time, maxLengthWidth, vgs[i].length, maxScoreWidth, vgs[i].score);

        // �ڴ�������ʾGeneral��Ϣ�������ö��뷽ʽΪ�����
        outtextxy(120, 90 + i * 40, buffer);
    }
    ////// �ڴ�������ʾÿ��General����Ϣ
    //for (size_t i = 0; i < vgs.size(); ++i) {
    //    char buffer[50]; // ���ڴ洢ת������ַ���

    //    // ��ʽ��General��ϢΪ�ַ���
    //    sprintf_s(buffer, "%d           %d           %d       %d", i + 1, vgs[i].time, vgs[i].length, vgs[i].score);
    //    // �ڴ�������ʾGeneral��Ϣ
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
    // ��ѯ users ��
    MYSQL* connection = mysql_init(nullptr); // ��ʼ�� MySQL ����
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

    // ���ж�ȡ��ѯ�������ӵ� v_User ��
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        User user;
        user.ID(row[0]);   // ���� user_id �ǵ�һ����
        user.Name(row[1]);  // ���� username �ǵڶ�����
        user.Password(row[2]);  // ���� password �ǵ�������
        v_User.push_back(user);
    }

    mysql_free_result(result);

    // ��ѯ scores ��
    if (mysql_query(connection, "SELECT * FROM scores")) {
        fprintf(stderr, "Error querying scores table: %s\n", mysql_error(connection));
        return;
    }

    result = mysql_store_result(connection);
    if (!result) {
        fprintf(stderr, "Error storing scores query result: %s\n", mysql_error(connection));
        return;
    }

    // ���ж�ȡ��ѯ�������ӵ� v_Score ��
    while ((row = mysql_fetch_row(result))) {
        Score score;
        score.ID( row[0]);    // ���� user_id �ǵ�һ����
        score.ScoreID( std::stoi(row[1]));  // ���� score_id �ǵڶ����У�ת��Ϊ����
        score.level (std::stoi(row[2])); // ���� level �ǵ������У�ת��Ϊ����
        score.theScore (std::stoi(row[3])); // ���� score �ǵ��ĸ��У�ת��Ϊ����
        v_Score.push_back(score);
    }

    mysql_free_result(result);
}

void General::DeleteUser(string name, string password) {
    for (auto uit = v_User.begin(); uit != v_User.end(); ++uit) {
        if (uit->getName() == name && uit->getPassword() == password) {
            v_User.erase(uit);//ֻɾ��һ������
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


