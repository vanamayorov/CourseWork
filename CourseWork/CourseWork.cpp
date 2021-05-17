#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <climits>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <string.h>
#include <windows.h>
using namespace std;
#define MAX_SIZE 255

bool hasOnlyDigits(const string s); // функція для перевірки строк на наявність букв
string getDate();

class Student {
	string studentName; // ПІБ студента
	int studentSex; // стать студента
	string studentAge; // вік студента
	int studentHobby; // види захоплень
	int numOfQualities; // к-сть якостей
	string* studentQualities;// особисті якості
	string studentQuality; //окремо взята якість для запису у массив
public:
	Student() {
		studentName = "";
		studentSex = 0;
		studentAge = "";
		studentHobby = 0;
		numOfQualities = 0;
		studentQualities = NULL;
		studentQuality = "";
	}
	void studentInput(); // функція для введеня даних про студента користувачем
	void studentOutput(); // функція для виведення даних про студента користувачем
	void studentCharact(string filename); // функція для виведення характеристики
	string getName() {
		return this->studentName;
	}
	~Student() {
		delete[]studentQualities;
	}
};

class Characteristic {
	int charactRating; // рейтинг характеристики
	int charactLanguage; // мова характеристики
	int charactPurpose; // куди призначена характеристика
public:
	void charactInput(); // функція для введеня даних про характеристику
	void charactOutput(); // функція для виведення даних про характеристику
	string charactChoice(); // функція вибору потрібного шаблону
};



void Characteristic::charactInput() {
	cout << "Оберіть на кого характеристика: " << endl;
	cout << "1.Учень \n2.Студент \n" << "> ";
	cin >> charactPurpose;
	while (!cin.good() || charactPurpose < 1 || charactPurpose > 2) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Невірний ввід, спробуйте ще раз:" << endl << "> ";
		cin >> charactPurpose;
	}
	cout << "Оберіть рейтинг характеристики: " << endl;
	cout << "1.Позитивна \n2.Негативна \n3.На 50% позитивна і на 50% негативна\n" << "> ";
	cin >> charactRating;
	while (!cin.good() || charactRating < 1 || charactRating > 3) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Невірний ввід, спробуйте ще раз:" << endl << "> ";
		cin >> charactRating;
	}

	cout << "Оберіть мову характеристики: " << endl;
	cout << "1.Українська \n2.Російська \n3.Англійська\n" << "> ";
	cin >> charactLanguage;
	while (!cin.good() || charactLanguage < 1 || charactLanguage > 3) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Невірний ввід, спробуйте ще раз:" << endl << "> ";
		cin >> charactLanguage;
	}
}

void Characteristic::charactOutput() {
	cout << "Characteristic: " << endl << charactRating << endl << charactLanguage << endl;
}

string Characteristic::charactChoice() {
	string filename;
	if (charactRating == 1) {
		filename = "pupil_positive.txt";
	}
	else if (charactRating == 2) {
		filename = "pupil_negative.txt";
	}
	else {
		filename = "pupil_50.txt";
	}
	return filename;
}


void Student::studentInput() {
	cout << "Введіть прізвище, ім'я, по батькові:" << endl;
	getline(cin, studentName);
	while (!cin.good() || studentName.length() <= 10 || studentName.length() >= 255 || hasOnlyDigits(studentName)) {
		cout << "Невірний ввід, спробуйте ще раз:" << endl << "> ";
		getline(cin, studentName);
	}
	cout << "Введіть стать(0-чоловіча, 1-жіноча): ";
	cin >> studentSex;
	while (!cin.good() || (studentSex != 0 && studentSex != 1)) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Невірний ввід, спробуйте ще раз:" << endl << "> ";
		cin >> studentSex;
	}
	cout << "Введіть рік народження: ";
	cin >> studentAge;
	while (!cin.good() || stoi(studentAge) <= 1920 || stoi(studentAge) > 2021) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Невірний ввід, спробуйте ще раз:" << endl << "> ";
		cin >> studentAge;
	}
	cout << "Оберіть захоплення серед перелічених: " << endl;
	cout << "1.Спорт \n2.Читання книг \n3.Фотографування \n4.Графічний дизайн \n5.Електроніка  \n" << "> ";
	cin >> studentHobby;
	while (!cin.good() || studentHobby < 1 || studentHobby > 5) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Невірний ввід, спробуйте ще раз:" << endl;
		cout << "Оберіть захоплення серед перелічених: " << endl;
		cout << "1.Спорт \n2.Читання книг \n3.Фотографування \n4.Графічний дизайн \n5.Електроніка  \n"
			<< endl << "> ";
		cin >> studentHobby;
	}
	cout << "Введіть к-сть якостей студента: " << endl << "> ";
	cin >> numOfQualities;
	while (!cin.good() || numOfQualities <= 0 || numOfQualities >= 10) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Невірний ввід, спробуйте ще раз:" << endl << "> ";
		cin >> numOfQualities;
	}
	studentQualities = new string[numOfQualities];
	cout << "Введіть якості студента:" << endl << "> ";
	for (int i = 0; i < numOfQualities; i++) {
		cin >> studentQuality;
		while (studentQuality.length() == 0 || !cin.good() || hasOnlyDigits(studentQuality)) {
			cout << "Невірний ввід, спробуйте ще раз:" << endl << "> ";
			cin >> studentQuality;
		}
		studentQualities[i] = studentQuality;

	}
}

void Student::studentOutput() {
	cout << "Student:" << endl << studentName << endl << ((studentSex) ? "Жіноча" : "Чоловіча") << " стать" << endl << studentAge << endl;
	for (int i = 0; i < numOfQualities; i++) {
		cout << studentQualities[i] << " ";
	}
	cout << endl;
}

void Student::studentCharact(string filename) {

	fstream templateSample, studentFile;
	templateSample.open(filename, fstream::in);
	studentFile.open("student1.txt", fstream::out);

	if (!templateSample.is_open()) {
		cout << "Неможливо відкрити файл-шаблон.\n";
		return;
	}

	if (!studentFile.is_open()) {
		cout << "Неможливо відкрити файл-характеристики.\n";
		return;
	}

	char ch;
	string str = "";

	templateSample.unsetf(ios::skipws);
	studentFile.unsetf(ios::skipws);
	while (!templateSample.eof()) {
		templateSample >> ch;
		studentFile << ch;
	}
	studentFile.close();
	templateSample.close();


	studentFile.open("student1.txt", fstream::in);
	while (!studentFile.eof()) {
		studentFile >> ch;
		if (!studentFile.eof()) {
			if (ch == '1') {
				str += studentName;
			}
			else if (ch == '2') {
				str += studentAge;
			}
			else if (ch == '3') {
				switch (studentHobby) {
				case 1:
					str += "спорту";
					break;
				case 2:
					str += "читання книг";
					break;
				case 3:
					str += "фотографування";
					break;
				case 4:
					str += "графічного дизайну";
					break;
				case 5:
					str += "електроніки";
					break;
				}
			}
			else if (ch == '4') {
				for (int i = 0; i < numOfQualities; i++) {
					if (i == numOfQualities - 1) {
						str += studentQualities[i];
					}
					else {
						str += studentQualities[i];
						str += ", ";
					}
				}
			}
			else if (ch == '^') {
				str += getDate();
			}
			else {
				str += ch;
			}
		}
	}
	studentFile.close();

	studentFile.open("student1.txt", fstream::out);
	studentFile << setw(50) << str;
	studentFile.close();
}

//string getPathToStudentFile(Student obj) {
//	string studentName = obj.getName();
//	string pathToStudentFile;
//	int end, counter;
//	end = 0;
//	int i = 0;
//	while (end != 2) {
//		if (studentName[i] == ' ') {
//			counter = i;
//			end++;
//		}
//		i++;
//	}
//	for (int j = 0; j <= counter; j++) {
//		pathToStudentFile += studentName[j];
//	}
//	return pathToStudentFile;
//
//}

int main() {
	Student person;
	Characteristic characteristic;
	cout << "\t<---Автоматичне написання характеристик--->" << "\n\n";
	person.studentInput();
	characteristic.charactInput();
	person.studentOutput();
	characteristic.charactOutput();
	string filename = characteristic.charactChoice();
	/*string pathToStudentFile = getPathToStudentFile(person);
	cout << pathToStudentFile << endl;*/
	person.studentCharact(filename);
	return 0;
}

string getDate() {
	time_t t = time(0);
	tm* now = localtime(&t);
	string str;
	return str = to_string(now->tm_mday) + '.' + to_string(now->tm_mon + 1) + '.' + to_string(now->tm_year + 1900);
}

bool hasOnlyDigits(const string s) {
	return s.find_first_not_of("0123456789!@№;$%^:?&*()_-+=/|.,") == string::npos;
}

