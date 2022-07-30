#include <iostream>
using namespace std;
#include "globalFile.h"
#include "identity.h"
#include "manager.h"
#include "teacher.h"
#include "student.h"
#include <fstream>
#include <string>

//进入教师子菜单页面
void teacherMenu(Identity* &teacher)
{
	while (true)
	{
		//教师菜单
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入学生子菜单界面
void studentMenu(Identity*& student)
{
	while (true)
	{
		//学生菜单
		student->operMenu();

		Student* stu = (Student*)student;
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			stu->applayOrdder();
		}
		else if (select == 2)
		{
			stu->showMyOrder();
		}
		else if (select == 3)
		{
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			stu->cancelOrder();
		}
		else
		{
			delete student;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入管理员子菜单界面
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//调用管理员子菜单
		manager->operMenu();

		//将父类指针 转为 子类的指针
		Manager* man = (Manager*)manager;

		//接受用户的选择
		int select = 0;
		
		cin >> select;
		if (select == 1)
		{
			man->addPerson();
		}
		else if (select == 2)
		{
			man->showPerson();
		}
		else if (select == 3)
		{
			man->showComputer();
		}
		else if (select == 4)
		{
			man->cleanFile();
		}
		else
		{
			delete man;//销毁堆区对象
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//登录功能
void LoginIn(string filename, int type)
{
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(filename, ios::in);

	//文件不存在情况
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1) //学生登录
	{
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	else if (type == 2) //教师登录
	{
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生登录验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId >> fName >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "学生验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生身份的子菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师登录验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId >> fName >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "教师验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入教师身份的子菜单
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员登录验证
		string fName;
		string fPwd;
		while (ifs >> fName >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "管理员验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入管理员身份的子菜单
				managerMenu(person);

				return;
			}
		}
	}

	cout << "验证登录失败！" << endl;

	system("pause");
	system("cls");
	return;
}

int main()
{
	int select = 0;
	while (true)
	{
		cout << "===================欢迎来到机房预约系统================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t-----------------------------------\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|            1.学生代表           |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|            2.老师               |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|            3.管理员             |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|            0.退出               |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t-----------------------------------\n";
		cout << "请输入您的选择：";

		cin >> select;

		switch (select)
		{
		case 1://学生身份
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://老师身份
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://管理员身份
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://退出系统
			cout << "欢迎下一次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");

	return 0;
}