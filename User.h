#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<string>
#include <mysql.h>
using namespace std;
class User {
private:
	bool m_State;//falseδ��¼״̬ trueΪ��¼״̬
	string m_ID;
	string m_Name;
	string m_Password;
public:
	User();
	User( string name, string password);
	bool Login(string password);
	void Logout();
	bool getState();
	string getName();
	string getID();
	string getPassword();   
	void ID(string id);
	void Name(string name);
	void Password(string password);
	void insertUser();
};
