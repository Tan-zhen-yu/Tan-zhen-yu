#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<mysql.h>
using namespace std;

const char* host = "127.0.0.1";
const char* user = "root";
const char* pw = "root";
const char* database_name = "testc";
const int port = 3306;

typedef struct Student
{
	string student_Name;
	int student_Age;
	string student_id;
}Student;
int main() {

	MYSQL* con = mysql_init(NULL);
	//设置字符编码
	mysql_options(con, MYSQL_SET_CHARSET_NAME, "GBK");
	//连接
	if (!mysql_real_connect(con, host, user, pw, database_name, port, NULL, 0)) {

		fprintf(stderr, "Failed to connect database :Error%s\n", mysql_error(con));
		return 0;
	}
	else {
		cout << "连接成功" << endl;
	}

	Student stu{ "何怡鑫",18,"2209020090" };

	char sql[1024];

	sprintf(sql, "insert into 学生表 (姓名,年龄,学号) values('%s',%d,'%s')",
		stu.student_Name.c_str(), stu.student_Age, stu.student_id.c_str());

	if (mysql_query(con, sql)) {
		fprintf(stderr, "Failed to insert database :Error %s\n", mysql_error(con));
		return 0;
	}

	mysql_close(con);

	return 0;
}