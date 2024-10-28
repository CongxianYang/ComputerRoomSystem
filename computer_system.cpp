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
		//���ù���Ա�Ӳ˵�
		manager->operMenu();

		//������ָ�� ת��Ϊ����ָ�룬��������������ӿ�
		Manager* man = (Manager*)manager;

		int select = 0;
		cin >> select;
		if (select == 1) {
			//����˺�
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2) {
			//�鿴�˺�
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3) {
			//�鿴����
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4) {
			//���ԤԼ
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else {
			delete manager;//���ٵ���������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//ѧ���˵�
void studentMenu(Identity*& student) {
	while (true) {
		//ѧ���˵�
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
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}
//��ʦ�˵�
void teacherMenu(Identity*& teacher) {
	while (true) {
		//ѧ���˵�
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
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

//��¼���� �����ļ��� �����������
void LoginIn(string fileName, int type) {
	Identity* person = NULL;
	ifstream ifs;
	ifs.open(fileName, ios::in);
	//ifs.imbue(locale("")); // ʹ��ϵͳĬ�ϵ�locale
	//string line;
	//while (getline(ifs, line)) { // ���ж�ȡ�ļ�
		//std::cout << line << std::endl; // ���ÿһ��
	//}
	//�ж��ļ��Ƿ����
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	//׼���û���Ϣ
	int id = 0;
	string name;
	string pwd;
	if (type == 1) {
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "���������ְ���ţ�" << endl;
		cin >> id;
	}
	cout << "�������û�����" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;
	
	if (type == 1) {
		//ѧ�������֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "ѧ����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ���Ӳ˵�
				studentMenu(person);
				return;
			}
			cout << endl;

		}
		
	}
	else if (type == 2) {
		//��ʦ�����֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "��ʦ��֤��¼�ɹ���" << endl;
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
		//����Ա�����֤
		string fName;
		string fPwd;
		while ( ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd) {
				cout << "����Ա��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�������Աҳ��
				managerMenu(person);
				return;
			}
			cout << endl;
		}
	}
	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;

}
int main() {
	int select;
	while (true) {
		cout << "===========��ӭ��������ԤԼϵͳ========\n";
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
		case 1: //ѧ����� 
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
			system("pause");//�����������
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}