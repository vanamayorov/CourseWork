#pragma once
#include <fstream>
#include "Functions.h"
#define MAX_SIZE 255
#define MIN_SIZE 10
class Student {
	string studentName; // ПІБ студента
	int studentSex; // стать студента
	string studentAge; // вік студента
	int studentHobby; // види захоплень
	int numOfQualities; // к-сть якостей
	string* studentQualities;// особисті якості
public:
	void studentInput(); // функція для введеня даних про студента користувачем
	void studentOutput(); // функція для виведення даних про студента користувачем
	bool studentCharact(string inputFile, string outputFile);// функція для виведення характеристики
	~Student() {
		delete[]studentQualities;
	}
};