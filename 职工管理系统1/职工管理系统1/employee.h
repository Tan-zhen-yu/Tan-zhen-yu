#pragma once
#include<string.h>
#include<iostream>
#include"woker.h"
using namespace std;

class Employee : public Woker {

public:
	Employee(int id, string name, int dId);

	virtual void showInfo();

	virtual string getDepetName();

};