#pragma once
#include <iostream>
#include "identity.h"
#include<string>
#include"globalFilie.h"
#include<fstream>
#include<vector>
#include"student.h"
#include"teacher.h"
#include<algorithm>
#include"computerRoom.h"
#include"orderFile.h"
using namespace std;
//ѧ����
class Student : public Identity
{
public :
    //�޲ι���
	Student();

	//�вι���
	Student(int id,string name,string pwd);

	//�˵�ҳ��
	virtual void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴����ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();
    
	//ѧ��ѧ��
	int m_Id;

	//��������
	vector<ComputerRoom> vCom;

};