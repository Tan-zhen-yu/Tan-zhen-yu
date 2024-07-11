#pragma once
#include<string.h>
#include<iostream>
#include"woker.h"
using namespace std;

class Boss : public Woker {

public:
	Boss(int id, string name, int dId);

	virtual void showInfo();

	virtual string getDepetName();

};