#pragma once
using namespace std;
#include <iostream>
#include "identity.h"
#include <string>
#include "orderFile.h"
#include <vector>

class Teacher : public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();

	//�вι���
	Teacher(int empId, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	int m_EmpId;//��ʦ���
};