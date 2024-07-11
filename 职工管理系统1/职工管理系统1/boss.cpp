#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include"boss.h"
using namespace std;

Boss::Boss(int id, string name, int dId) {

	this->m_Id = id;
	this->m_Name = name;
	this->m_DpetId = dId;

}

void  Boss::showInfo() {

	cout << " 职工编号:  " << this->m_Id
		<< "\t职工姓名 " << this->m_Name
		<< "\t岗位 " << this->getDepetName()
	<< "\t岗位职责:管理公司全部事务" << endl;


}



string Boss ::getDepetName() {

	
	return string("总裁");
}