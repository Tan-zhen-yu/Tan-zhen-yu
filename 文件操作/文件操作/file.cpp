#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;


void test01()
{
	ofstream file;
	file.open("text.txt", ios::out);
	file << "张三 18岁" << endl;
	file << "李四 20岁" << endl;

	file.close();
}

int main()
{

	test01();


	return 0;
}