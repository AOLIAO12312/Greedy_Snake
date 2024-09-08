#include"User.h"

User::User() {};
User::User(string name, string password) :m_Name(name), m_Password(password) {}
void User::ID(string id) {
	m_ID = id;

}

void User::Name(string name) {
	m_Name = name;
}

void User::Password(string password) {
	m_Password = password;
}
bool User::Login(string password) {
	if (password == m_Password) {
		m_State = true;
		return true;
	}
	else {
		return false;
	}
}

void User::Logout() {
	m_State = false;
}

bool User::getState() {
	return m_State;
}
string User::getName() {
	return m_Name;
}
string User::getID() {
	return m_ID;
}
void User::insertUser() {
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
	string user_id = m_ID;
	string password = m_Password;
	string username = m_Name;
	char query[200]; // 增加查询字符串长度，以防止溢出
	sprintf(query, "INSERT INTO users (user_id, password, username) VALUES ('%s', '%s', '%s')",
		user_id, password, username);
	if (mysql_query(conn, query)) {
		fprintf(stderr, "Failed to insert data into MySQL: %s\n", mysql_error(conn));
	}
	else {
		printf("Data inserted successfully!\n");
	}
	mysql_close(conn);
}
string User::getPassword() {
	return m_Password;
}

