#include"manager.h"
Manager::Manager() {

}
Manager::Manager(string name, string pwd) {
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->initVector();
	
	//获取机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum) {
		vCom.push_back(c);
	}
	cout << "当前机房数量为：" << vCom.size() << endl;
	ifs.close();
}

//菜单页面
void Manager::operMenu() {
	cout << "===========欢迎管理员："<<this->m_Name <<"登录机房预约系统========\n";
	cout << "\t\t----------------\n";
	cout << "\t\t  1,添加账号 \n";
	cout << "\t\t  2,查看账号 \n";
	cout << "\t\t  3,查看机房 \n";
	cout << "\t\t  4,清空预约 \n";
	cout << "\t\t  5,注销登录 \n";
	cout << "\t\t----------------\n";
	cout << "请选择你的操作:";
}

//添加账号
void Manager::addPerson() {
	cout << "请输入添加账号的类型" << endl;
	cout << "1,添加学生" << endl;
	cout << "2,添加老师" << endl;
	string fileName;
	string tip;
	ofstream ofs;
	string errorTip;//错误提示
	int select = 0;
	cin >> select;
	if (select = 1) {
		fileName = STUDENT_FILE;
		tip = "请输入学号:";
		errorTip = "学号重复，请重新输入";
	}
	else {
		fileName = TEACHER_FILE;
		tip = "请输入职工编号";
		errorTip = "职工号重复，请重新输入";
	}
	ofs.open(fileName, ios::out | ios::app);//追加模式和输出模式打开
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	while (true) {
		cin >> id;
		bool ret = this->checkRepeat(id, 1);
		if(ret) {
			cout << errorTip << endl;
		}
		else {
			break;
		}
	}
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;
	system("pause");
	system("cls");
	ofs.close();
	//调用初始化接口，重新更新容器
	this->initVector();

}
void printStudent(Student& s) {
	cout << "学号:" << s.m_Id << " 姓名:" << s.m_Name << " 密码：" << s.m_Pwd << endl;
}
void printTeacher(Teacher& t) {
	cout << "学号:" << t.m_EmpId << " 姓名:" << t.m_Name << " 密码：" << t.m_Pwd << endl;
}
//查看账号
void Manager::showPerson() {
	cout << "请选择查看内容："<< endl;
	cout << "1,查看所有学生" << endl;
	cout << "2,查看所有老师" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		cout << "所有学生信息如下：" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else {
		cout << "所有老师信息如下：" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}
//查看机房信息
void Manager::showComputer() {
	cout << "机房信息如下：" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++) {
		cout << "机房号：" << it->m_ComId << " 机房最大容量：" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::cleanFile() {
	ofstream ofs(ORDER_FILE, ios::trunc);//ofs 以截断模式 (ios::trunc) 打开 ORDER_FILE 文件。 若文件已经存在，文件内容将被清空，文件长度变为零
	ofs.close();
	cout << "清空成功！"<<endl;
	system("pause");
	system("cls");
}
//初始化容器
void Manager::initVector() {

	//ofstream：用于向文件写入数据。
	//ifstream：用于从文件读取数据。

	//读取学生文件信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件读取失败" << endl;
		return;
	}
	vStu.clear();
	vTea.clear();
	//读取所有的学生信息
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {
		vStu.push_back(s);
	}
	cout << "当前的学生数量为：" << vStu.size() << endl;
	ifs.close();

	//读取所有的老师信息
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd) {
		vTea.push_back(t);
	}
	cout << "当前的教师数量为：" << vTea.size() << endl;
	ifs.close();


}
bool Manager::checkRepeat(int id, int type) {
	if (type == 1) {
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
			if (id == it->m_Id) {
				return true;
			}
		}
	}
	else {
		for (vector < Teacher>::iterator it = vTea.begin(); it != vTea.end();it++)
			if (id == it->m_EmpId) {
				return true;
			}
	}
	return false;
}