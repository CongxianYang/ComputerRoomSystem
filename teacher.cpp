#include"teacher.h"


//Ĭ�Ϲ���
Teacher::Teacher() {

}

//�вι���(ְ����ţ����������룩
Teacher::Teacher(int empID, string name, string pwd) {
	this->m_EmpId = empID;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//�˵�����
void Teacher::operMenu() {
	cout << "===========��ӭ��ʦ��" << this->m_Name << "��¼����ԤԼϵͳ========\n";
	cout << "\t\t----------------\n";
	cout << "\t\t  1,�鿴����ԤԼ \n";
	cout << "\t\t  2,���ԤԼ \n";
	cout << "\t\t  3,ע����¼ \n";
	cout << "\t\t----------------\n";
	cout << "��ѡ����Ĳ���:";
}

//�鿴����ԤԼ
void Teacher::showAllOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++) {
		cout << i + 1 << ", ";
		cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
		cout << " ʱ���:" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << " ѧ��:" << of.m_orderData[i]["stuId"];
		cout << " ����:" << of.m_orderData[i]["stuName"];
		cout << " ����:" << of.m_orderData[i]["roomId"];
		string status = "״̬:";
		if (of.m_orderData[i]["status"] == "1") {
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2") {
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "-1") {
			status += "���δͨ����ԤԼʧ��";
		}
		else {
			status += "ԤԼ�Ѿ�ȡ��";
		}

		cout << status << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ
void Teacher::validOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵�ԤԼ��¼����" << endl;
	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++) {
			if (of.m_orderData[i]["status"] == "1" ) {
				v.push_back(i);//�洢ԭʼ���±�λ��
				cout << index++ << ",";
				cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
				cout << " ʱ���:" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
				cout << " ����:" << of.m_orderData[i]["roomId"];
				string status = "״̬:";
				if (of.m_orderData[i]["status"] == "1") {
					status += "�����";
				}
				cout << status << endl;

			}
	}
	cout << "������Ҫ��˵ļ�¼��0��������" << endl;
	int select = 0;
	int ret=0;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			}
			else {
				cout << "��������˽����" << endl;
				cout << "1,ͨ��" << endl;
				cout << "2����ͨ��" << endl;
				cin >> ret;
				if (ret == 1) {
					of.m_orderData[v[select - 1]]["status"] = "2";
				}
				else if (ret == 2) {
					of.m_orderData[v[select - 1]]["status"] = "-1";
				}
				of.updateOrder();
				cout << "�����ɹ�" << endl;
				break;
			}
		}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
}