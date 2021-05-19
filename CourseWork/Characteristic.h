#pragma once
#include "Functions.h"
#include <sys/stat.h>
#define EXTENSIONS_NUM 3
class Characteristic {
	int charactRating; // ������� ��������������
	int charactLanguage; // ���� ��������������
	int charactPurpose; // ���� ���������� ��������������
	string nameOfStudentFile; //��'� ������������ �����, � ���� �������� �����
	string fileExtension; // ���������� �����
	string directoryName; // ����� ����� ��� ��������� �����
	string allowableExtensions[EXTENSIONS_NUM] = { "txt", "doc", "docx" }; // �������� ���������� �����
public:
	void charactInput(); // ������� ��� ������� ����� ��� ��������������
	void charactOutput(); // ������� ��� ��������� ����� ��� ��������������
	string charactChoice(); // ������� ������ ��������� �������
	string getNameOfStudentFile(); // ������� ��� ��������� ����� �����, � ���� �������� �����
	void makeDirectory(); // ������� ��� ��������� ����� ��� ��������� �����
	bool matchExtension(string str); // ������� ��� �������� ���������� ��������� �����
};
