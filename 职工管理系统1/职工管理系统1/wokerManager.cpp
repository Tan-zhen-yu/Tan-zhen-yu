#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include"wokerManager.h"
using namespace std;

wokerManager::wokerManager() {

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	this->m_EmpNum = this->get_EmpNum();

	this->m_EmpArray = new Woker * [this->m_EmpNum];

	this->init_Emp();

	ifs.close();

}

void wokerManager::delete_All() {

	delete[]this->m_EmpArray;
	this->m_EmpArray = NULL;
	this->m_EmpNum = 0;
	this->m_FileIsEmpty = true;

	return;
}

void wokerManager::quicksort(int left,int right) {

	int i = left;
	int j = right;
	Woker* temp;
	Woker* Base = this->m_EmpArray[left];
	

	if (left > right)
		return;
	while (i != j)
	{
		while (this->m_EmpArray[j]->m_Id >= Base->m_Id && i < j)
		{
			j--;
		}

		while (this->m_EmpArray[i]->m_Id <= Base->m_Id && i < j)
		{
			i++;
		}

		if (i < j)
		{
			temp = this->m_EmpArray[i];
			this->m_EmpArray[i] = this->m_EmpArray[j];
			this->m_EmpArray[j] = temp;
		}

	}
	this->m_EmpArray[left] = this->m_EmpArray[i];
	this->m_EmpArray[i] = Base;

	quicksort(left, i - 1);//继续处理左边的，这里是一个递归的过程
	quicksort(i + 1, right);


}

void wokerManager::modifyManager() {

	bool flat = false;
	cout << "以下是所有成员信息" << endl;
	this->showWokerManager();
	cout << "请输入被修改人的姓名:" << endl;
	int id;
	string name;
	int dId;
	cin >> name;
	Woker* woker = NULL;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Name.compare(name)==0)
		{
			flat = true;

			cout << "请输入新编号" << endl;
			cin >> id;
			cout << "请输入新姓名" << endl;
			cin >> name;
			cout << "请选择该职工的岗位" << endl
				<< "1、普通员工" << endl
				<< "2、经理" << endl
				<< "3、老板" << endl;
			cin >> dId;
		    woker = NULL;
			switch (dId)
			{
			case 1: {
				woker = new Employee(id, name, dId);
				break;
			}
			case 2: {
				woker = new Manager(id, name, dId);
				break;
			}
			case 3: {
				woker = new Boss(id, name, dId);
				break;
			}
			}
			this->m_EmpArray[i] = woker;
		}
		
	}
	if (flat == true)
	{
		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

}

void wokerManager::showWokerManager() {

	bool flat = false;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		this->m_EmpArray[i]->showInfo();
		flat = true;
	}
	if (flat == false)
	{
		cout << "显示失败，暂无数据" << endl;
	}

}

void wokerManager::queryManager() {

	cout << "请输入需要查找的类别:<" << endl;
	cout << "1、编号" << endl;
	cout << "2、名字" << endl;
	cout << "3、岗位" << endl;
	bool flat = false;
	int id;
	string name;
	int dId;
	int slect = 0;
	cin >> slect;

	switch (slect)
	{
	case 1: {
		cout << "请输入需要编号:<" << endl;
		cin >> id;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i]->m_Id == id)
			{
				flat = true;
				this->m_EmpArray[i]->showInfo();
			}
		}
		break;
	}
	case 2: {
		cout << "请输入需要姓名:<" << endl;
		cin >> name;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i]->m_Name == name)
			{
				flat = true;
				this->m_EmpArray[i]->showInfo();
			}
		}
		break;
	}
	case 3: {
		cout << "请输入需要岗位:<" << endl;
		cout << "1、员工" << endl;
		cout << "2、经理" << endl;
		cout << "3、老板" << endl;
		cin >> dId;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i]->m_DpetId == dId)
			{
				flat = true;
				this->m_EmpArray[i]->showInfo();
			}
		}
		break;
	}
	default:
		cout << "输入错误，已退出" << endl;
		break;
	}
	if (flat == false)
	{
		cout << "查无此人" << endl;
	}
}

void wokerManager::deleteManager() {

	bool flat = false;
	cout << "以下是所有成员信息" << endl;
	this->showWokerManager();
	cout << "请输入被删除人的姓名:" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Name.compare(name) == 0)
		{
			flat = true;
			for (int j = i; j < this->m_EmpNum - 1; j++)
			{
				this->m_EmpArray[j] = this->m_EmpArray[j + 1];
			}
			this->m_EmpNum--;
		}
	}
	if (flat == false)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		cout << "删除成功" << endl;
	}


}

void wokerManager::init_Emp() {

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	Woker* woker = NULL;

	int id;
	string name;
	int dId;
	int i = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		switch (dId)
		{
		case 1: {
			woker = new Employee(id, name, dId);
			break;
		}
		case 2: {
			woker = new Manager(id, name, dId);
			break;
		}
		case 3: {
			woker = new Boss(id, name, dId);
			break;
		}
		default:
			break;
		}
		this->m_EmpArray[i]=woker;
		i++;
	}






}

int wokerManager::get_EmpNum() {

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}

	ifs.close();

	return num;

}

wokerManager::~wokerManager() {

	this->save();
	delete[] this->m_EmpArray;
	this->m_EmpArray = NULL;

}

void wokerManager:: save() {
	
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id<<" "
		 << this->m_EmpArray[i]->m_Name<<" "
		 << this->m_EmpArray[i]->m_DpetId<<endl;
	}

	ofs.close();
}

void wokerManager::Add_Emp() {

	cout << "请输入需要添加职工的人数" << endl;
	int addNum = 0;

	cin >> addNum;

	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum;

		Woker** newSpace = new Woker * [newSize];

		if (m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//添加新数据

		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dId;//部门

			cout << "请输入第" << i + 1 << "个新职工的编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工的姓名" << endl;
			cin >> name;
			cout << "请选择该职工的岗位" << endl
				<< "1、普通员工" << endl
				<< "2、经理" << endl
				<< "3、老板" << endl;
			
			cin >> dId;
			Woker* woker=NULL;
			switch (dId)
			{
			case 1: {
				woker = new Employee(id, name, dId);
				break;
			}
			case 2: {
				woker = new Manager(id, name, dId);
				break;
			}
			case 3: {
				woker = new Boss(id, name, dId);
				break;
			}
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = woker;
			
		}
		delete[] this->m_EmpArray;

		this->m_EmpArray = newSpace;

		this->m_EmpNum = newSize;

		cout << "成功添加" << addNum << "名新职工" << endl;

		this->save();
			
	}
	else
	{
		cout << "输入有误，已退出" << endl;
	}


}


void wokerManager:: showMenu() {

	cout << "****************************************" << endl;
	cout << "**********欢迎使用职工管理系统**********" << endl;
	cout << "**********   0 退出管理系统   **********" << endl;
	cout << "**********   1 添加职工信息   **********" << endl;
	cout << "**********   2 显示职工信息   **********" << endl;
	cout << "**********   3 删除离职职工   **********" << endl;
	cout << "**********   4 修改职工信息   **********" << endl;
	cout << "**********   5 查找职工信息   **********" << endl;
	cout << "**********   6 按照编号排序   **********" << endl;
	cout << "**********   7 清空所有文档   **********" << endl;
	cout << "****************************************" << endl;
}


int main()
{
	wokerManager wk;
	
	int slect = 1;

	while (slect)
	{
		
		wk.showMenu();
		cout << "请输入您的选择：" << endl;
		cin >> slect;
		
		switch (slect){
			
			//退出
			case 0: {
				cout << "感谢使用,退出成功" << endl;
				break;
			}
			//添加
			case 1: {
				wk.Add_Emp();
				break;
			}
			//显示
			case 2: {
				wk.showWokerManager();
				break;
			}
			//删除
			case 3: {
				wk.deleteManager();
				
				break;
			}
			//修改
			case 4: {
				wk.modifyManager();
				break;
			}
			//查找
			case 5: {
				wk.queryManager();
				break;
			}
			//按照编号排序
			case 6: {
				wk.quicksort(0, wk.m_EmpNum - 1);
				cout << "排序成功" << endl;
				break;
			}
			//清空所有文档
			case 7: {
				wk.delete_All();
				break;
			}
		
			default:
				cout<<"选择错误，请重新选择"<<endl;
				break;
			}
		system("pause");
		system("cls");
	}


	return 0;
}