#include"Score.h"

Score::Score() {};
void Score::ID(string id) {
	m_UserID = id;
}
void Score::ScoreID(int scoreid) {
	m_ScoreID = scoreid;
}
void Score::theScore(int score) {
	m_Score = score;
}
void Score::level(int level) {
	m_level = level;
}
Score::Score(unsigned ScoreID, string UserID, int level, unsigned int score) {
	m_Score = score;
	m_UserID = UserID;
	m_ScoreID = ScoreID;
	m_level = level;
}
void Score::insertScore(string id) {
	MYSQL mysql;
	mysql_init(&mysql);

	// 设置字符编码
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");

	// 连接数据库
	MYSQL* conn = mysql_real_connect(&mysql, "127.0.0.1", "root", "thedangerinmyheart", "snack", 3306, NULL, 0);
	if (conn == NULL) {
		fprintf(stderr, "Connection failed: %s\n", mysql_error(&mysql));
		exit(1);
	}
	int score_id = m_ScoreID;
	int level = m_level;
	int score = m_Score;

	char query[200]; // 增加查询字符串长度，以防止溢出
	sprintf(query, "INSERT INTO scores (user_id, score_id, level,score) VALUES ('%s', '%d', '%d','%d')",id, score_id, level, score);
	if (mysql_query(conn, query)) {
		fprintf(stderr, "Failed to insert data into MySQL: %s\n", mysql_error(conn));
	}
	else {
		printf("Data inserted successfully!\n");
	}
	mysql_close(conn);
}

