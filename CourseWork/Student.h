#pragma once
#include <fstream>
#include "Functions.h"
#define MAX_SIZE 255
#define MIN_SIZE 10
class Student {
	string studentName; // ϲ� ��������
	int studentSex; // ����� ��������
	string studentAge; // �� ��������
	int studentHobby; // ���� ���������
	int numOfQualities; // �-��� �������
	string* studentQualities;// ������� �����
public:
	void studentInput(); // ������� ��� ������� ����� ��� �������� ������������
	void studentOutput(); // ������� ��� ��������� ����� ��� �������� ������������
	bool studentCharact(string inputFile, string outputFile);// ������� ��� ��������� ��������������
	~Student() {
		delete[]studentQualities;
	}
};