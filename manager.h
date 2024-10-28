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
//����Ա��
class Manager :public Identity
{
public:
	Manager();
	Manager(string name,string pwd);

	//�˵�ҳ��
	virtual void operMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();
	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFile();

	//��ʼ������ ����ȥ���ظ���
	void initVector();

	//ѧ������
	vector<Student> vStu;

	//��ʦ����
	vector<Teacher> vTea;

	//����ظ� �����������id,��������ͣ� ����ֵ(true�����ظ���
	bool checkRepeat(int id, int type);

	//��������
	vector<ComputerRoom> vCom;
};