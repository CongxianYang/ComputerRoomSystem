#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include<string>
#include"globalFilie.h"
#include<fstream>
#include<vector>
#include"student.h"
#include"teacher.h"
#include<algorithm>
#include"computerRoom.h"
//管理员类
class Manager :public Identity
{
public:
	Manager();
	Manager(string name,string pwd);

	//菜单页面
	virtual void operMenu();

	//添加账号
	void addPerson();

	//查看账号
	void showPerson();
	//查看机房信息
	void showComputer();

	//清空预约记录
	void cleanFile();

	//初始化容器 用于去除重复的
	void initVector();

	//学生容器
	vector<Student> vStu;

	//教师容器
	vector<Teacher> vTea;

	//检查重复 参数（传入的id,传入的类型） 返回值(true代表重复）
	bool checkRepeat(int id, int type);

	//机房容器
	vector<ComputerRoom> vCom;
};