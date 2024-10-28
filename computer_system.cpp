#include<iostream>
#include"identity.h"
#include<fstream>
#include"globalFilie.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
#include"string"
using namespace std;

void managerMenu(Identity*& manager) {
	while (true)
	{
		//调用管理员子菜单
		manager->operMenu();

		//将父类指针 转化为子类指针，调用子类的其他接口
		Manager* man = (Manager*)manager;

		int select = 0;
		cin >> select;
		if (select == 1) {
			//添加账号
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2) {
			//查看账号
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3) {
			//查看机房
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4) {
			//清空预约
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else {
			delete manager;//销毁掉堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//学生菜单
void studentMenu(Identity*& student) {
	while (true) {
		//学生菜单
		student->operMenu();
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		if (select == 1) {
			stu->applyOrder();
		}
		else if (select == 2) {
			stu->showMyOrder();
		}
		else if (select == 3) {
			stu->showAllOrder();
		}
		else if (select == 4) {
			stu->cancelOrder();
		}
		else {
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}
//老师菜单
void teacherMenu(Identity*& teacher) {
	while (true) {
		//学生菜单
		teacher->operMenu();
		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;
		if (select == 1) {
			tea->showAllOrder();
		}
		else if (select == 2) {
			tea->validOrder();
		}
		else {
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

//登录功能 操作文件名 操作身份类型
void LoginIn(string fileName, int type) {
	Identity* person = NULL;
	ifstream ifs;
	ifs.open(fileName, ios::in);
	//ifs.imbue(locale("")); // 使用系统默认的locale
	//string line;
	//while (getline(ifs, line)) { // 逐行读取文件
		//std::cout << line << std::endl; // 输出每一行
	//}
	//判断文件是否存在
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	//准备用户信息
	int id = 0;
	string name;
	string pwd;
	if (type == 1) {
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "请输入你的职工号：" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;
	
	if (type == 1) {
		//学生身份验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生子菜单
				studentMenu(person);
				return;
			}
			cout << endl;

		}
		
	}
	else if (type == 2) {
		//教师身份验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				teacherMenu(person);
				return;
			}
			cout << endl;
		}

	}
	else if (type == 3) {
		//管理员身份验证
		string fName;
		string fPwd;
		while ( ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd) {
				cout << "管理员验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入管理员页面
				managerMenu(person);
				return;
			}
			cout << endl;
		}
	}
	cout << "验证登录失败！" << endl;
	system("pause");
	system("cls");
	return;

}
int main() {
	int select;
	while (true) {
		cout << "===========欢迎来到机房预约系统========\n";
		cout << "please enter your identity" << endl;
		cout << "\t\t----------------\n";
		cout << "\t\t  1,student \n";
		cout << "\t\t  2,teacher \n";
		cout << "\t\t  3,system admin \n";
		cout << "\t\t  4,exit \n";
		cout << "\t\t----------------\n";
		cout << "please enter your choice:";
		cin >> select;
		switch (select)
		{
		case 1: //学生身份 
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
		case 4:
			cout << "welcome next use!";
			system("pause");
			return 0;
			break;
		default:
			cout << "enter error! please enter verify nums again!" << endl;
			system("pause");//按任意键继续
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}