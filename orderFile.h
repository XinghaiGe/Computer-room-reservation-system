#pragma once
#include <iostream>
using namespace std;
#include <map>
#include "globalFile.h"
#include <fstream>
#include <string>

class OrderFile
{
public:
	//���캯��
	OrderFile();

	//����ԤԼ��¼
	void updateOrder();

	//��¼������ key --- ��¼������ value --- �������Ϣ
	map<int, map<string, string>> m_orderData;

	//��¼ԤԼ������
	int m_Size;
};