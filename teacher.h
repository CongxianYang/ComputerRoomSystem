#pragma once
#include<iostream>
#include "identity.h"
using namespace std;
#include"orderFile.h"
#include<vector>
//老师类
class Teacher :public Identity
{
public:
	//默认构造
	Teacher();

	//有参构造
	Teacher(int empID,string name,string pwd);

	//菜单界面
	virtual void operMenu();

	//查看所有预约
	void showAllOrder();

	//审核预约
	void validOrder();

	//职工号
	int m_EmpId;
};