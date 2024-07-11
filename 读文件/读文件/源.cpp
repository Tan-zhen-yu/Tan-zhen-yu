#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;

void test01()
{
	ifstream ifs;

	ifs.open("text.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	char buf[1024] = {};

	if (ifs >> buf)
	{
		cout << buf << endl;
	}

	ifs.close();






}

int main()
{


	test01();

	return 0;
}