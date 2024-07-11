#pragma once
#include<string.h>
#include<iostream>
#include"woker.h"
using namespace std;

class Manager : public Woker {

public:
	Manager(int id, string name, int dId);

	virtual void showInfo();

	virtual string getDepetName();

};