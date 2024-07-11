#pragma once
#include<string.h>
#include<iostream>
using namespace std;

class Woker {

public:

	virtual void showInfo() = 0;

	virtual string getDepetName() = 0;


	int m_Id;
	string m_Name;
	int m_DpetId;



};