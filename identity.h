#pragma once //防止头文件重复包含
#include<iostream>

using namespace std;
//身份类
class Identity 
{
public:
	virtual void operMenu() = 0;//操作菜单

	string m_Name;//名字
	string m_Pwd;//密码
};