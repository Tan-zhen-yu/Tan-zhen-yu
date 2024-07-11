#define _CRT_SECURE_NO_WARNINGS
#include"iostream"
#include"fstream"
using namespace std;

int main()
{
	ofstream ofs;
	ofs.open("first file",ios::out);

	ofs << "this is my first stream in the file";
	ofs.close();



	return 0;
}