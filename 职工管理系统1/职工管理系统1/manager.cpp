#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include"manager.h"
using namespace std;

Manager::Manager(int id, string name, int dId) {

	this->m_Id = id;
	this->m_Name = name;
	this->m_DpetId = dId;

}

void Manager::showInfo() {

	cout << " 职工编号:  " << this->m_Id
		<< "\t职工姓名 " << this->m_Name
		<< "\t岗位 " << this->getDepetName()
		<< "\t岗位职责:完成总裁的任务" << endl;


}



string Manager::getDepetName() {

	return "经理";
}